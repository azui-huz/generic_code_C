#ifndef INSTRUCTION_H
#define INSTRUCTION_H

typedef struct Instruction {
    char type[16];   
    char arg1[32];   
    char arg2[32];   
    char arg3[32];   
    struct Instruction* next; 
} Instruction;

void parse_instruction(const char* line, Instruction* instr);

#endif
