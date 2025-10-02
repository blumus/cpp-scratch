# A solid Makefile for building all top-level .cpp files

# Toolchain
CXX ?= g++

# Build type: Debug or Release
BUILD ?= Debug

# Flags
COMMON_CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic
ifeq ($(BUILD),Debug)
  CXXFLAGS ?= $(COMMON_CXXFLAGS) -g -O0
else ifeq ($(BUILD),Release)
  CXXFLAGS ?= $(COMMON_CXXFLAGS) -O3
else
  $(error BUILD must be Debug or Release)
endif

LDFLAGS ?=
LDLIBS  ?=

# Layout
BIN_DIR := build
TARGET  := $(BIN_DIR)/unordered_set_exercise.out

# Sources / objects / deps
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,$(BIN_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all run clean distclean rebuild debug release

all: $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%.o: %.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)

run: $(TARGET)
	$<

clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/*.d $(TARGET)

distclean:
	rm -rf $(BIN_DIR)

rebuild: distclean all

debug:
	$(MAKE) BUILD=Debug

release:
	$(MAKE) BUILD=Release

-include $(DEPS)

