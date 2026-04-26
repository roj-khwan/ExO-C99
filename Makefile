CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
DEBUG_FLAGS = -g -O0

# Source and object dirs
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests
TEST_OBJ_DIR = $(OBJ_DIR)/tests
DEBUG_OBJ_DIR = $(OBJ_DIR)/debug
BIN = tictactoe
TEST_BIN = test_runner

# Auto find all .c files (exclude main), map to obj/
SRC = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
DEBUG_OBJ = $(patsubst $(SRC_DIR)/%.c, $(DEBUG_OBJ_DIR)/%.o, $(SRC))


# Test sources
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(TEST_OBJ_DIR)/%.o, $(TEST_SRC))

# Main target
all: $(BIN)

$(BIN): $(OBJ_DIR) $(OBJ) $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(OBJ_DIR)/main.o

# Compile each .c into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
# Compile each .c into obj/
$(DEBUG_OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DEBUG_OBJ_DIR)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

# Create obj dir if not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
# Test targets
test: $(TEST_BIN)
	./$(TEST_BIN)    

$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)

$(DEBUG_OBJ_DIR):
	mkdir -p $(DEBUG_OBJ_DIR)

# Compile test files
$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

# Link test executable (exclude main.o)
$(TEST_BIN): $(DEBUG_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(TEST_BIN) $(DEBUG_OBJ) $(TEST_OBJ)

# Debug
debug: $(DEBUG_OBJ_DIR) $(DEBUG_OBJ) $(DEBUG_OBJ_DIR)/main.o
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(BIN)_debug $(DEBUG_OBJ) $(DEBUG_OBJ_DIR)/main.o
	gdb $(BIN)_debug

.PHONY: all test clean

clean:
	rm -rf $(OBJ_DIR) $(BIN) $(TEST_BIN)
