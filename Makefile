# Compiler and flags
CC = g++
CFLAGS = -Wall -g

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source and object files
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))
TARGET = $(BUILD_DIR)/my_program

# OS detection
ifeq ($(OS),Windows_NT)
    MKDIR = if not exist $(subst /,\,$(BUILD_DIR)) mkdir $(subst /,\,$(BUILD_DIR))
    RMDIR = if exist $(subst /,\,$(BUILD_DIR)) rmdir /S /Q $(subst /,\,$(BUILD_DIR))
    RM = del /F /Q
else
    MKDIR = mkdir -p $(BUILD_DIR)
    RMDIR = rm -rf $(BUILD_DIR)
    RM = rm -f
endif

# Rule to build the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Rule to compile .cpp files from src/ into .o files in build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up build files
clean:
	@echo "Cleaning up..."
	$(RMDIR)

.PHONY: clean
