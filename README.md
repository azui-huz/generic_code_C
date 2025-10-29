# C State Machine Project

A modular **state machine engine** written in **C**, capable of dynamically executing context files (`.txt`) containing high-level pseudo-instructions. Contexts can define transitions to other contexts or leave the machine in an **IDLE** state, waiting for user input.

---

## Project Structure

```
project/
├── Makefile
├── context/
│   ├── main.txt
│   ├── menu.txt
│   ├── game.txt
└── src/
    ├── main.c
    ├── machine.c / .h
    ├── context.c / .h
    ├── instruction.c / .h
    ├── execution.c / .h
    ├── variable.c / .h
```

---

## Features

- **Dynamic context loading** — Each `.txt` file defines a sequence of instructions.
- **Arithmetic and print operations** — Example: `A = B + C`, `PRINT A`, `PRINT "Hello"`.
- **Context transitions** — Controlled by `#NEXT_CONTEXT`.
- **IDLE mode** — The machine waits for user input when no next context is defined.
- **Interactive** — Enter a context name manually from the console.
- **Modular design** — Easy to extend with new instruction types or states.

---

## Build and Run

```bash
make run
```

This will:
1. Compile all `.c` files in `src/`
2. Create object files in `obj/`
3. Build the executable `state_machine`
4. Run it immediately

To clean and rebuild:

```bash
make rebuild
```

To only clean:

```bash
make clean
```

---

## Context Files

Each context file contains a set of human-readable instructions stored in the `context/` folder.

### Example — `context/main.txt`

```
PRINT "=== Main Program ==="
A = 5
B = 10
PRINT "Sum:"
C = A + B
PRINT C
#NEXT_CONTEXT menu
```

### Example — `context/menu.txt`

```
PRINT "=== MENU ==="
PRINT "Type 'game' to start the game."
#NEXT_CONTEXT game
```

### Example — `context/game.txt`

```
PRINT "=== GAME CONTEXT ==="
X = 3
Y = 4
Z = X * Y
PRINT "Result of X * Y:"
PRINT Z
PRINT "Game finished."
#NEXT_CONTEXT
```

---

## Machine States

| State | Description |
|--------|--------------|
| `STATE_RUNNING` | Executes the current context’s instructions. |
| `STATE_TRANSITION` | Loads and switches to the next context. |
| `STATE_IDLE` | Waits for user input or exit command. |

---

## Instructions Supported

| Syntax | Description | Example |
|---------|-------------|----------|
| `VAR = VALUE` | Assign a constant to a variable | `A = 5` |
| `VAR = VAR + VAR` | Perform addition | `C = A + B` |
| `VAR = VAR * VAR` | Perform multiplication | `Z = X * Y` |
| `PRINT "TEXT"` | Print a string | `PRINT "Hello"` |
| `PRINT VAR` | Print a variable’s value | `PRINT A` |
| `#NEXT_CONTEXT name` | Switch to another context after execution | `#NEXT_CONTEXT menu` |
| `#NEXT_CONTEXT` | No next context → enter IDLE mode | `#NEXT_CONTEXT` |

---

## Interactive IDLE Mode

When the machine reaches IDLE state:

```
Machine is IDLE.
Enter a context name to launch (e.g., main, menu, game)
Or type 'quit' to exit.
> main
```

Typing a context name restarts execution from that context.

---

## Architecture Overview

1. **machine.c**
   - Manages the current and next states of the machine.
   - Handles transitions and idle input.

2. **context.c**
   - Loads a `.txt` file, parses it into a linked list of instructions.
   - Frees memory when done.

3. **instruction.c**
   - Parses each line into an `Instruction` structure.

4. **execution.c**
   - Interprets and executes instructions.
   - Handles variable assignment and arithmetic.

5. **variable.c**
   - Maintains a simple in-memory map of variables.

---

## Adding New Instructions

To add a new instruction:
1. Modify `instruction.c` to recognize a new keyword.
2. Add corresponding logic in `execution.c`.

Example:
```
IF A > 10
PRINT "A is large"
ENDIF
```
- Extend parser to recognize `IF`/`ENDIF`.
- Add logic in `run_instructions()`.

---

## Adding New Contexts

1. Create a new `.txt` file in `context/`.
2. Add instructions inside.
3. Use `#NEXT_CONTEXT your_context_name` to transition to it.

---

## Generating Documentation

If you have **Doxygen** installed:

```bash
doxygen -g Doxyfile
```
Edit `Doxyfile`:
```
PROJECT_NAME = "C State Machine"
OUTPUT_DIRECTORY = docs
INPUT = src
RECURSIVE = YES
GENERATE_LATEX = NO
```
Generate docs:
```bash
doxygen Doxyfile
```
HTML docs appear in `docs/html/index.html`.

---

## Example Output

```
=== Loading context 'main' ===
Executing context...
=== Main Program ===
Sum:
15
→ Transition to context 'menu'

=== Loading context 'menu' ===
Executing context...
=== MENU ===
Type 'game' to start the game.
→ Transition to context 'game'

=== Loading context 'game' ===
Executing context...
=== GAME CONTEXT ===
Result of X * Y:
12
Game finished.
No next context defined. Switching to IDLE state.

Machine is IDLE.
Enter a context name to launch (e.g., main, menu, game)
Or type 'quit' to exit.
> main
Restarting context 'main'
```

---

## License

This project is open-source and free to modify for educational and research purposes.

