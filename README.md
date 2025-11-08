# MiniRISC 🧠⚙️

MiniRISC is a simple educational CPU simulator built as a student project to better understand how real processors work under the hood.  
It follows the RISC (Reduced Instruction Set Computer) design philosophy and includes a basic 5-stage pipeline similar to classic MIPS architecture.

## 🔍 Project Overview
The goal of this project is to implement a minimal yet functional CPU core that supports:
- Basic arithmetic and logic operations (ADD, SUB, ADDI)
- Simple memory access (LW, SW)
- Branch and jump instructions (BEQ, J, JR)
- A 5-stage instruction pipeline (Fetch  → Decode → Execute  → Memory Access → Write Back)

## 🧩 Components
- **cpu.c / cpu.h** – Main CPU structure, including registers, memory, program counter (PC), and control logic.
- **instruction.h** – Defines the instruction format and opcode constants.
- **cpu_execute.c** – Executes decoded instructions (the ALU stage).
- **pipeline.c / pipeline.h** – Implements a simple 5-stage pipeline simulation: Fetch, Decode, Execute, Memory Access, Write Back.
- **memory.c / memory.h** – Handles memory operations such as load and store, and manages access to the CPU’s memory space.
- **main.c** – The main entry point; builds the system and runs an example program on the CPU.

## 🚀 How to Run
```bash
gcc src/*.c -o build/minirisc
./build/minirisc

