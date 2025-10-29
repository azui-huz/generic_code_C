#include "context.h"
#include "execution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_context(const char* filename, Context* ctx) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open context file '%s'\n", filename);
        return 0;
    }

    ctx->instructions = NULL;
    Instruction* last = NULL;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\r\n")] = 0;
        if (strlen(line) == 0) continue;

        Instruction* new_instr = malloc(sizeof(Instruction));
        parse_instruction(line, new_instr);
        new_instr->next = NULL;

        if (!ctx->instructions) ctx->instructions = new_instr;
        else last->next = new_instr;

        last = new_instr;
    }

    fclose(file);
    return 1;
}

void free_context(Context* ctx) {
    Instruction* current = ctx->instructions;
    while (current) {
        Instruction* temp = current;
        current = current->next;
        free(temp);
    }
    ctx->instructions = NULL;
}

void execute_context(const char* path, char* next_context) {
    Context ctx;
    if (!load_context(path, &ctx)) return;

    printf("Executing context...\n");
    run_instructions(ctx.instructions, next_context);

    free_context(&ctx);
}
