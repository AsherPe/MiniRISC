#ifndef CPU_H
#define CPU_H

#include "instruction.h"
#include "pipeline.h" 

#define NUM_CPU_REGS 8
#define MEM_SIZE 1024

typedef struct CPU {
    int regs[NUM_CPU_REGS];
    int pc;
    int mem[MEM_SIZE];
    Pipeline pipeline;
} CPU;

void cpu_init(CPU *cpu);
void cpu_print_state(const CPU *cpu);

#endif
