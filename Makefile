
# Phony target descriptions:
# 	test - compiles and runs test suite
# 	clean - removes object files and executables
# 	run - runs a user-implemented "run.sh" script.
# 	all - reserved; not implemented

.PHONY: test clean

# Compiler Settings
CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

# Libraries needed to link for googletest.
TEST_LIBS = -lgtest -lpthread

# Googletest has it's own main, so leave out challengers main.cpp when compiling tests.
TEST_SRC := $(filter-out src/main.cpp, $(wildcard src/*.cpp))
TEST_SRC += $(wildcard test/*.cpp)

# Test flags
TEST_EXECUTABLE = test_runner
TEST_CXX_FLAGS = $(CXXFLAGS) -isystem $(HOME)/googletest/googletest/include 

# Project flags
BUILD_DIR = build
EXECUTABLE = challenger
OBJS = main.o uci.o position.o


$(shell if [ ! -d build ]; then mkdir build; fi )

challenger : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(BUILD_DIR)/*.o

%.o : src/%.cpp
	$(CXX) -c $(CXXFLAGS) -o build/$@ $<

test :
	$(CXX) $(TEST_CXX_FLAGS) -o $(BUILD_DIR)/$(TEST_EXECUTABLE) $(TEST_SRC) $(TEST_LIBS)
	$(BUILD_DIR)/$(TEST_EXECUTABLE)

clean :
	rm -rf $(BUILD_DIR) ./challenger
