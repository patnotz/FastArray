cmake_minimum_required(VERSION 2.6)

# HACK:
add_definitions("-g -O3")

PROJECT(FastArray)

################################################################################
# GTest
# See: http://code.google.com/p/googletest/
################################################################################
set(GTEST_DIR gtest-1.6.0)
set(GTEST_INCLUDE_DIRECTORIES ${GTEST_DIR}/include ${GTEST_DIR} ${GTEST_DIR}/src)
include_directories(${GTEST_INCLUDE_DIRECTORIES})
add_library(gtest ${GTEST_DIR}/src/gtest-all.cc ${GTEST_DIR}/src/gtest_main.cc)
enable_testing(true)

################################################################################
# FastArray
################################################################################
include_directories(src ${GTEST_INCLUDE_DIRS})
add_executable(unit-tests src/unit-tests.cpp)
target_link_libraries(unit-tests gtest)
add_test(unit-tests unit-tests)
