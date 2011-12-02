CC=g++
CFLAGS=-Wall

TARGET=main.exe
SRC_DIR := src
OBJ_DIR := obj
SRC_EXT := .cpp
OBJ_EXT := .o

CPP_FILES := $(wildcard $(SRC_DIR)/*$(SRC_EXT))
OBJ_FILES := $(addprefix $(OBJ_DIR)/,$(notdir $(CPP_FILES:$(SRC_EXT)=$(OBJ_EXT))))

$(TARGET): $(OBJ_DIR) $(OBJ_FILES)
    $(CC) $(CFLAGS) -o $@ $(OBJ_FILES)

$(OBJ_DIR):
    mkdir $@

$(OBJ_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%$(SRC_EXT)
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ_FILES)
    rm -f $(TARGET)
