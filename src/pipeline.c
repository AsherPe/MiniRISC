#include <stdio.h>
#include "cpu.h"
#include "pipeline.h"
#include "cpu_execute.h" 

void pipeline_step(struct CPU *cpu, Instruction program[], int program_length)
{
    if(cpu->pc < program_length) {
        cpu->pipeline.Fetch.instr = program[cpu->pc];
        cpu->pipeline.Fetch.pc = cpu->pc;
    }

    
    cpu->pipeline.Decode = cpu->pipeline.Fetch;
    cpu->pipeline.Execute = cpu->pipeline.Decode;
    cpu->pipeline.MemoryAccess = cpu->pipeline.Execute;
    cpu->pipeline.WriteBack = cpu->pipeline.MemoryAccess;

    if(cpu->pipeline.WriteBack.instr.op != -1)
        execute_instruction(cpu, cpu->pipeline.WriteBack.instr);

    cpu->pc++;
}

void pipeline_run(struct CPU *cpu, Instruction program[], int program_length)
{
    printf("Starting program with pipeline...\n");

    while(cpu->pc < program_length + 4) { // +4 כדי לרוקן pipeline
        printf("\n[Cycle %d]\n", cpu->pc);
        pipeline_step(cpu, program, program_length);
    }

    printf("\nProgram finished!\n");
}
