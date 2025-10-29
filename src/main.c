#include "machine.h"
#include <stdio.h>

int main() {
    Machine machine;
    initialize_machine(&machine, "main");
    run_machine(&machine);
    return 0;
}
