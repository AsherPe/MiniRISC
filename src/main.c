#include <stdio.h>
#include <unistd.h>
#include "cpu.h"
#include "instruction.h"
#include "pipeline.h"

 void print_menu()
    {
        puts("+------------------------------------------------------------+");
        puts("|                                                            |");
        puts("|              MiniRISC Run Mode Selector                    |");
        puts("|                                                            |");
        puts("|   1) Run without pipeline                                  |");
        puts("|   2) Run with pipeline                                     |");
        puts("|   3) Manual run (step-by-step with instructions)           |");
        puts("|                                                            |");
        puts("+------------------------------------------------------------+");
    }

int main()
{
    CPU cpu;
    cpu_init(&cpu);

    printf("Starting CPU simulation...\n");
    sleep(2); 
    print_menu();
    printf("your choise: ");

    int flag;
    scanf("%d", &flag);

    Instruction program[] = {
        {OP_ADDI, 1, 0, 0, 5},  // R1 = 5
        {OP_ADDI, 2, 0, 0, 10}, // R2 = 10
        {OP_ADD, 3, 1, 2, 0},   // R3 = R1 + R2
        {OP_SUB, 4, 3, 1, 0},   // R4 = R3 - R1
        {OP_SW, 4, 0, 0, 0},    // MEM[0] = R4
        {OP_LW, 5, 0, 0, 0},    // R5 = MEM[0]
    };   
    
    int program_length = sizeof(program) / sizeof(program[0]);


    switch (flag)
    {
    case 1:
        printf("Running without pipeline...\n");
        break;
    case 2:
        printf("Running with pipeline...\n");
        pipeline_run(&cpu, program, program_length);
        break;
    case 3:
        printf("Manual run selected...\n");
        break;
    default:
        printf("Invalid option. Exiting.\n");
        return 1;
    }

    
    cpu_print_state(&cpu);

    return 0;

    
}



   
