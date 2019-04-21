all: compile

compile:
	cd build/ && $(MAKE) --no-print-directory -j8 --silent

clean:
	$(RM) -rf build/

build:
	cmake -H. -Bbuild

test: compile
	cd build/ && $(MAKE) test --no-print-directory ARGS=-V

coverage: compile test
	cd build/ && $(MAKE) --no-print-directory coverage
	rm -rf ./build/html
	genhtml --output-directory ./build/html ./build/challenger.info
