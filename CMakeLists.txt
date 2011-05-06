cmake_minimum_required(VERSION 2.6)

# HACK:
add_definitions("-g -O2")

PROJECT(FastArray)

################################################################################
# GTest
# See: http://code.google.com/p/googletest/
################################################################################
set(GTEST_ROOT /usr/local/gtest-1.5.0)
find_package(GTest)
if(GTEST_FOUND)
   enable_testing(true)
endif()

add_subdirectory(src)
