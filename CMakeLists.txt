cmake_minimum_required(VERSION 2.6)

PROJECT(FastArray CXX C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3")

################################################################################
# GTest - http://code.google.com/p/googletest/
################################################################################
add_subdirectory(gtest-1.6.0)
enable_testing(true)

################################################################################
# FastArray
################################################################################
include_directories(src ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(unit-tests src/unit-tests.cpp)
target_link_libraries(unit-tests gtest gtest_main)
add_test(unit-tests unit-tests)
