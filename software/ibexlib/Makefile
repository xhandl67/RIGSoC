COMPILER_CPP = riscv64-unknown-elf-g++
COMPILER_C = riscv64-unknown-elf-gcc
OBJCOPYTOOL = riscv64-unknown-elf-objcopy
FLAGS = -march=rv32imc_zicsr_zifencei -mabi=ilp32 -nostdlib -Wall -Wextra
#FLAGS = -march=rv32ifdc_zicsr_zifencei -mabi=ilp32d -nostdlib -Wall -Wextra
LINKER = link_cpp.ld
all: firmware.bin
	python3 bin2svh.py firmware.bin ../../rtl/firmware_mem_init.svh

firmware.bin:firmware.elf 
	$(OBJCOPYTOOL) -O binary firmware.elf firmware.bin	

firmware.elf: main.o uart.o startup.o
	$(COMPILER_C) $(FLAGS) -T $(LINKER) main.o uart.o startup.o -o firmware.elf

main.o: main.c
	$(COMPILER_C) $(FLAGS) -c main.c -o main.o 

uart.o: uart.c
	$(COMPILER_C) $(FLAGS) -c uart.c -o uart.o 

startup.o: startup.S
	$(COMPILER_C) $(FLAGS) -c startup.S -o startup.o 

timer.o: timer.c
	$(COMPILER_C) $(FLAGS) -c timer.c -o timer.o
clean:
	rm -f *.o *.elf *.map *.hex *.bin

test:
	$(COMPILER_CPP) $(FLAGS) -c test.cpp -o test.o 
	$(COMPILER_C) $(FLAGS) -c startup.S -o startup.o 
	$(COMPILER_CPP) $(FLAGS) -c uart.cpp -o uart.o 
	$(COMPILER_CPP) $(FLAGS) -c timer.cpp -o timer.o 
	$(COMPILER_CPP) $(FLAGS) -T $(LINKER) startup.o test.o uart.o timer.o -o firmware.elf
	$(OBJCOPYTOOL) -O binary firmware.elf firmware.bin	
	python3 bin2svh.py firmware.bin ../../../rtl/firmware_mem_init.svh
