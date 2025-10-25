#ifndef CPU_H
#define CPU_H
#include "pipeline.h"


#define NUM_CPU_REGS 8
#define MEM_SIZE 1024

typedef struct
{
    int regs[NUM_CPU_REGS];
    int pc;
    int mem[MEM_SIZE];
    Pipeline pipeline;
} CPU;

void cpu_init(CPU *cpu); // Initialize CPU state
void cpu_print_state(const CPU *cpu); // Print CPU state for debugging


#endif // CPU_H


