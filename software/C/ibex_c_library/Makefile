PREFIX ?= riscv64-unknown-elf-
COMPILER = $(PREFIX)gcc
FLAGS = -march=rv32ic_zicsr_zifencei -mabi=ilp32 -nostdlib -Wall -Wextra

all: firmware.bin

firmware.bin: firmware.elf
	$(PREFIX)objcopy -O binary firmware.elf firmware.bin
	$(PREFIX)objcopy -O ihex   firmware.elf firmware.hex

firmware.elf: main.o startup.o uart.o demo_system.o
	$(COMPILER) $(FLAGS) -Wl,-Map=firmware.map -T link.ld startup.o uart.o demo_system.o main.o -o firmware.elf

main.o: main.c 
	$(COMPILER) $(FLAGS) -c main.c -o main.o

startup.o: startup.S 
	$(COMPILER) $(FLAGS) -c startup.S -o startup.o


uart.o: uart.c 
	$(COMPILER) $(FLAGS) -c uart.c -o uart.o
	
demo_system.o: demo_system.c
	$(COMPILER) $(FLAGS) -c demo_system.c -o demo_system.o
clean:
	rm -f *.o firmware.elf *.fst *.log *.csv

objdump:
	$(PREFIX)objdump -d firmware.elf

# Firmware image for synthesis: bake the .bin into a SystemVerilog array
# initializer that the RAM picks up (yosys-slang cannot do $readmemh).
../DesignSources/firmware_mem_init.svh: firmware.bin bin2svh.py
	python3 bin2svh.py firmware.bin $@

svh: ../DesignSources/firmware_mem_init.svh
