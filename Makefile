TARGET_KERN = firewall_kern.bpf.o
TARGET_USER = firewall_usr
IFACE ?= enp0s3

all: $(TARGET_KERN) $(TARGET_USER)

# Compile the Kernel eBPF program
$(TARGET_KERN): firewall_kern.bpf.c
	clang -O2 -g -target bpf \
	-I/usr/include/x86_64-linux-gnu \
	-c firewall_kern.bpf.c -o $(TARGET_KERN)

# Compile the User Space program
$(TARGET_USER): firewall_usr.c
	clang -O2 -g \
	firewall_usr.c -o $(TARGET_USER) -lbpf -lelf -lz

load: $(TARGET_KERN)
	sudo ip link set dev $(IFACE) xdp obj $(TARGET_KERN) sec xdp

unload:
	sudo ip link set dev $(IFACE) xdp off

clean:
	rm -f $(TARGET_KERN) $(TARGET_USER)