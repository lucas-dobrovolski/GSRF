
#     COMPILADORES
# ============================
CXX := g++
CC  := gcc

#     FLAGS
# ============================
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic \
            -I./source \
            -I./source/glad/include

CFLAGS   := -std=c11 -Wall -Wextra -Wno-pedantic \
            -I./source/glad/include

LDFLAGS  := -lglfw -ldl -lGL -lpthread \
            -lX11 -lXcursor -lXi -lXrandr

#     DIRECTORIOS
# ============================
SRC_DIR   := source
GLAD_DIR  := source/glad/src
BUILD_DIR := build

#     FUENTES
# ============================
CPP_FILES := $(shell find $(SRC_DIR) -name "*.cpp")
C_FILES   := $(GLAD_DIR)/glad.c

OBJ_CPP := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CPP_FILES))
OBJ_C   := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(C_FILES))

OBJ := $(OBJ_CPP) $(OBJ_C)

#     TARGET
# ============================
TARGET := GSRF

# ============================
#     REGLAS
# ============================
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
