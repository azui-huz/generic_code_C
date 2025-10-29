#include "instruction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parse_instruction(const char* line, Instruction* instr) {
    instr->type[0] = instr->arg1[0] = instr->arg2[0] = instr->arg3[0] = '\0';

    if (strncmp(line, "PRINT", 5) == 0) {
        strcpy(instr->type, "PRINT");
        strcpy(instr->arg1, line + 6);
    }
    else if (strchr(line, '=')) {
        strcpy(instr->type, "ASSIGN");
        char left[32], right1[32], op[4], right2[32];
        if (sscanf(line, "%31s = %31s %3s %31s", left, right1, op, right2) == 4) {
            strcpy(instr->arg1, left);
            strcpy(instr->arg2, right1);
            strcpy(instr->arg3, op);
            strcpy(instr->type, right2);
        } else if (sscanf(line, "%31s = %31s", left, right1) == 2) {
            strcpy(instr->arg1, left);
            strcpy(instr->arg2, right1);
        }
    }
    else if (strncmp(line, "#NEXT_CONTEXT", 13) == 0) {
        strcpy(instr->type, "NEXT");
        strcpy(instr->arg1, line + 14);
    }
}
