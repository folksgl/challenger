
# PHONY target descriptions:
# 	- test: compiles and runs the tests for the challenger project
# 	- clean: removes object files and executables
# 	- optimized: compiles challenger with heavy optimization (used for releases, not development)

.PHONY: test clean optimized

# Compiler Settings
CXX = g++
CXXFLAGS = -g3 -std=c++11 -Wall

# DEVELOPERS, the googletest home directory goes here. i.e. if you cloned googletest into /usr/lib, then
# GTEST_DIR would then be /usr/lib/googletest
GTEST_DIR = $(HOME)/googletest

# Libraries needed to link for googletest.
TEST_LIBS = -lgtest -lpthread

# Googletest has it's own main, so leave out challengers main.cpp when compiling tests.
TEST_SRC := $(filter-out src/main.cpp, $(wildcard src/*.cpp))
TEST_SRC += $(wildcard test/*.cpp)

# Test flags
TEST_EXECUTABLE = test_runner
TEST_CXX_FLAGS = $(CXXFLAGS) -isystem $(GTEST_DIR)/googletest/include 

# Project flags
BUILD_DIR = build
EXECUTABLE = challenger
OBJS = main.o uci.o position.o

all : challenger

setOptimizeflags: 
	$(eval CXXFLAGS = -std=c++11 -Wall -s -O3)

optimized : setOptimizeflags challenger

challenger : directory $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(BUILD_DIR)/*.o

directory: 
	$(shell if [ ! -d build ]; then mkdir build; fi )

%.o : src/%.cpp
	$(CXX) -c $(CXXFLAGS) -o build/$@ $<

test :
	$(CXX) $(TEST_CXX_FLAGS) -o $(BUILD_DIR)/$(TEST_EXECUTABLE) $(TEST_SRC) $(TEST_LIBS)
	$(BUILD_DIR)/$(TEST_EXECUTABLE)

clean :
	rm -rf $(BUILD_DIR) ./challenger
