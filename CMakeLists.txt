cmake_minimum_required(VERSION 3.16)
project(Challenger)

# Add src and test files
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Og -pg --coverage -pthread")

set(SRC_DIR src)
set(TEST_DIR "test")
set(BENCH_DIR "benchmarks")
set(PERFT_DIR "perft")

#set(SRC_PATTERN "${SRC_DIR}/*.cpp")

# List contains all .cpp files in the source directory
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")

# List contains all .cpp files in the source and test directories
file(GLOB_RECURSE TEST_FILES "${TEST_DIR}/*.cpp" "${SRC_DIR}/*.cpp")
list(REMOVE_ITEM TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# List contains all .cpp files in the source and bench directories
file(GLOB_RECURSE BENCH_FILES "${BENCH_DIR}/*.cpp" "${SRC_DIR}/*.cpp")
list(REMOVE_ITEM BENCH_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# List contains all .cpp files in the source and perft directories
file(GLOB_RECURSE PERFT_FILES "${PERFT_DIR}/*.cpp" "${SRC_DIR}/*.cpp")
list(REMOVE_ITEM PERFT_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)


add_executable(challenger ${SRC_FILES})

# Testing
enable_testing()
find_package(GTest REQUIRED)
set (TEST_FILE_NAME runtest)
add_executable(${TEST_FILE_NAME} ${TEST_FILES})
target_link_libraries(${TEST_FILE_NAME} GTest::GTest)
add_test(unit_tests ${TEST_FILE_NAME} --gtest_color=yes)

# Add test coverage generation and cleaning
set(COVERAGE_OUTPUT_FILE challenger.info)
add_custom_target(coverage
    COMMAND lcov --directory ./CMakeFiles/${TEST_FILE_NAME}.dir/${SRC_DIR}/ --zerocounters 
    COMMAND make test 
    COMMAND lcov --directory ./CMakeFiles/${TEST_FILE_NAME}.dir/${SRC_DIR}/ --directory ${CMAKE_CURRENT_SOURCE_DIR}/${SRC_DIR} --capture --no-external --output-file ${COVERAGE_OUTPUT_FILE} --quiet
    COMMAND lcov --remove ${COVERAGE_OUTPUT_FILE} *.hpp -o coverage_tmp
    COMMAND mv coverage_tmp ${COVERAGE_OUTPUT_FILE}
    BYPRODUCTS ${COVERAGE_OUTPUT_FILE}
)

set(RELEASE_FLAGS "")

add_custom_target(optimized
    COMMAND g++ -o linux_challenger -O3 -pthread --std=c++17 ${SRC_FILES}
    BYPRODUCTS optimized_challenger
)

add_custom_target(windows_challenger
    COMMAND x86_64-w64-mingw32-c++-posix -o windows_challenger.exe -O3 -pthread --std=c++17 ${SRC_FILES}
    BYPRODUCTS windows_challenger
)

add_custom_target(benchmark
    COMMAND g++ -o benchmark_challenger -O3 -pthread --std=c++17 ${BENCH_FILES}
    BYPRODUCTS benchmark_challenger
)

add_custom_target(perft
    COMMAND g++ -o perft_challenger -DPERFT -O3 -pthread --std=c++17 ${PERFT_FILE_LIST}
    BYPRODUCTS perft_challenger
)

