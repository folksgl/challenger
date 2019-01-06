.PHONY: all test clean

TESTLIBS = -lgtest -lpthread
CXXFLAGS = -g -Wall
DIRS = build

$(shell if [ ! -d build ]; then mkdir build; fi )

challenger : main.o
	g++ $(CXXFLAGS) -o challenger ./build/main.o

main.o : src/main.cpp
	g++ $(CXXFLAGS) -c -o build/main.o src/main.cpp 

test : 
	g++ $(CXXFLAGS) -o build/test_runner test/*.cpp $(TESTLIBS)
	./build/test_runner

clean : 
	rm -rf ./build ./challenger
