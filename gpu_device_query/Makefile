CXX := nvcc

SRC_DIRS := ./src

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))


CPPFLAGS += $(INC_FLAGS)
CPPFLAGS += -MMD -MP
CXXFLAGS := -std=c++17

TARGET_EXEC := main

BUILD_DIR := ./build
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# Linking objects to executable
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compiling source to objects
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
