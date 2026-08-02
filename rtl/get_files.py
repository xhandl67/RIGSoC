#!/usr/bin/env python3

import os
import shutil

SOURCE_ROOT = "/home/xaver/forks/ibex-demo-system/build/lowrisc_ibex_demo_system_0/src"
OUTPUT_DIR = "/home/xaver/FPGA_Projects/RiscGate/DesignSources"
FILELIST = "/home/xaver/FPGA_Projects/RiscGate/sv_headers.txt"

os.makedirs(OUTPUT_DIR, exist_ok=True)

with open(FILELIST, "r") as f:
    wanted_files = {line.strip() for line in f if line.strip()}

found = set()

for root, dirs, files in os.walk(SOURCE_ROOT):
    for file in files:
        if file in wanted_files:
            src = os.path.join(root, file)
            dst = os.path.join(OUTPUT_DIR, file)

            shutil.copy2(src, dst)
            found.add(file)

            print(f"Kopiert: {src}")

missing = wanted_files - found

print("\n--- Zusammenfassung ---")
print(f"Gefunden: {len(found)}")
print(f"Nicht gefunden: {len(missing)}")

if missing:
    print("\nFehlende Dateien:")
    for f in sorted(missing):
        print(f)