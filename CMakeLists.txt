cmake_minimum_required(VERSION 3.10)
project("Challenger")

### GOOGLETEST START ###
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build . -- --no-print-directory
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

### GOOGLETEST END ###

# Add src and test files
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -g3 -Og -fprofile-arcs -ftest-coverage")

set(SRC_DIR src)
set(TEST_DIR "test")
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp)
file(GLOB_RECURSE TEST_FILES ${TEST_DIR}/*.cpp ${SRC_FILES}/*.cpp)
set(SRC_FILE_LIST ${SRC_FILES})
set(TEST_FILE_LIST ${TEST_FILES})
list(REMOVE_ITEM TEST_FILE_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)


add_executable(challenger ${SRC_FILE_LIST})

enable_testing()
set (TEST_FILE_NAME runtest)
add_executable(${TEST_FILE_NAME} ${TEST_FILE_LIST})

target_link_libraries(${TEST_FILE_NAME} gtest)

add_test(unit_tests ${TEST_FILE_NAME} --gtest_color=yes)

# Add test coverage generation and cleaning
set(COVERAGE_OUTPUT_FILE challenger.info)
add_custom_target(coverage
    COMMAND lcov --directory ./CMakeFiles/${TEST_FILE_NAME}.dir/${SRC_DIR}/ --zerocounters 
    COMMAND make test 
    COMMAND lcov --directory ./CMakeFiles/${TEST_FILE_NAME}.dir/${SRC_DIR}/ --directory ${CMAKE_CURRENT_SOURCE_DIR}/${SRC_DIR} --capture --no-external --output-file ${COVERAGE_OUTPUT_FILE} --quiet
    COMMAND lcov --remove ${COVERAGE_OUTPUT_FILE} *.h -o coverage_tmp
    COMMAND mv coverage_tmp ${COVERAGE_OUTPUT_FILE}
    BYPRODUCTS ${COVERAGE_OUTPUT_FILE}
    )
#add_custom_target()

