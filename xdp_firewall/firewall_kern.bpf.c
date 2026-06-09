#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/in.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#include <linux/icmp.h>
#include "firewall.h"
#include "../ML_model/firewall_xgb_model.h"

#define THRESHOLD -90000LL

struct {
    __uint(type, BPF_MAP_TYPE_RINGBUF);
    __uint(max_entries, 1 << 24); // 16MB
} packet_data SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_LRU_HASH); 
    __type(key, struct connection_key);
    __type(value, struct connection_record);
    __uint(max_entries, 65536); 
} connection_table SEC(".maps");

// Extract features and calculate the ML model score
static __always_inline long long get_model_score(struct connection_record *record) {
    long long features[9];
    features[0] = record->packet_count;
    features[1] = record->byte_count;
    features[2] = record->min_packet_size;
    features[3] = record->max_packet_size;
    features[4] = record->syn_count;
    features[5] = record->fin_count;
    features[6] = record->ack_count;
    features[7] = record->rst_count;
    features[8] = record->avg_inter_arrival_time;

    return calc_model_score(features);
}

// TCP Handler
static __always_inline int handle_tcp(struct xdp_md *ctx, struct iphdr *ip, void *data, void *data_end) {
    struct tcphdr *tcp = (void *)(ip + 1);
    
    // Ensure we can read the TCP header
    if ((void *)(tcp + 1) > data_end) {
        return XDP_DROP;
    }

    // Calculate dynamic headers size and payload
    __u32 ip_hl = ip->ihl * 4;
    __u32 tcp_hl = tcp->doff * 4;
    __u32 headers_size = sizeof(struct ethhdr) + ip_hl + tcp_hl;
    __s64 payload_size = (data_end - data) - headers_size;
    if (payload_size < 0) {
        payload_size = 0;
    }

    struct connection_key conn_key = {};
    conn_key.src_ip = ip->saddr;
    conn_key.dst_ip = ip->daddr;
    conn_key.src_port = tcp->source;
    conn_key.dst_port = tcp->dest;
    conn_key.protocol = IPPROTO_TCP;

    struct connection_record *record = bpf_map_lookup_elem(&connection_table, &conn_key);
    if (!record) {
        struct connection_record new_record = {};
        new_record.packet_count = 1;
        new_record.byte_count = payload_size;
        new_record.first_seen = bpf_ktime_get_ns();
        new_record.last_seen = new_record.first_seen;
        new_record.min_packet_size = payload_size;
        new_record.max_packet_size = payload_size;
        new_record.avg_inter_arrival_time = 0;
        
        if (tcp->syn) new_record.syn_count = 1;
        if (tcp->fin) new_record.fin_count = 1;
        if (tcp->ack) new_record.ack_count = 1;
        if (tcp->rst) new_record.rst_count = 1;

        bpf_map_update_elem(&connection_table, &conn_key, &new_record, BPF_ANY);
        return XDP_PASS;
    }

    // Convert nanoseconds to microseconds to match the ML training data
    __u64 now = bpf_ktime_get_ns();
    __u64 inter_arrival_time = (now - record->last_seen) / 1000;
    record->last_seen = now;
    record->packet_count++;
    record->byte_count += payload_size;
    record->avg_inter_arrival_time = (record->avg_inter_arrival_time * (record->packet_count - 1) + inter_arrival_time) / record->packet_count;

    if (payload_size < record->min_packet_size) {
        record->min_packet_size = payload_size;
    }
    if (payload_size > record->max_packet_size) {
        record->max_packet_size = payload_size;
    }

    if (tcp->syn) record->syn_count++;
    if (tcp->fin) record->fin_count++;
    if (tcp->ack) record->ack_count++;
    if (tcp->rst) record->rst_count++;

    // Allow the connection to establish before classifying
    if (record->packet_count < 20) {
        return XDP_PASS;
    }

    long long model_score = get_model_score(record);
    if (model_score > THRESHOLD) {
        return XDP_DROP;
    }
    
    return XDP_PASS;
}

