#ifndef PIPELINE_H
#define PIPELINE_H

#include "instruction.h"
#include "cpu.h"

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


struct CPU; // Forward declaration
void pipeline_step(struct CPU *cpu, Instruction program[], int program_length);
void pipeline_run(struct CPU *cpu, Instruction program[], int program_length);
void run_without_pipeline(struct CPU *cpu, Instruction program[], int program_length);
#endif
