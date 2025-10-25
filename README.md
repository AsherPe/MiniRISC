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
- **cpu.c / cpu.h** – main CPU structure, registers, memory, and control logic  
- **instruction.h** – instruction format and opcode definitions  
- **cpu_execute.c** – executes decoded instructions (the ALU stage)  
- **pipeline.c / pipeline.h** – simple 5-stage pipeline simulation  
- **main.c** – example program that runs on the CPU  

## 🚀 How to Run
```bash
gcc src/*.c -o build/minirisc
./build/minirisc
