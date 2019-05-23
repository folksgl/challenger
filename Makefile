all: compile


build_dir:
	@if [ ! -d "./build" ];then     \
			cmake -H. -Bbuild ; \
			cd build ; \
			cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON . ; \
			mv compile_commands.json ../src/ ; \
	fi

compile: build_dir
	@cd build/ && $(MAKE) --no-print-directory -j8 --silent

clean: build_dir
	@$(RM) analysis gmon.out
	@cd ./build && make clean --no-print-directory

really_clean:
	@$(RM) -rf build/

build:
	@cmake -H. -Bbuild

test: compile
	@cd build/ && $(MAKE) test --no-print-directory ARGS=-V

coverage: compile test
	@cd build/ && $(MAKE) --no-print-directory coverage
	@rm -rf ./build/html
	genhtml --output-directory ./build/html ./build/challenger.info

optimized: build_dir
	@cd build/ && $(MAKE) optimized --no-print-directory -j8 --silent

benchmark: build_dir
	@cd build/ && $(MAKE) benchmark --no-print-directory -j8 --silent
	./build/benchmark_challenger >> benchmarking_reference

profile: compile
	@if [ -f "./gmon.out" ]; then \
			$(RM) "./gmon.out"; \
	fi
	@if [ -f "./analysis" ]; then \
			$(RM) "./analysis"; \
	fi
	@echo "position startpos\ngo depth 1\nquit" > tmp_input_challenger
	@./build/challenger < tmp_input_challenger
	@$(RM) tmp_input_challenger
	gprof -b ./build/challenger gmon.out > analysis
