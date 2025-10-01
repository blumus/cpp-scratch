# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -g -O0

# Project layout
SRC_DIR := src
BIN_DIR := build
TARGET := $(BIN_DIR)/hello.out

# Sources and objects
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))

.PHONY: all run clean release

all: $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

run: all
	$(TARGET)

clean:
	rm -rf $(BIN_DIR)

# Optimized build: make release
release:
	$(MAKE) CXXFLAGS="-std=c++17 -Wall -O3" all


