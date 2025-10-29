#include "variable.h"
#include <string.h>
#include <stdlib.h>

typedef struct Var {
    char name[32];
    int value;
    struct Var* next;
} Var;

static Var* vars = NULL;

static Var* find_var(const char* name) {
    Var* v = vars;
    while (v) {
        if (strcmp(v->name, name) == 0)
            return v;
        v = v->next;
    }
    return NULL;
}

int get_variable_value(const char* name) {
    Var* v = find_var(name);
    if (v) return v->value;
    return atoi(name); // if it's a number
}

void set_variable_value(const char* name, int value) {
    Var* v = find_var(name);
    if (!v) {
        v = malloc(sizeof(Var));
        strcpy(v->name, name);
        v->next = vars;
        vars = v;
    }
    v->value = value;
}
