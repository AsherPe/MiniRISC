#include <stdio.h>
#include "cpu_execute.h"
#include "cpu.h"
#include "memory.h"

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
            cpu->regs[instr.rd] = mem_read(cpu->regs[instr.rs] + instr.imm);
            printf("LW R%d = MEM[%d] -> %d\n", instr.rd, cpu->regs[instr.rs]+instr.imm, cpu->regs[instr.rd]);
            break;

        case OP_SW:
            mem_write(cpu->regs[instr.rs]+instr.imm, cpu->regs[instr.rd]);
            printf("SW MEM[%d] = R%d -> %d\n", cpu->regs[instr.rs]+instr.imm, instr.rd, cpu->regs[instr.rd]);
            break;

        case OP_LUI:
            cpu->regs[instr.rd] = instr.imm << 16; // Load Upper Immediate
            printf("LUI R%d = %d << 16 -> %d\n", instr.rd, instr.imm, cpu->regs[instr.rd]);
            break;

        case OP_BEQ:
            if(cpu->regs[instr.rs] == cpu->regs[instr.rt]) {
                cpu->pc += instr.imm; // jump relative
                printf("BEQ taken: R%d == R%d, PC += %d -> %d\n", instr.rs, instr.rt, instr.imm, cpu->pc);
            } else {
                printf("BEQ not taken: R%d != R%d\n", instr.rs, instr.rt);
            }
            break;

        case OP_J:
            cpu->pc = instr.imm; // jump to absolute address
            printf("JUMP to %d\n", cpu->pc);
            break;

        case OP_JR:
            cpu->pc = cpu->regs[instr.rs]; // jump to address in register
            printf("JUMP Register R%d -> PC = %d\n", instr.rs, cpu->pc);
            break;

        default:
            printf("Unknown opcode %d\n", instr.op);
    }
}
