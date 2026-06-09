import pandas as pd
import numpy as np
import os
import xgboost as xgb
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, accuracy_score, confusion_matrix, recall_score
import m2cgen as m2c

def load_and_prepare_data(csv_path):
    print(f"Loading {csv_path}...")
    df = pd.read_csv(csv_path)

    df.columns = df.columns.str.strip()

    df['packet_count'] = df['Total Fwd Packets'] + df['Total Backward Packets']
    df['byte_count'] = df['Total Length of Fwd Packets'] + df['Total Length of Bwd Packets']
    df['avg_inter_arrival_time_ns'] = df['Flow IAT Mean'] * 1000

    features = [
        'packet_count',
        'byte_count',
        'Min Packet Length',       # min_packet_size
        'Max Packet Length',       # max_packet_size
        'SYN Flag Count',          # syn_count
        'FIN Flag Count',          # fin_count
        'ACK Flag Count',          # ack_count
        'RST Flag Count',          # rst_count
        'avg_inter_arrival_time_ns'# avg_inter_arrival_time
    ]

    X = df[features]
    y = df['Label']

    X = X.replace([np.inf, -np.inf], np.nan)
    
    valid_indices = X.dropna().index
    X = X.loc[valid_indices]
    y = y.loc[valid_indices]

    print(f"Data ready: {len(X)} rows extracted.")
    return X, y


def process_dataset():
    directory_path = "CIC-IDS-2017"
    all_X = []
    all_y = []

    for filename in os.listdir(directory_path):
        if filename.endswith(".csv"):
            csv_path = os.path.join(directory_path, filename)
            X, y = load_and_prepare_data(csv_path)

            all_X.append(X)
            all_y.append(y)

    X = pd.concat(all_X, ignore_index=True)
    y = pd.concat(all_y, ignore_index=True)

    print(f"Final dataset: {len(X)} samples, {X.shape[1]} features.")
    print("Class distribution:")
    print(y.value_counts())
    print("Sample features:")
    print(X.sample(20))
    print("Sample labels:")
    print(y.sample(20))

    # Data cleaning
    y = y.replace({'DoS Hulk': 'DDoS', 'DoS GoldenEye': 'DDoS', 'DoS slowloris': 'DDoS', 'DoS Slowhttptest': 'DDoS'})
    y = y.replace({'Web Attack � Brute Force': 'Web Attack', 'Web Attack � XSS': 'Web Attack', 'Web Attack � Sql Injection': 'Web Attack','Infiltration': 'Web Attack','Heartbleed': 'Web Attack'})
    y = y.replace({'FTP-Patator': 'Brute Force', 'SSH-Patator': 'Brute Force'})
    print("Class distribution after cleaning:")
    print(y.value_counts())

    # the class distribution is still imbalanced, so we will use binary classification for benign vs Non-benign
    y = y.apply(lambda x: 1 if x == 'BENIGN' else 0)
    print("Binary class distribution:")
    print(y.value_counts()) 

    # To balance the dataset, we will undersample the majority class (benign) to match the number of samples in the minority class (non-benign)
    benign_count = y.value_counts()[1]
    non_benign_count = y.value_counts()[0]
    y.drop(y[y == 1].sample(n=benign_count - non_benign_count).index, inplace=True)
    X = X.loc[y.index]
    print("Binary class distribution after undersampling:")
    print(y.value_counts())
    return X, y


def build_and_train_model(X, y):
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    model = xgb.XGBClassifier(
        n_estimators=10,
        max_depth=5,
        learning_rate=0.1,
        use_label_encoder=False,
        eval_metric='logloss',
        base_score=0.5
    )

    print("Training model...")
    model.fit(X_train, y_train)

    print("Evaluating model...")
    y_pred = model.predict(X_test)
    print(classification_report(y_test, y_pred))
    print(f"Accuracy: {accuracy_score(y_test, y_pred):.4f}")
    print(f"Recall: {recall_score(y_test, y_pred):.4f}")
    print("Confusion Matrix:")
    print(confusion_matrix(y_test, y_pred))

    return model


import re

def convert_m2cgen_to_ebpf(input_file, output_file, scale_factor=1000000):
    with open(input_file, "r") as f:
        code = f.read()

    # Remove floating-point types and signatures
    code = re.sub(r"void score\s*\(double\s*\*?\s*input,\s*double\s*\*?\s*output\)", 
                  "long long calc_model_score(long long *input)", code)
    code = code.replace("double var0;", "long long var0 = 0;")
    
    # Strip the trailing '.0' from all integer thresholds inside IF statements
    code = re.sub(r"(\d+)\.0(?!\d)", r"\1", code)

    # Scale and convert remaining float leaf values to integers
    def scale_leaf(match):
        val = float(match.group(1))
        return f"{int(val * scale_factor)}"

    code = re.sub(r"=\s*([-+]?\d+\.\d+);", lambda m: f"= {int(float(m.group(1)) * scale_factor)};", code)

    # Modify the end of the score function to return the raw accumulated score
    code = re.sub(r"output\[0\]\s*=\s*var0\s*;", "return var0;", code)
    
    # Clean up any remaining double definitions or unused memory functions
    code = re.sub(r"double\s+[^;]+;", "", code) 

    with open(output_file, "w") as f:
        f.write(code)
        
    print(f"Conversion complete: {output_file} is ready for eBPF usage.")


if __name__ == "__main__":
    print("Processing dataset...")
    X, y = process_dataset()
    print("Building and training model...")
    model = build_and_train_model(X, y)
    print("Generating C code from model...")
    c_code = m2c.export_to_c(model)
    with open("firewall_xgb_model.h", "w") as f:
        f.write(c_code)
    print("C code saved to firewall_xgb_model.h")
    print("Converting C code to eBPF-compatible format...")
    convert_m2cgen_to_ebpf("firewall_xgb_model.h", "firewall_xgb_model.h")    



