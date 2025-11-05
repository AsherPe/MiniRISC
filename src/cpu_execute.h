#ifndef CPU_EXECUTE_H
#define CPU_EXECUTE_H

#include "cpu.h"
#include "instruction.h"

void execute_instruction(CPU *cpu, Instruction instr);

#endif
