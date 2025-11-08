#ifndef INSTRUCTION_H
#define INSTRUCTION_H

typedef enum { 
   OP_ADD,  //0
   OP_SUB,  //1
   OP_ADDI, //2
   OP_LW,   //3
   OP_SW,   //4
   OP_LUI,  //5
   OP_BEQ,  //6
   OP_J,    //7
   OP_JR,    //8
   OP_NOP =  -1 // No Operation
} Opcode;

typedef struct {
    Opcode op;    
    int rd;     // destination
    int rs;     // source 
    int rt;     // target
    int imm;    // Immediate 
} Instruction;





#endif