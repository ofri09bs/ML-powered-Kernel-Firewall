#include <stdio.h>
#include <signal.h>
#include <arpa/inet.h>
#include <bpf/libbpf.h>
#include <net/if.h>
#include <unistd.h>
#include <linux/in.h>
#include <linux/ip.h>
#include <linux/if_link.h>
#include "firewall.h"
#include "../ML_model/firewall_xgb_model.h"

const char *bpf_object_file = "build/firewall_kern.bpf.o";
const char *bpf_program_name = "xdp_monitor";
const char *if_name = "enp0s3";
#define THRESHOLD -90000LL

long long get_model_score(struct connection_record *record) {
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

char* get_protocol_name(__u8 protocol) {

    switch (protocol) {
        case IPPROTO_TCP:      return "TCP";
        case IPPROTO_UDP:      return "UDP";
        case IPPROTO_ICMP:     return "ICMP";
        default:
            return "UNKNOWN";
    }
}

int main()
{
    struct ring_buffer *buffer = NULL;
    struct packet_event evt;
    struct bpf_object *obj;
    struct bpf_program *prog;
    struct bpf_map *map;
    int prog_fd, map_fd;

    // ########### BPF Program loading and linking ###########

    // Load the BPF program to the kernel
    obj = bpf_object__open_file(bpf_object_file, NULL);
    if (libbpf_get_error(obj)) {
        fprintf(stderr, "Failed to open BPF object\n");
        return 1;
    }
    if (bpf_object__load(obj)) {
        fprintf(stderr, "Failed to load BPF object\n");
        return 1;
    }

    // Find the BPF program by name and attach it to the XDP hook
    prog = bpf_object__find_program_by_name(obj, bpf_program_name);
    if (!prog) {
        fprintf(stderr, "failed to find program\n");
        return 1;
    }
    
    // link the program to the network interface
    struct bpf_link *link;
    int ifindex = if_nametoindex(if_name);
    
    // attach the program to the XDP hook
    link = bpf_program__attach_xdp(prog, ifindex);
    if (!link) {
        fprintf(stderr, "attach failed\n");
        return 1;
    }

    
    while (1) {
        struct connection_record record;
        struct connection_key next_key;
        struct connection_key current_key;
        struct connection_key *prev_key_ptr = NULL; 

        // Read connection records from the BPF map
        map = bpf_object__find_map_by_name(obj, "connection_table");
        if (!map) {
            fprintf(stderr, "Failed to find map\n");
            return 1;
        }

        // Iterate through all elements in the map
        while (bpf_map__get_next_key(map, prev_key_ptr, &next_key, sizeof(next_key)) == 0) {
            
            if (bpf_map__lookup_elem(map, &next_key, sizeof(next_key), &record, sizeof(record), 0) == 0) {
                char src_ip[INET_ADDRSTRLEN];
                char dst_ip[INET_ADDRSTRLEN];
                
                inet_ntop(AF_INET, &next_key.src_ip, src_ip, sizeof(src_ip));
                inet_ntop(AF_INET, &next_key.dst_ip, dst_ip, sizeof(dst_ip));
                
                long long model_score = get_model_score(&record);
                char *action = (model_score > THRESHOLD) ? "DROPPED" : "PASSED";
                // Print raw data separated by commas
                printf("DATA,%s,%s,%d,%d,%s,%lld,%s\n\n", src_ip, dst_ip, ntohs(next_key.src_port), ntohs(next_key.dst_port), get_protocol_name(next_key.protocol), model_score, action);
                fflush(stdout); // Force output immediately
            }

            current_key = next_key;
            prev_key_ptr = &current_key;
        }
        sleep(1);
        printf("CLEAR\n");
        fflush(stdout);
    }

    bpf_object__close(obj);
    return 0;

}