#include <stdio.h>
#include <signal.h>
#include <arpa/inet.h>
#include <bpf/libbpf.h>
#include <net/if.h>
#include <unistd.h>
#include <linux/if_link.h>
#include "firewall.h"

const char *bpf_object_file = "firewall_kern.bpf.o";
const char *bpf_program_name = "xdp_monitor";
const char *if_name = "enp0s3";


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
                
                printf("Connection: %s:%u -> %s:%u\n", src_ip, ntohs(next_key.src_port), dst_ip, ntohs(next_key.dst_port));
                printf("  Packets: %llu, Bytes: %llu, First Seen: %llu, Last Seen: %llu, Min Size: %llu, Max Size: %llu, SYN: %llu, FIN: %llu, ACK: %llu, RST: %llu, Avg IAT: %llu\n",
                    record.packet_count, record.byte_count, record.first_seen, record.last_seen, 
                    record.min_packet_size, record.max_packet_size, record.syn_count, 
                    record.fin_count, record.ack_count, record.rst_count, record.avg_inter_arrival_time);
            }

            current_key = next_key;
            prev_key_ptr = &current_key;
        }
        sleep(15);
    }

    bpf_object__close(obj);
    return 0;

}