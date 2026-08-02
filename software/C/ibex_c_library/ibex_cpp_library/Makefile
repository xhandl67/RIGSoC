COMPILER_CPP = riscv64-unknown-elf-g++
COMPILER_C = riscv64-unknown-elf-gcc
OBJCOPYTOOL = riscv64-unknown-elf-objcopy
FLAGS = -march=rv32ic_zicsr_zifencei -mabi=ilp32 -nostdlib -Wall -Wextra
LINKER = link_cpp.ld
all: firmware.bin
	python3 bin2svh.py firmware.bin ../../../rtl/firmware_mem_init.svh
firmware.bin:firmware.elf 
	$(OBJCOPYTOOL) -O binary firmware.elf firmware.bin


firmware.elf: main.o uart.o startup.o
	$(COMPILER_CPP) $(FLAGS) -Wl,-Map=firmware.map -T $(LINKER) main.o uart.o startup.o -o firmware.elf

main.o: main.cpp
	$(COMPILER_CPP) $(FLAGS) -c main.cpp -o main.o 

uart.o: uart.cpp
	$(COMPILER_CPP) $(FLAGS) -c uart.cpp -o uart.o 

startup.o: startup.S
	$(COMPILER_C) $(FLAGS) -c startup.S -o startup.o 

clean:
	rm -f *.o *.bin *.elf *.hex *.map