# Path to directories
ENV_DIR := ../gem5/
RISCV_DIR := /opt/riscv/bin

# Compiler and assembler
CC   := $(RISCV_DIR)/riscv64-unknown-linux-gnu-gcc
AS   := $(RISCV_DIR)/riscv64-unknown-linux-gnu-as
LD   := $(RISCV_DIR)/riscv64-unknown-linux-gnu-ld
DP   := $(RISCV_DIR)/riscv64-unknown-linux-gnu-objdump
HEX  := $(RISCV_DIR)/riscv64-unknown-linux-gnu-objcopy
CPP  := $(RISCV_DIR)/riscv64-unknown-linux-gnu-g++
CMP  := $(RISCV_DIR)/riscv64-unknown-linux-gnu-size
DBG  := $(RISCV_DIR)/riscv64-unknown-linux-gnu-gdb

# Program name
PROG := main

# Target files
CPP_SRC := $(PROG).cpp
C_SRC   := $(PROG).c
ASM_SRC := $(PROG).s

CPP_OUT := $(PROG)
C_OUT   := $(PROG)
ASM_OUT := $(PROG)
HEX_OUT := $(PROG).hex

DP_ASM  := $(PROG).asm
DP_EXEC := $(PROG)

# Compiler options
# ARCH_FLAGS := -march=rv64gcv -mabi=lp64 AA
ARCH_FLAGS := -march=rv32gcv -mabi=ilp32
STATIC_FLAG := -static

.PHONY: all g++ gcc asm dump_asm dump_hex calc_size gem5 profile clean

# AA
PROG2 := hw3_sol_v2_RV32.s
P0 := /workspace/testcase/public/testcase_00.txt /workspace/answer/public/answer_00.txt
P1 := /workspace/testcase/public/testcase_01.txt /workspace/answer/public/answer_01.txt
P2 := /workspace/testcase/public/testcase_02.txt /workspace/answer/public/answer_02.txt
P3 := /workspace/testcase/public/testcase_03.txt /workspace/answer/public/answer_03.txt
P4 := /workspace/testcase/public/testcase_04.txt /workspace/answer/public/answer_04.txt
P5 := /workspace/testcase/private/testcase_05.txt /workspace/answer/private/answer_05.txt
P6 := /workspace/testcase/private/testcase_06.txt /workspace/answer/private/answer_06.txt
P7 := /workspace/testcase/private/testcase_07.txt /workspace/answer/private/answer_07.txt
P8 := /workspace/testcase/private/testcase_08.txt /workspace/answer/private/answer_08.txt
P9 := /workspace/testcase/private/testcase_09.txt /workspace/answer/private/answer_09.txt
P10 := /workspace/testcase/private/testcase_10.txt /workspace/answer/private/answer_10.txt

# Convert CPP to Assembly Code
cpp2asm: $(CPP_SRC)
	$(CPP) $(ARCH_FLAGS) $(CPP_SRC) -S -o $(ASM_OUT).s $(STATIC_FLAG)
	@echo "C++ code converted to $(ASM_OUT).s"

# Compile C++ code with PROG2
g++2: $(CPP_SRC)
	$(CPP) $(ARCH_FLAGS) $(CPP_SRC) $(PROG2) -o $(CPP_OUT) $(STATIC_FLAG)
	@echo "C++ code compiled to $(CPP_OUT)"

# Emulate the program on gem5 for testcases P0 to P4
gem5_all:
	@echo "e.g. make gem5_all GEM5_ARGS=\"--isa_type 64 --l1i_size 1kB --l1i_assoc 2 --l1d_size 1kB --l1d_assoc 2 --l2_size 16kB --l2_assoc 4\""
	cd $(ENV_DIR); \
	rm -rf m5out; \
	for i in 0 1 2 3 4; do \
		case $$i in \
			0) param="$(P0)";; \
			1) param="$(P1)";; \
			2) param="$(P2)";; \
			3) param="$(P3)";; \
			4) param="$(P4)";; \
		esac; \
		# 'set --' splits the pair into positional parameters $$1 and $$2 \
		set -- $$param; \
		echo "Running gem5 with testcase: $$1 and answer: $$2"; \
		build/RISCV/gem5.opt --outdir="/workspace/m5out" configs/gem5_config/simple-riscv-mod-config.py /workspace/$(PROG) $$1 $$2 $(GEM5_ARGS); \
	done; \

