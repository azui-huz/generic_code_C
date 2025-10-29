#include "execution.h"
#include "variable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void run_instructions(Instruction* instr_list, char* next_context) {
    Instruction* current = instr_list;

    while (current) {
        if (strcmp(current->type, "PRINT") == 0) {
            if (current->arg1[0] == '"') {
                printf("%s\n", current->arg1 + 1);
            } else {
                printf("%d\n", get_variable_value(current->arg1));
            }
        }
        else if (strcmp(current->type, "ASSIGN") == 0) {
            int a = get_variable_value(current->arg2);
            int b = 0;
            if (strlen(current->type) > 0)
                b = get_variable_value(current->type);

            int result = 0;
            if (strcmp(current->arg3, "+") == 0)
                result = a + b;
            else if (strcmp(current->arg3, "-") == 0)
                result = a - b;
            else if (strcmp(current->arg3, "*") == 0)
                result = a * b;
            else if (strcmp(current->arg3, "/") == 0 && b != 0)
                result = a / b;
            else if (strlen(current->arg3) == 0)
                result = a;

            set_variable_value(current->arg1, result);
        }
        else if (strcmp(current->type, "NEXT") == 0) {
            strcpy(next_context, current->arg1);
        }

        current = current->next;
    }
}
