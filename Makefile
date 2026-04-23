CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Source and object dirs
SRC_DIR = src
OBJ_DIR = obj
BIN = tictactoe

# Auto find all .c files, map to obj/
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Main target
$(BIN): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

# Compile each .c into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj dir if not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN)