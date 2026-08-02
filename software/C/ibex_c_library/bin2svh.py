#!/usr/bin/env python3
"""Convert a raw firmware binary into a SystemVerilog unpacked-array assignment
pattern for a declaration-time memory initializer.

yosys-slang does NOT support $readmemh, and the synth flow uses --ignore-initial
(which strips initial blocks), so the usual `initial $readmemh(...)` memory load
is silently dropped and the BRAM comes up all-zero. A *declaration* initializer
(logic [..] mem[..] = '{...};) is not an initial procedure, so slang keeps it.

Emits: '{ 0: 32'hXXXXXXXX, 1: 32'h..., ..., default: 32'h00000000 }
(little-endian 32-bit words; unlisted words default to 0).

Usage: bin2svh.py <firmware.bin> <firmware_mem_init.svh>
"""
import struct
import sys

with open(sys.argv[1], "rb") as f:
    data = f.read()
if len(data) % 4:
    data += b"\x00" * (4 - len(data) % 4)
words = [struct.unpack("<I", data[i:i + 4])[0] for i in range(0, len(data), 4)]
with open(sys.argv[2], "w") as f:
    f.write("'{ ")
    f.write(", ".join("%d: 32'h%08X" % (i, w) for i, w in enumerate(words)))
    f.write(", default: 32'h00000000 }")
