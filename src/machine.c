#include "machine.h"
#include <string.h>
#include <stdio.h>

void initialize_machine(Machine* m, const char* initial_context) {
    m->state = STATE_RUNNING;
    strcpy(m->current_context, initial_context);
    m->next_context[0] = '\0';
    m->should_exit = 0;
}

void run_machine(Machine* m) {
    while (!m->should_exit) {

        if (m->state == STATE_RUNNING) {
            printf("\n=== Loading context '%s' ===\n", m->current_context);

            char path[128];
            snprintf(path, sizeof(path), "context/%s.txt", m->current_context);

            char next[64] = "";
            execute_context(path, next);

            if (strlen(next) > 0) {
                printf("→ Transition to context '%s'\n", next);
                strcpy(m->next_context, next);
                m->state = STATE_TRANSITION;
            } else {
                printf("No next context defined. Switching to IDLE state.\n");
                m->state = STATE_IDLE;
            }
        }

        else if (m->state == STATE_TRANSITION) {
            strcpy(m->current_context, m->next_context);
            m->next_context[0] = '\0';
            m->state = STATE_RUNNING;
        }

        else if (m->state == STATE_IDLE) {
            printf("\nMachine is IDLE.\n");
            printf("Enter a context name to launch (e.g., main, menu, game)\n");
            printf("Or type 'quit' to exit.\n> ");

            char input[64];
            if (fgets(input, sizeof(input), stdin)) {
                input[strcspn(input, "\r\n")] = 0;

                if (strcmp(input, "quit") == 0) {
                    printf("Exiting machine.\n");
                    m->should_exit = 1;
                }
                else if (strlen(input) > 0) {
                    printf("Restarting context '%s'\n", input);
                    strcpy(m->current_context, input);
                    m->state = STATE_RUNNING;
                }
            }
        }
    }
}
