import subprocess
from rich.live import Live
from rich.table import Table
from rich import box

def generate_table(connections):
    # Create a beautiful terminal table
    table = Table(
        title="[bold blue]eBPF XDP Traffic Classifier - Live View[/bold blue]",
        box=box.DOUBLE_EDGE,
        header_style="bold cyan",
        expand=True
    )
    
    table.add_column("Source IP", justify="center")
    table.add_column("Dest IP", justify="center")
    table.add_column("Source Port", justify="right", style="green")
    table.add_column("Dest Port", justify="right")
    table.add_column("Protocol", justify="center")
    table.add_column("Score (Log-Odds)", justify="right")
    table.add_column("Status", justify="center")

    for conn in connections:
        # Color coding the status
        status_color = "red" if conn['status'] == "DROPPED" else "green"
        status_text = f"[bold {status_color}]{conn['status']}[/bold {status_color}]"
        
        table.add_row(
            conn['src'], 
            conn['dst'], 
            conn['src_port'], 
            conn['dst_port'], 
            conn['protocol'], 
            conn['score'], 
            status_text
        )
        
    return table

def run_dashboard():
    process = subprocess.Popen(
        ['./firewall_usr'], 
        stdout=subprocess.PIPE, 
        text=True
    )

    current_connections = []
    
    with Live(generate_table(current_connections), auto_refresh=False, screen=True) as live:
        for line in process.stdout:
            line = line.strip()
            
            if line == "CLEAR":
                live.update(generate_table(current_connections), refresh=True)
                current_connections = []
                
            elif line.startswith("DATA"):
                parts = line.split(',')
                if len(parts) >= 8:
                    conn_data = {
                        'src': parts[1],
                        'dst': parts[2],
                        'src_port': parts[3],
                        'dst_port': parts[4],
                        'protocol': parts[5],
                        'score': parts[6],
                        'status': parts[7]
                    }
                    current_connections.append(conn_data)

if __name__ == "__main__":
    try:
        run_dashboard()
    except KeyboardInterrupt:
        print("\nDashboard closed.")