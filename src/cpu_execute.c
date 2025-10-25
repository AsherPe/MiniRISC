#include<stdio.h>
#include "cpu.h"
#include "instruction.h"


void execute_instruction(CPU *cpu , Instruction instr){
    switch (instr.op)  // "Decoder"
    /******** ALU Oprtation *********/
    {
    case OP_ADD: // R[rd] = R[rs] + R[rt];
        cpu->regs[instr.rd] = cpu->regs[instr.rs] + cpu->regs[instr.rt];
        printf("Executed: ADD R%d = R%d + R%d → %d\n",
                instr.rd, instr.rs, instr.rt, cpu->regs[instr.rd]);
        break;

    case OP_SUB: // R[rd] = R[rs] - R[rt];
        cpu->regs[instr.rd] = cpu->regs[instr.rs] - cpu->regs[instr.rt];
        printf("Executed: SUB R%d = R%d - R%d → %d\n",
                instr.rd, instr.rs, instr.rt, cpu->regs[instr.rd]);
        break;
    
    case OP_ADDI: // R[rd] = R[rs] + imm;
        cpu->regs[instr.rd] = cpu->regs[instr.rs] + instr.imm;
        printf("Executed: ADDI R%d = R%d + %d → %d\n",
                instr.rd, instr.rs, instr.imm, cpu->regs[instr.rd]);
        break;
    
        case OP_LW: // R[rd] = MEM[R[rs] + imm];
            cpu->regs[instr.rd] = cpu->mem[cpu->regs[instr.rs] + instr.imm];
            printf("Executed: LW R%d = MEM[R%d + %d] → %d\n",
                    instr.rd, instr.rs, instr.imm, cpu->regs[instr.rd]);
            break;

        case OP_SW: // MEM[R[rs] + imm] = R[rd];
        cpu->mem[cpu->regs[instr.rs] + instr.imm] = cpu ->regs[instr.rd];
        printf("Executed: SW MEM[R%d + %d] = R%d → %d\n",
                instr.rs, instr.imm, instr.rd, cpu->regs[instr.rd]);
        break;

    default:
        printf("Error: Unknown opcode %d\n", instr.op);
        break;
    }

}