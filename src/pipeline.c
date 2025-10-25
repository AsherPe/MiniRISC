#include <stdio.h>
#include "pipeline.h"

void pipeline_step(CPU *cpu)
{
    // Fetch (IF)
    printf("F Stage: Fetching instruction at PC=%d\n", cpu->pc);
    cpu->pipeline.Fetch.instruction = cpu->mem[cpu->pc];
    cpu->pipeline.Fetch.pc = cpu->pc;

    // Decode (ID)
    printf("D Stage: Decoding instruction\n");
    cpu->pipeline.Decode = cpu->pipeline.Decode;

     // Execute (EX)
    printf("EX Stage: Running ALU operation\n");
    cpu->pipeline.Execute = cpu->pipeline.Execute;

    // Memory Access (MEM)
    printf("MA Stage: Access memory if needed\n");
    cpu->pipeline.MemoryAccess = cpu->pipeline.MemoryAccess;

    // Write Back (WB)
    printf("WB Stage: Writing result to register %d\n",
           cpu->pipeline.WriteBack.writeReg);

    cpu->pc++; // advance to next instruction
}
