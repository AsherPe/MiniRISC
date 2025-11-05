#ifndef PIPELINE_H
#define PIPELINE_H

#include "instruction.h"

typedef struct {
    Instruction instr;
    int pc;
    int aluResult;
    int memData;
    int writeReg;
} PipelineStage;

typedef struct {
    PipelineStage Fetch;
    PipelineStage Decode;
    PipelineStage Execute;
    PipelineStage MemoryAccess;
    PipelineStage WriteBack;
} Pipeline;

// Forward declaration 
struct CPU;

void pipeline_step(struct CPU *cpu, Instruction program[], int program_length);
void pipeline_run(struct CPU *cpu, Instruction program[], int program_length);

#endif
