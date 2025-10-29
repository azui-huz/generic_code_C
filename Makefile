# ==========================================
#  Makefile - State Machine Project (C)
# ==========================================

TARGET = state_machine

SRC_DIR = src
OBJ_DIR = obj
CTX_DIR = context

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: build $(TARGET)

build:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(CTX_DIR)

$(TARGET): $(OBJ)
	@echo "Linking..."
	$(CC) $(OBJ) -o $@
	@echo "Build complete: ./$(TARGET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	rm -rf $(OBJ_DIR) $(TARGET)
	@echo "Clean complete."

run: all
	@echo "Running program:"
	./$(TARGET)

rebuild: clean all

.PHONY: all clean run rebuild build
