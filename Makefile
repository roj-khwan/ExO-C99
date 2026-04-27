CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
DEBUG_FLAGS = -g -O0
AR = ar

# Directories
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests
LIB_DIR = lib
BIN_DIR = bin

# Targets
LIBRARY = $(LIB_DIR)/libexo.a
MAIN_BIN = $(BIN_DIR)/exo
TEST_BIN = $(BIN_DIR)/test_runner

# Source files
CORE_SRC = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
CORE_OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(CORE_SRC))

TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_SRC))

# Main targets
all: $(MAIN_BIN)

$(MAIN_BIN): $(BIN_DIR) $(LIBRARY) $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -o $@ $(SRC_DIR)/main.c -L$(LIB_DIR) -lexo

# Library creation
$(LIBRARY): $(LIB_DIR) $(CORE_OBJ)
	$(AR) -rcs $@ $(CORE_OBJ)

# Object files for library
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Test object files
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

# Directories
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Test targets
test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(BIN_DIR) $(LIBRARY) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $@ $(TEST_OBJ) -L$(LIB_DIR) -lexo

.PHONY: all test clean

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)
