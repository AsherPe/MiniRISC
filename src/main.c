#include <stdio.h>
#include <unistd.h>
#include "cpu.h"
#include "instruction.h"
#include "pipeline.h"
#include "cpu_execute.h"

void print_menu()
    {
        puts("**************************************************************\n");
        puts("Starting CPU simulation...");
        sleep(2);

        puts("+------------------------------------------------------------+");
        puts("|                                                            |");
        puts("|              MiniRISC Run Mode Selector                    |");
        puts("|                                                            |");
        puts("|   1) Run without pipeline                                  |");
        puts("|   2) Run with pipeline                                     |");
        puts("|                                                            |");
        puts("|                                                            |");
        puts("+------------------------------------------------------------+");

        printf("your choise: ");
    }


int main()
{
    setvbuf(stdout, NULL, _IONBF, 0); // Disable output buffering for immediate print
    Instruction program[] = {
  //{opcode, rd, rs, rt, immediate}
    {OP_ADDI, 1, 0, 0, 5},       // R1 = 5
    {OP_ADDI, 2, 0, 0, 10},      // R2 = 10
    {OP_ADD, 3, 1, 2, 0},        // R3 = R1 + R2
    {OP_SUB, 4, 3, 1, 0},        // R4 = R3 - R1
    {OP_SW, 4, 0, 0, 0},         // Store R4 into MEM[0]
    {OP_LW, 5, 0, 0, 0},         // Load MEM[0] into R5
    {OP_ADDI, 6, 5, 0, 20},      // R6 = R5 + 20
    {OP_ADD, 7, 6, 2, 0},        // R7 = R6 + R2
    {OP_SUB, 1, 7, 3, 0},        // R1 = R7 - R3
    {OP_LUI, 2, 0, 0, 1000},     // Load upper immediate: R2 = 1000 << 16
    {OP_SW, 1, 0, 0, 4},         // Store R1 into MEM[4]
    {OP_LW, 3, 0, 0, 4},         // Load MEM[4] into R3
    {OP_BEQ, 1, 3, 0, 2},        // Branch if R1 == R3, skip next 2 instructions
    {OP_ADDI, 4, 4, 0, 7},       // R4 = R4 + 7
    {OP_ADD, 5, 1, 2, 0},        // R5 = R1 + R2
    {OP_ADDI, 6, 6, 0, -5},      // R6 = R6 - 5
    {OP_SUB, 7, 7, 6, 0},        // R7 = R7 - R6
    {OP_J, 12, 0, 0, 0},         // Jump to instruction index 12 (BEQ)
    {OP_ADDI, 1, 1, 0, 100},     // R1 = R1 + 100 (skipped because of previous J)
    {OP_JR, 0, 7, 0, 0},         // Jump to address stored in R7
    {OP_ADDI, 2, 2, 0, 50},      // R2 = R2 + 50
    {OP_SW, 2, 0, 0, 8},         // Store R2 into MEM[8]
    {OP_LW, 4, 0, 0, 8},         // Load MEM[8] into R4
};
    int program_length = sizeof(program) / sizeof(program[0]);
    int flag = 0;
    int user_choice;
    
    CPU cpu;
    cpu_init(&cpu); // Initialize CPU

    print_menu();
    scanf("%d", &user_choice);
    
    switch (user_choice)
    {
    case 1:
        run_without_pipeline(&cpu, program, program_length);
        break;
    case 2:
        pipeline_run(&cpu, program, program_length);
        break;
    default:
        while(flag < 2){
            puts("Invalid option. Please select 1 or 2.");
            printf("your choise: ");
            scanf("%d", &user_choice);
            if(user_choice == 1){
                run_without_pipeline(&cpu, program, program_length);
                break;
            }
            else if(user_choice == 2){
                pipeline_run(&cpu, program, program_length);
                break;
            }
            flag++;
        }
        puts("Invalid option. Exiting.");
        return 1;
    }

    return 0;

    
}



   
