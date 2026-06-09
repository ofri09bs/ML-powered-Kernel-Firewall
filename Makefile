TARGET_KERN = build/firewall_kern.bpf.o
TARGET_USER = build/firewall_usr
IFACE ?= enp0s3

all: $(TARGET_KERN) $(TARGET_USER)

$(TARGET_KERN): xdp_firewall/firewall_kern.bpf.c
	clang -O2 -g -target bpf -D__x86_64__ \
	-I/usr/include/bpf \
	-I/usr/include/x86_64-linux-gnu \
	-c xdp_firewall/firewall_kern.bpf.c \
	-o $(TARGET_KERN)

$(TARGET_USER): xdp_firewall/firewall_usr.c
	gcc -O2 -g \
	xdp_firewall/firewall_usr.c \
	-o $(TARGET_USER) -lbpf -lelf -lz

load: $(TARGET_KERN)
	sudo ip link set dev $(IFACE) xdp obj $(TARGET_KERN) sec xdp

unload:
	sudo ip link set dev $(IFACE) xdp off

clean:
	rm -f $(TARGET_KERN) $(TARGET_USER)