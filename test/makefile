CC = g++
VERSION = -std=c++17
CFLAGS = -g -Wall
LFLAGS = -pthread
LIBS = -lpigpio
INCLUDE = -I
PARENT_DIRECTORY = ..
SRC_DIR = $(PARENT_DIRECTORY)/src/
BUILD_DIR = $(PARENT_DIRECTORY)/obj/
TEST_DIR = $(PARENT_DIRECTORY)/test/

# get source and test directories
INCLUDE_DIRS := $(SRC_DIR)
INCLUDE_DIRS += $(sort $(dir $(wildcard $(TEST_DIR)*/*)))

# Add sub-src directory files and get their .h dependencies
CPPSRC += $(patsubst /%,%,$(foreach %,$(INCLUDE_DIRS),$(wildcard $(%)*.cpp)))
CSRC += $(patsubst /%,%,$(foreach %,$(INCLUDE_DIRS),$(wildcard $(%)*.c)))
DEPENDENCIES += $(patsubst /%,%,$(foreach %,$(INCLUDE_DIRS),$(wildcard $(%)*.h)))

# Create flags to include all directories (so we don't have to use paths in #include)
INCLUDE_FLAGS := $(foreach %,$(INCLUDE_DIRS),$(INCLUDE)$(wildcard $(%)))

# create .o file paths for .cpp files in src and test
OBJ_SRC := $(patsubst $(SRC_DIR)%,$(BUILD_DIR)%, $(CPPSRC:.cpp=.o) $(CSRC:.c=.o))
OBJ := $(patsubst $(TEST_DIR)%,$(BUILD_DIR)%, $(OBJ_SRC))

# pattern rules for src and test folders
$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp $(DEPENDENCIES)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDE_FLAGS)

$(BUILD_DIR)%.o: $(TEST_DIR)%.cpp $(DEPENDENCIES)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDE_FLAGS)

$(info OBJ is $(OBJ))

# tests
test-fill: $(OBJ) $(BUILD_DIR)test-fill.o
	$(CC) $(VERSION) $(CFLAGS) $(LFLAGS) -o $@ $^ $(LIBS) $(INCLUDE_FLAGS)

test-grid: $(OBJ) $(BUILD_DIR)test-grid.o
	$(CC) $(VERSION) $(CFLAGS) $(LFLAGS) -o $@ $^ $(LIBS) $(INCLUDE_FLAGS)

test-rainbow: $(OBJ) $(BUILD_DIR)test-rainbow.o
	$(CC) $(VERSION) $(CFLAGS) $(LFLAGS) -o $@ $^ $(LIBS) $(INCLUDE_FLAGS)

test-shape:  $(OBJ) $(BUILD_DIR)test-shape.o
	$(CC) $(VERSION) $(CFLAGS) $(LFLAGS) -o $@ $^ $(LIBS) $(INCLUDE_FLAGS)

all: test-fill test-grid test-rainbow test-shape

.PHONY: clean

clean:
	rm -r $(BUILD_DIR) test-fill test-grid test-rainbow test-shape