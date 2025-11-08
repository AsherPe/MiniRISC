#include <stdio.h>
#include <unistd.h>
#include "cpu.h"
#include "pipeline.h"
#include "cpu_execute.h" 


void pipeline_step(CPU *cpu, Instruction program[], int program_length)
{
    // Fetch stage
    if(cpu->pc < program_length) {
        cpu->pipeline.Fetch.instr = program[cpu->pc];
        cpu->pipeline.Fetch.pc = cpu->pc;
        cpu->pc++; // Increment PC for next fetch
    } else {
        cpu->pipeline.Fetch.instr.op = -1; // NOP
    }

    // Move stages forward
    cpu->pipeline.WriteBack = cpu->pipeline.MemoryAccess;
    cpu->pipeline.MemoryAccess = cpu->pipeline.Execute;
    cpu->pipeline.Execute = cpu->pipeline.Decode;
    cpu->pipeline.Decode = cpu->pipeline.Fetch;

    // Execute stage – handle branches and jumps
    Instruction exe_instr = cpu->pipeline.Execute.instr;
    switch (exe_instr.op) {
        case OP_BEQ:
            if(cpu->regs[exe_instr.rs] == cpu->regs[exe_instr.rt]) {
                cpu->pc = cpu->pipeline.Execute.pc + exe_instr.imm + 1;
                printf("[Execute] BEQ taken: R%d == R%d, new PC = %d\n", exe_instr.rs, exe_instr.rt, cpu->pc);
            }
            break;
        case OP_J:
            cpu->pc = exe_instr.imm;
            printf("[Execute] JUMP to %d\n", cpu->pc);
            break;
        case OP_JR:
            cpu->pc = cpu->regs[exe_instr.rs];
            printf("[Execute] JUMP Register R%d -> PC = %d\n", exe_instr.rs, cpu->pc);
            break;
        default:
            break;
    }

    // WriteBack stage
    if(cpu->pipeline.WriteBack.instr.op != -1 &&
       cpu->pipeline.WriteBack.instr.op != OP_BEQ &&
       cpu->pipeline.WriteBack.instr.op != OP_J &&
       cpu->pipeline.WriteBack.instr.op != OP_JR)
    {
        execute_instruction(cpu, cpu->pipeline.WriteBack.instr);
    }
}

void print_instruction(Instruction instr) {
    if (instr.op == -1) {
        printf("NOP");
        return;
    }

    switch (instr.op) {
        case OP_ADD:
            printf("ADD R%d,R%d,R%d", instr.rd, instr.rs, instr.rt);
            break;
        case OP_SUB:
            printf("SUB R%d,R%d,R%d", instr.rd, instr.rs, instr.rt);
            break;
        case OP_ADDI:
            printf("ADDI R%d,R%d,%d", instr.rd, instr.rs, instr.imm);
            break;
        case OP_LW:
            printf("LW R%d,[R%d+%d]", instr.rd, instr.rs, instr.imm);
            break;
        case OP_SW:
            printf("SW [R%d+%d],R%d", instr.rs, instr.imm, instr.rd);
            break;
        case OP_LUI:
            printf("LUI R%d,%d", instr.rd, instr.imm);
            break;
        case OP_BEQ:
            printf("BEQ R%d,R%d,%d", instr.rs, instr.rt, instr.imm);
            break;
        case OP_J:
            printf("J %d", instr.imm);
            break;
        case OP_JR:
            printf("JR R%d", instr.rs);
            break;
        default:
            printf("UNKNOWN");
    }
}

void pipeline_run(struct CPU *cpu, Instruction program[], int program_length)
{
    printf("\n**************************************************************\n");
    printf("Running program WITH pipeline...\n");
    printf("**************************************************************\n\n");

    int total_cycles = program_length + 4; // 4 additional cycles for pipeline to flush

    for (int cycle = 0; cycle < total_cycles; cycle++) {
        printf("+------------------------------------------------------------+\n");
        printf("|                      Cycle %2d                              |\n", cycle + 1);
        printf("+------------------------------------------------------------+\n");

        // Print pipeline stages
        printf(" Fetch:        |"); print_instruction(cpu->pipeline.Fetch.instr); printf("\n");
        printf(" Decode:       |"); print_instruction(cpu->pipeline.Decode.instr); printf("\n");
        printf(" Execute:      |"); print_instruction(cpu->pipeline.Execute.instr); printf("\n");
        printf(" MemoryAccess: |"); print_instruction(cpu->pipeline.MemoryAccess.instr); printf("\n");
        printf(" WriteBack:    |"); print_instruction(cpu->pipeline.WriteBack.instr); printf("\n");

        printf("+------------------------------------------------------------+\n");

        pipeline_step(cpu, program, program_length);

        usleep(300000); //0.3 sleep for visualization
    }

    printf("\n**************************************************************\n");
    printf("Program finished!\n");
    printf("**************************************************************\n");

    cpu_print_state(cpu);
}

void run_without_pipeline(CPU *cpu, Instruction program[], int program_length) {
    printf("\n**************************************************************\n");
    printf("Running program WITHOUT pipeline...\n");
    printf("**************************************************************\n\n");

    for (int i = 0; i < program_length; i++) {
        printf("[Cycle %d] Executing instruction %d...\n", i + 1, i);
        execute_instruction(cpu, program[i]);
        cpu->pc++;
        usleep(300000); //0.3 sleep for visualization
    }

    printf("\nProgram finished!\n");
    printf("**************************************************************\n");
    cpu_print_state(cpu);
}

