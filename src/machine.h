#ifndef MACHINE_H
#define MACHINE_H

#include "context.h"

typedef enum {
    STATE_RUNNING,    
    STATE_TRANSITION, 
    STATE_IDLE        
} MachineState;

typedef struct {
    MachineState state;           
    char current_context[64];     
    char next_context[64];        
    int should_exit;              
} Machine;

void initialize_machine(Machine* m, const char* initial_context);

void run_machine(Machine* m);

#endif
