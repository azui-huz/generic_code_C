/**
 * @file main.c
 * @brief Entry point for the state machine program.
 */

#include "machine.h"
#include <stdio.h>

/**
 * @brief Program entry point.
 * Initializes the machine and starts the execution loop.
 */
int main() {
    Machine machine;
    initialize_machine(&machine, "main");
    run_machine(&machine);
    return 0;
}
