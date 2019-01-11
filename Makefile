.PHONY: all test clean

TESTLIBS = -lgtest -lpthread
CXXFLAGS = -g -Wall
DIRS = build

$(shell if [ ! -d build ]; then mkdir build; fi )

challenger : main.o uci.o position.o
	g++ $(CXXFLAGS) -o challenger ./build/main.o ./build/uci.o ./build/position.o

main.o : src/main.cpp
	g++ $(CXXFLAGS) -c -o build/main.o src/main.cpp

uci.o : src/uci.cpp
	g++ $(CXXFLAGS) -c -o build/uci.o src/uci.cpp

position.o: src/position.cpp
	g++ $(CXXFLAGS) -c -o build/position.o src/position.cpp

test :
	g++ $(CXXFLAGS) -o build/test_runner test/*.cpp $(TESTLIBS)
	./build/test_runner

clean :
	rm -rf ./build ./challenger
