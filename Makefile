TARGET = firewall_kern.bpf.o
IFACE ?= enp0s3

all:
	clang -O2 -g -target bpf \
	-I/usr/include/x86_64-linux-gnu \
	-c firewall_kern.bpf.c -o $(TARGET)

load: $(TARGET)
	sudo ip link set dev $(IFACE) xdp obj $(TARGET) sec xdp

unload:
	sudo ip link set dev $(IFACE) xdp off

clean:
	rm -f $(TARGET)