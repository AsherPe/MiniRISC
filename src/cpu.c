#include <stdio.h>
#include <unistd.h>
#include "cpu.h"
#include "instruction.h"
#include "memory.h"

void cpu_init(CPU *cpu) // Initialize CPU state
{
    for (int i = 0; i < NUM_CPU_REGS; i++)
        cpu->regs[i] = 0;

    cpu->pc = 0;

    // Initialize pipeline stages to "No Operation - NOP"
    cpu->pipeline.Fetch.instr.op = -1;
    cpu->pipeline.Decode.instr.op = -1;
    cpu->pipeline.Execute.instr.op = -1;
    cpu->pipeline.MemoryAccess.instr.op = -1;
    cpu->pipeline.WriteBack.instr.op = -1;
}

void cpu_print_state(const CPU *cpu) // Print CPU state 
{
    printf("CPU State:\n");
    printf("\nPC: %d\n", cpu->pc);
    printf("\nRegisters:\n");
    for (int i = 0; i < NUM_CPU_REGS; i++){
        printf("R%d: %d\n", i, cpu->regs[i]);
    }

    printf("\nMemory (first 16 bytes):\n");
    for (int i = 0; i < 16; i++){
        printf("M[%d]: %d\n", i, mem_read(i)); 
    }
    puts("**************************************************************\n");

}
