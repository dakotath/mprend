# Compiler and flags
CC = gcc
CFLAGS = -I./include -I./exinclude -Wall -Wextra -O2 -fsanitize=address,undefined -DPLATFORM_WIN
LDFLAGS = -L./lib -L./exlib -lmprend -lSDL2 -lSDL2_ttf

# Source and object files
SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Output binary
TARGET = myprogram

# Default target
all: $(TARGET)

# Link the target
$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(TARGET)
	rm -rf $(OBJ_DIR)

# Phony targets
.PHONY: all clean