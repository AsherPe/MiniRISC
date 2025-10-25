#ifndef PIPELINE_H
#define PIPELINE_H

#include "instruction.h"
#include "cpu.h"


typedef struct {
    Instruction instr;   // The instruction currently in this pipeline stage
    int pc;              // The program counter (address) of this instruction
    int aluResult;       // The result produced by the ALU in the EX stage
    int memData;         // Data loaded from memory (if applicable)
    int writeReg;        // The destination register to write to during WB
} PipelineStage;

typedef struct {
    PipelineStage Fetch;
    PipelineStage Execute;
    PipelineStage MemoryAccess;
    PipelineStage WriteBack;
} Pipeline;

#endif
