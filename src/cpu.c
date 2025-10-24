#include<stdio.h>
#include "cpu.h"
#include "instruction.h"

/*
typedef struct
{
    int regs[NUM_CPU_REGS];
    int pc;
    int mem[MEM_SIZE];
} CPU;
*/ 


void cpu_init(CPU *cpu)
{
    for (int i = 0 ; i < NUM_CPU_REGS ; i++){ // Initialize all registers to 0
        cpu->regs[i] = 0;
    }

    for(int i = 0 ; i < MEM_SIZE ; i++){ // Initialize all memory to 0
        cpu->mem[i] = 0;
    }

    cpu->pc = 0; // Initialize program counter to 0
     
}

void cpu_print_state(const CPU *cpu)
{
    printf("==========================\n");
    printf("CPU State:\n");
    printf("PC: %d\n", cpu->pc);
    printf("Registers:\n");
    for (int i = 0; i < NUM_CPU_REGS; i++) {
        printf("R%d: %d\n", i, cpu->regs[i]);
    }
    printf("Memory (first 16 bytes):\n");
    for (int i = 0; i < 16; i++) {
        printf("M[%d]: %d\n", i, cpu->mem[i]);
    }
}

extern void execute_instruction(CPU *cpu, Instruction instr);

void cpu_run(CPU *cpu, Instruction program[], int program_length)
{
    printf("Starting program...\n");

    while (cpu->pc < program_length)
    {
        Instruction instr = program[cpu->pc];

        printf("\n[Cycle %d] Executing instruction at PC=%d\n", cpu->pc, cpu->pc);

        execute_instruction(cpu, instr); // הרץ פקודה אחת

        cpu->pc++; // עבור לפקודה הבאה
    }

    printf("\nProgram finished!\n");
}
