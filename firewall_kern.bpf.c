#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/in.h>
#include <linux/tcp.h>
#include "firewall.h"

#define THRESHOLD 1000000 // Placeholder threshold for model score

struct {
    __uint(type, BPF_MAP_TYPE_RINGBUF);
    __uint(max_entries, 1 << 24); // 16MB
} packet_data SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_LRU_HASH); // Use LRU hash to automatically evict old entries
    __type(key, struct connection_key);
    __type(value, struct connection_record);
    __uint(max_entries, 65536); 
} connection_table SEC(".maps");

int calc_model_score(struct connection_record *record) {
    // placeholder for a more complex model, for now we just use a simple heuristic
    return 0;
}

SEC("xdp")
int xdp_monitor(struct xdp_md *ctx) {
    
    void *data_end = (void *)(long)ctx->data_end;
    void *data = (void *)(long)ctx->data;

    struct ethhdr *eth = data;
    // Ensure we can read the Ethernet header
    if ((void*)(eth + 1) > data_end) {
        bpf_printk("Packet too short for Ethernet header\n");
        return XDP_DROP;
    }

    struct iphdr *ip = (void *)(eth + 1);
    // Ensure we can read the IP header
    if ((void*)(ip + 1) > data_end) {
        bpf_printk("Packet too short for IP header\n");
        return XDP_DROP;
    }

    int pkt_protocol = ip->protocol;
    if (pkt_protocol != IPPROTO_TCP) {
        bpf_printk("Non-TCP packet, protocol: %d\n", pkt_protocol);
        return XDP_PASS; // Only monitor TCP packets, pass others
    }

    struct tcphdr *tcp = (void *)(ip + 1);
    // Ensure we can read the TCP header
    if ((void*)(tcp + 1) > data_end) {
        bpf_printk("Packet too short for TCP header\n");
        return XDP_DROP;
    }

    struct connection_key conn_key;
    conn_key.src_ip = ip->saddr;
    conn_key.dst_ip = ip->daddr;
    conn_key.src_port = tcp->source;
    conn_key.dst_port = tcp->dest;
    conn_key.protocol = pkt_protocol;

    struct connection_record *record = bpf_map_lookup_elem(&connection_table, &conn_key);
    if (!record) {
        struct connection_record new_record = {};
        new_record.packet_count = 1;
        new_record.byte_count = data_end - data;
        new_record.first_seen = bpf_ktime_get_ns();
        new_record.last_seen = new_record.first_seen;
        new_record.min_packet_size = (long)(data_end - data);
        new_record.max_packet_size = (long)(data_end - data);
        new_record.avg_inter_arrival_time = 0;
        
        if (tcp->syn) new_record.syn_count = 1;
        if (tcp->fin) new_record.fin_count = 1;
        if (tcp->ack) new_record.ack_count = 1;
        if (tcp->rst) new_record.rst_count = 1;

        bpf_map_update_elem(&connection_table, &conn_key, &new_record, BPF_ANY);
    }
    else {
        __u64 now = bpf_ktime_get_ns();
        __u64 inter_arrival_time = now - record->last_seen;
        record->last_seen = now;
        record->packet_count++;
        record->byte_count += data_end - data;
        record->avg_inter_arrival_time = (record->avg_inter_arrival_time * (record->packet_count - 1) + inter_arrival_time) / record->packet_count;

        if (data_end - data < record->min_packet_size) {
            record->min_packet_size = data_end - data;
        }
        if (data_end - data > record->max_packet_size) {
            record->max_packet_size = data_end - data;
        }

        if (tcp->syn) record->syn_count++;
        if (tcp->fin) record->fin_count++;
        if (tcp->ack) record->ack_count++;
        if (tcp->rst) record->rst_count++;
    }

    __u64 model_score = calc_model_score(record);
    if (model_score > THRESHOLD) {
        bpf_printk("Dropping connection: src=%pI4:%d dst=%pI4:%d score=%llu\n", &ip->saddr, tcp->source, &ip->daddr, tcp->dest, model_score);
        return XDP_DROP;
    }
    return XDP_PASS;
}

char _license[] SEC("license") = "GPL";