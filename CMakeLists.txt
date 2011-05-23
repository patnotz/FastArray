cmake_minimum_required(VERSION 2.6)

# HACK:
add_definitions("-g -O2")

PROJECT(FastArray)

################################################################################
# GTest
# See: http://code.google.com/p/googletest/
################################################################################
#set(GTEST_ROOT ./gtest-1.5.0_gcc-4.5.3)
#find_package(GTest REQUIRED)

set(GTEST_DIR gtest-1.5.0)
set(GTEST_INCLUDE_DIRECTORIES ${GTEST_DIR}/include ${GTEST_DIR} ${GTEST_DIR}/src)

include_directories(${GTEST_INCLUDE_DIRECTORIES})
add_library(gtest ${GTEST_DIR}/src/gtest-all.cc ${GTEST_DIR}/src/gtest_main.cc)
enable_testing(true)

add_subdirectory(src)
