#include <linux/bpf.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#ifndef FIREWALL_H
#define FIREWALL_H

struct packet_event {
    __u32 src_ip;
    __u32 dst_ip;
};

// Define a connection key structure for tracking unique connections
struct connection_key {
    __u32 src_ip;
    __u32 dst_ip;
    __u16 src_port;
    __u16 dst_port;
    __u8 protocol;
};

// Define a connection record structure for tracking connection statistics
struct connection_record {
    __u64 packet_count;
    __u64 byte_count;
    __u64 first_seen;
    __u64 last_seen;
    __u64 min_packet_size;
    __u64 max_packet_size;
    __u64 syn_count;
    __u64 fin_count;
    __u64 ack_count;
    __u64 rst_count;
    __u64 avg_inter_arrival_time;
};


#endif // FIREWALL_H