// UDP Handler
static __always_inline int handle_udp(struct xdp_md *ctx, struct iphdr *ip, void *data, void *data_end) {
    struct udphdr *udp = (void *)(ip + 1);
    
    // Ensure we can read the UDP header
    if ((void *)(udp + 1) > data_end) {
        return XDP_DROP;
    }

    // UDP header is exactly 8 bytes
    __u32 ip_hl = ip->ihl * 4;
    __u32 headers_size = sizeof(struct ethhdr) + ip_hl + sizeof(struct udphdr);
    __s64 payload_size = (data_end - data) - headers_size;
    if (payload_size < 0) {
        payload_size = 0;
    }

    struct connection_key conn_key = {};
    conn_key.src_ip = ip->saddr;
    conn_key.dst_ip = ip->daddr;
    conn_key.src_port = udp->source;
    conn_key.dst_port = udp->dest;
    conn_key.protocol = IPPROTO_UDP;

    struct connection_record *record = bpf_map_lookup_elem(&connection_table, &conn_key);
    if (!record) {
        struct connection_record new_record = {};
        new_record.packet_count = 1;
        new_record.byte_count = payload_size;
        new_record.first_seen = bpf_ktime_get_ns();
        new_record.last_seen = new_record.first_seen;
        new_record.min_packet_size = payload_size;
        new_record.max_packet_size = payload_size;
        new_record.avg_inter_arrival_time = 0;
        
        bpf_map_update_elem(&connection_table, &conn_key, &new_record, BPF_ANY);
        return XDP_PASS;
    }

    __u64 now = bpf_ktime_get_ns();
    __u64 inter_arrival_time = (now - record->last_seen) / 1000;
    record->last_seen = now;
    record->packet_count++;
    record->byte_count += payload_size;
    record->avg_inter_arrival_time = (record->avg_inter_arrival_time * (record->packet_count - 1) + inter_arrival_time) / record->packet_count;

    if (payload_size < record->min_packet_size) {
        record->min_packet_size = payload_size;
    }
    if (payload_size > record->max_packet_size) {
        record->max_packet_size = payload_size;
    }

    if (record->packet_count < 20) {
        return XDP_PASS;
    }

    long long model_score = get_model_score(record);
    if (model_score > THRESHOLD) {
        return XDP_DROP;
    }
    
    return XDP_PASS;
}

// ICMP Handler
static __always_inline int handle_icmp(struct xdp_md *ctx, struct iphdr *ip, void *data, void *data_end) {
    struct icmphdr *icmp = (void *)(ip + 1);
    
    // Ensure we can read the ICMP header
    if ((void *)(icmp + 1) > data_end) {
        return XDP_DROP;
    }

    // ICMP header size is fixed to 8 bytes for basic parsing
    __u32 ip_hl = ip->ihl * 4;
    __u32 headers_size = sizeof(struct ethhdr) + ip_hl + sizeof(struct icmphdr);
    __s64 payload_size = (data_end - data) - headers_size;
    if (payload_size < 0) {
        payload_size = 0;
    }

    struct connection_key conn_key = {};
    conn_key.src_ip = ip->saddr;
    conn_key.dst_ip = ip->daddr;
    // Set ports to 0 since ICMP does not utilize ports like TCP/UDP
    conn_key.src_port = 0;
    conn_key.dst_port = 0;
    conn_key.protocol = IPPROTO_ICMP;

    struct connection_record *record = bpf_map_lookup_elem(&connection_table, &conn_key);
    if (!record) {
        struct connection_record new_record = {};
        new_record.packet_count = 1;
        new_record.byte_count = payload_size;
        new_record.first_seen = bpf_ktime_get_ns();
        new_record.last_seen = new_record.first_seen;
        new_record.min_packet_size = payload_size;
        new_record.max_packet_size = payload_size;
        new_record.avg_inter_arrival_time = 0;
        
        bpf_map_update_elem(&connection_table, &conn_key, &new_record, BPF_ANY);
        return XDP_PASS;
    }

    __u64 now = bpf_ktime_get_ns();
    __u64 inter_arrival_time = (now - record->last_seen) / 1000;
    record->last_seen = now;
    record->packet_count++;
    record->byte_count += payload_size;
    record->avg_inter_arrival_time = (record->avg_inter_arrival_time * (record->packet_count - 1) + inter_arrival_time) / record->packet_count;

    if (payload_size < record->min_packet_size) {
        record->min_packet_size = payload_size;
    }
    if (payload_size > record->max_packet_size) {
        record->max_packet_size = payload_size;
    }

    if (record->packet_count < 20) {
        return XDP_PASS;
    }

    long long model_score = get_model_score(record);
    if (model_score > THRESHOLD) {
        return XDP_DROP;
    }
    
    return XDP_PASS;
}

// Main XDP Entry Point
SEC("xdp")
int xdp_monitor(struct xdp_md *ctx) {
    
    void *data_end = (void *)(long)ctx->data_end;
    void *data = (void *)(long)ctx->data;

    struct ethhdr *eth = data;
    
    // Ensure we can read the Ethernet header
    if ((void *)(eth + 1) > data_end) {
        return XDP_DROP;
    }

    // Only process IPv4 traffic
    if (eth->h_proto != __constant_htons(ETH_P_IP)) {
        return XDP_PASS;
    }

    struct iphdr *ip = (void *)(eth + 1);
    
    if ((void *)(ip + 1) > data_end) {
        return XDP_DROP;
    }

    // Route traffic by protocol
    if (ip->protocol == IPPROTO_TCP) {
        return handle_tcp(ctx, ip, data, data_end);
    }
    else if (ip->protocol == IPPROTO_UDP) {
        return handle_udp(ctx, ip, data, data_end);
    }
    else if (ip->protocol == IPPROTO_ICMP) {
        return handle_icmp(ctx, ip, data, data_end);
    }

    // Pass any other protocols transparently (could be extended to handle more protocols in the future)
    return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
