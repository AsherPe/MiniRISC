#include <stdio.h>
#include "cpu.h"
#include "instruction.h"

extern void cpu_init(CPU *cpu);
extern void cpu_run(CPU *cpu, Instruction program[], int program_length);
extern void cpu_print_state(const CPU *cpu);

int main()
{
    CPU cpu;
    cpu_init(&cpu);

    // נגדיר תוכנית קטנה
    Instruction program[] = {
        {OP_ADD, 3, 1, 2, 0},   // R3 = R1 + R2
        {OP_SUB, 4, 3, 1, 0},   // R4 = R3 - R1
        {OP_ADDI, 1, 0, 0, 5},  // R1 = R0 + 5
        {OP_ADDI, 2, 0, 0, 10}, // R2 = R0 + 10
    };

    int program_length = sizeof(program) / sizeof(program[0]);

    cpu_run(&cpu, program, program_length);
    cpu_print_state(&cpu);


    printf("\nProgram finished.\n");

    return 0;
}
