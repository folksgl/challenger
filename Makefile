all: compile
N_PROC := $(shell nproc)

build_dir:
	@if [ ! -d "./build" ];then     \
			cmake -S . -B ./build -Wdev -D CMAKE_EXPORT_COMPILE_COMMANDS=ON -D CMAKE_CXX_COMPILER=g++-9 ; \
			mv ./build/compile_commands.json ./src/ ; \
	fi

check:
	cppcheck --enable=all ./src

compile: build_dir
	cmake --build ./build --parallel $(N_PROC) -- --no-print-directory

clean: build_dir
	@$(RM) analysis gmon.out
	@cd ./build && make clean --no-print-directory

really_clean:
	@$(RM) -rf build/

test: compile
	cmake --build ./build --target test --parallel $(N_PROC) -- --no-print-directory ARGS=-V

coverage: compile test
	cmake --build ./build --target coverage --parallel $(N_PROC) -- --no-print-directory
	@rm -rf ./build/html
	genhtml --output-directory ./build/html ./build/challenger.info

optimized: build_dir
	cmake --build ./build --target optimized --parallel $(N_PROC) -- --no-print-directory

windows: build_dir
	cmake --build ./build --target windows_challenger --parallel $(N_PROC) -- --no-print-directory

benchmark: build_dir
	cmake --build ./build --target benchmark --parallel $(N_PROC) -- --no-print-directory
	./build/benchmark_challenger >> benchmarking_reference

perft: build_dir
	cmake --build ./build --target perft --parallel $(N_PROC) -- --no-print-directory

profile: compile
	@if [ -f "./gmon.out" ]; then \
			$(RM) "./gmon.out"; \
	fi
	@echo "position startpos\ngo depth 10\nquit" > tmp_input_challenger
	@./build/challenger < tmp_input_challenger
	@$(RM) tmp_input_challenger
	gprof -b ./build/challenger gmon.out > tmp_analysis
	@echo " " >> analysis
	@echo " " >> analysis
	@echo " " >> analysis
	@echo " " >> analysis
	@echo " " >> analysis
	head -n 30 tmp_analysis >> analysis
	@$(RM) tmp_analysis

travis: build_dir
	cmake --build ./build --parallel $(N_PROC)

travis_test: travis
	cmake --build ./build --target test --parallel $(N_PROC) -- --no-print-directory ARGS=-V