# Emulate the program on gem5 for testcases P5 to P10
gem5_hidden:
	@echo "e.g. make gem5_hidden GEM5_ARGS=\"--isa_type 64 --l1i_size 1kB --l1i_assoc 2 --l1d_size 1kB --l1d_assoc 2 --l2_size 16kB --l2_assoc 4\""
	cd $(ENV_DIR); \
	rm -rf m5out; \
	for i in 5 6 7 8 9 10; do \
		case $$i in \
			5) param="$(P5)";; \
			6) param="$(P6)";; \
			7) param="$(P7)";; \
			8) param="$(P8)";; \
			9) param="$(P9)";; \
			10) param="$(P10)";; \
		esac; \
		# 'set --' splits the pair into positional parameters $$1 and $$2 \
		set -- $$param; \
		echo "Running gem5 with testcase: $$1 and answer: $$2"; \
		build/RISCV/gem5.opt --outdir="/workspace/m5out" configs/gem5_config/simple-riscv-mod-config.py /workspace/$(PROG) $$1 $$2 $(GEM5_ARGS); \
	done; \

# AA end

# Compile C++ code
g++: $(CPP_SRC)
	$(CPP) $(ARCH_FLAGS) $(CPP_SRC) -o $(CPP_OUT) $(STATIC_FLAG)
	@echo "C++ code compiled to $(CPP_OUT)"

# Compile C code
gcc: $(C_SRC)
	$(CC) $(ARCH_FLAGS) $(C_SRC) -o $(C_OUT) $(STATIC_FLAG)
	@echo "C code compiled to $(C_OUT)"

# Assemble assembly code
asm:
	sed -i -e '$$a\\' $(ASM_SRC)
	$(CPP) $(ARCH_FLAGS) $(ASM_SRC) -o $(ASM_OUT) $(STATIC_FLAG)
	@echo "Assembly code assembled to $(ASM_OUT)"

# Disassemble compiled C code
dump_asm:
	$(DP) -d $(C_OUT) > $(DP_ASM)
	@echo "Disassembled $(C_OUT) to $(DP_ASM)"

# Convert compiled C code to machine code
dump_hex:
	$(HEX) -O verilog $(DP_EXEC) $(HEX_OUT)
	@echo "Converted $(DP_EXEC) to machine code (hex) $(HEX_OUT)"

# Calculate the size of the machine code
calc_size: dump_hex
	du -sh ./$(DP_EXEC)
	@echo "Size of $(DP_EXEC) is calculated"

# Emulate the program on gem5 with additional arguments
gem5:
	@echo "e.g. make gem5 ARGS=\"p1 p2 p3\" GEM5_ARGS=\"--isa_type 64 --l1i_size 1kB --l1i_assoc 2 --l1d_size 1kB --l1d_assoc 2 --l2_size 16kB --l2_assoc 4\""
	cd $(ENV_DIR); \
	rm -rf m5out; \
	build/RISCV/gem5.opt --outdir="/workspace/m5out" configs/gem5_config/simple-riscv-mod-config.py /workspace/$(PROG) $(ARGS) $(GEM5_ARGS) 
	@echo "Emulated $(PROG) $(ARGS) on gem5 with arguments: $(GEM5_ARGS)"

# Profile the program
profile:
	python3 profiler.py
	python3 profiler_plot.py
	@echo "Profiled $(PROG) on gem5"

# Clean up generated files
clean:
	rm -f $(PROG) $(HEX_OUT) $(ASM_OUT).o $(DP_ASM)
	@echo "Cleaned up generated files"
