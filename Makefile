TOP = top_gatemate
#you can deactivate the seed, it is not necessary
PREFIX := rtl/
DESIGN_SOURCES := $(addprefix $(PREFIX),$(shell cat build/compile_files.txt))
IMPLEMENT_FLAGS = -l Logs/routing.log --verbose --device=CCGM1A1 --seed 2 --vopt allow-unconstrained --json Synth/$(TOP)_synth_final.json
GATE_MATE_PIN_CONSTRAINTS = constraints/pin_constraints.ccf
GATE_MATE_TIMING_CONSTRAINTS = constraints/timing_constraints.sdc
#here you need to replace the path to your oss-cad-suite toolchain!
PRIMITVE_LIB_FILES = /home/kasachstan_horse67/toolchains/oss-cad-suite/share/yosys/gatemate/*.v

soc:
#synthesize with yosys. You need to use the slang plugin because of modern sv syntax:
#we synthesize all primitve verilog files as library with read_verilog, because read_slang cant parse them
	yosys -m slang -p "read_slang --std latest --ignore-initial $(DESIGN_SOURCES) --top $(TOP) -D SYNTHESIS; read_verilog -lib $(PRIMITVE_LIB_FILES); synth_gatemate -top $(TOP) -luttree -nomx8; write_json Synth/$(TOP)_synth_final.json" > Logs/synth.log

#implement (place and route) with nextpnr:

	nextpnr-himbaechel $(IMPLEMENT_FLAGS) -o ccf=$(GATE_MATE_PIN_CONSTRAINTS) \
	-o out=Impl/impl.txt --sdc $(GATE_MATE_TIMING_CONSTRAINTS) --router router2

#create bitfile with gmpack 

	gmpack Impl/impl.txt Impl/impl.bit


clean:
	rm -f *.log *.png Synth/*.v Synth/*.json Impl/*.bit Impl/impl.txt Logs/*.log 