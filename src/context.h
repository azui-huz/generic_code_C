#ifndef CONTEXT_H
#define CONTEXT_H

#include "instruction.h"

typedef struct Context {
    Instruction* instructions;
} Context;

int load_context(const char* filename, Context* ctx);

void free_context(Context* ctx);

void execute_context(const char* path, char* next_context);

#endif
