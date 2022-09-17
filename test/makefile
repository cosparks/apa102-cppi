CC = g++
VERSION = -std=c++17
CFLAGS = -g -Wall
LFLAGS = -pthread
LIBS = -lpigpio
INCLUDE = -I
PARENT_DIRECTORY = ../
SRC_DIR = $(PARENT_DIRECTORY)src/
BUILD_DIR = $(PARENT_DIRECTORY)obj/
TEST_DIR = $(PARENT_DIRECTORY)test/

# get source and test directories
INCLUDE_DIRS := $(SRC_DIR)
INCLUDE_DIRS += $(sort $(dir $(wildcard $(TEST_DIR)*/*)))

# Add sub-src directory files and get their .h dependencies
CPPSRC += $(foreach %,$(INCLUDE_DIRS),$(wildcard $(%)*.cpp))
DEPENDENCIES += $(foreach %,$(INCLUDE_DIRS),$(wildcard $(%)*.h))

# Create flags to include all directories (so we don't have to use paths in #include)
INCLUDE_FLAGS := $(foreach %,$(INCLUDE_DIRS),$(INCLUDE)$(wildcard $(%)))

# create .o file paths for .cpp files in src and test
OBJ := $(patsubst $(PARENT_DIRECTORY)%,$(BUILD_DIR)%, $(CPPSRC:.cpp=.o))


# pattern rules for src and test folders
$(BUILD_DIR)%.o: $(PARENT_DIRECTORY)%.cpp $(DEPENDENCIES)
	@echo ' *** Compiling $@ *** '
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDE_FLAGS)

# tests
test-edges: $(OBJ) $(BUILD_DIR)test/test-edges.o
	@echo ' *** Building $@ *** '
	@$(CC) $(VERSION) $(CFLAGS) $(LFLAGS) -o $@ $^ $(LIBS) $(INCLUDE_FLAGS)

test-fill: $(OBJ) $(BUILD_DIR)test/test-fill.o
	@echo ' *** Building $@ *** '
	@$(CC) $(VERSION) $(CFLAGS) $(LFLAGS) -o $@ $^ $(LIBS) $(INCLUDE_FLAGS)

test-grid: $(OBJ) $(BUILD_DIR)test/test-grid.o
	@echo ' *** Building $@ *** '
	@$(CC) $(VERSION) $(CFLAGS) $(LFLAGS) -o $@ $^ $(LIBS) $(INCLUDE_FLAGS)

test-rainbow: $(OBJ) $(BUILD_DIR)test/test-rainbow.o
	@echo ' *** Building $@ *** '
	@$(CC) $(VERSION) $(CFLAGS) $(LFLAGS) -o $@ $^ $(LIBS) $(INCLUDE_FLAGS)

test-shape:  $(OBJ) $(BUILD_DIR)test/test-shape.o
	@echo ' *** Building $@ *** '
	@$(CC) $(VERSION) $(CFLAGS) $(LFLAGS) -o $@ $^ $(LIBS) $(INCLUDE_FLAGS)

all: test-fill test-grid test-rainbow test-shape test-edges

.PHONY: clean

clean:
	rm -r $(BUILD_DIR) test-fill test-grid test-rainbow test-shape test-edges