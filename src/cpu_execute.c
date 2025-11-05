#include <stdio.h>
#include "cpu_execute.h"

void execute_instruction(CPU *cpu, Instruction instr)
{
    switch (instr.op) {
        case OP_ADD:
            cpu->regs[instr.rd] = cpu->regs[instr.rs] + cpu->regs[instr.rt];
            printf("ADD R%d = R%d + R%d -> %d\n", instr.rd, instr.rs, instr.rt, cpu->regs[instr.rd]);
            break;
        case OP_SUB:
            cpu->regs[instr.rd] = cpu->regs[instr.rs] - cpu->regs[instr.rt];
            printf("SUB R%d = R%d - R%d -> %d\n", instr.rd, instr.rs, instr.rt, cpu->regs[instr.rd]);
            break;
        case OP_ADDI:
            cpu->regs[instr.rd] = cpu->regs[instr.rs] + instr.imm;
            printf("ADDI R%d = R%d + %d -> %d\n", instr.rd, instr.rs, instr.imm, cpu->regs[instr.rd]);
            break;
        case OP_LW:
            cpu->regs[instr.rd] = cpu->mem[cpu->regs[instr.rs] + instr.imm];
            printf("LW R%d = MEM[R%d + %d] -> %d\n", instr.rd, instr.rs, instr.imm, cpu->regs[instr.rd]);
            break;
        case OP_SW:
            cpu->mem[cpu->regs[instr.rs] + instr.imm] = cpu->regs[instr.rd];
            printf("SW MEM[R%d + %d] = R%d -> %d\n", instr.rs, instr.imm, instr.rd, cpu->regs[instr.rd]);
            break;
        default:
            printf("Unknown opcode %d\n", instr.op);
    }
}
