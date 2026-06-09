#  XDP-ML Firewall: AI-Powered eBPF Traffic Classifier

An advanced, low-latency Intrusion Prevention System (IPS) built with **eBPF/XDP** and **Machine Learning**. This project deploys an **XGBoost** model directly into the **Linux Kernel** to classify and mitigate malicious network traffic (such as **DDoS**, **Port Scans**, and **Floods**) in real-time, before it even reaches the networking stack.

## Key Features

* **In-Kernel Machine Learning:** Executes a trained **XGBoost** classifier (converted to native C code using m2cgen) directly at the network interface level using **XDP**.
* **Multi-Protocol Support:** Parses and tracks **TCP**, **UDP**, and **ICMP** traffic flows.
* **Real World Dataset:** The XGBoost model was trained on over a million data samples from **CIC-IDS2017 Dataset** and got 93% accuracy on test set
* **Live Terminal Dashboard:** A dynamic, real-time UI built with Python's `rich` library, providing immediate visibility into traffic status and model scoring.

## Architecture

The project is split into two main components:
1. **Kernel Space (`xdp_firewall/firewall_kern.bpf.c`):** The XDP program intercepts incoming packets, parses Ethernet, IP, TCP/UDP/ICMP headers, updates the connection state in an eBPF map, and evaluates the ML model to return either `XDP_PASS` or `XDP_DROP`.
2. **User Space (`dashboard.py` & `firewall_usr.c`):** Reads the shared eBPF maps, extracts the connection data, and visualizes the traffic flow and the ML model's Log-Odds score.

## Prerequisites

To compile and run this project, ensure your environment has the following dependencies:

* Linux Kernel 5.4+ (Ubuntu 20.04/22.04 or similar)
* `clang` and `llvm` (for BPF target compilation)
* `libbpf-dev` and `libelf-dev`
* Python 3.x
* Python `rich` library (`pip install rich`)

### 1. Compilation
Compile the eBPF kernel object and the user-space loader. 

```bash
make clean
make
```

### 2. Running the Live Dashboard
Start the real-time monitoring interface. This requires `sudo` privileges to interact with the eBPF maps via the compiled user-space C program.

```bash
sudo python3 dashboard.py
```

## Project Structure
```
├── xdp_firewall/
│   ├── firewall_kern.bpf.c      # The core XDP program and BPF map definitions
│   ├── firewall_usr.c           # User-space C program reading maps and outputting CSV
│   └── firewall.h               # Shared structures (Kernel ↔ User space)
│
├── ML_model/
│   ├── firewall_xgb_model.h     # XGBoost model translated into C function
│   └── xgb_model.py             # Training and building the XGBoost model
│
├── dashboard.py                 # Python frontend using rich for live terminal visualization
├── Makefile                     # Automates BPF + user-space build process
```
