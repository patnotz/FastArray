cmake_minimum_required(VERSION 2.6)

PROJECT(FastArray CXX C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3")

find_package(Threads)
if (CMAKE_USE_PTHREADS_INIT)  # The pthreads library is available and allowed.
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DGTEST_HAS_PTHREAD=1")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DGTEST_HAS_PTHREAD=0")
endif()

################################################################################
# GTest
# See: http://code.google.com/p/googletest/
################################################################################
set(GTEST_DIR gtest-1.6.0)
set(GTEST_INCLUDE_DIRECTORIES ${GTEST_DIR}/include ${GTEST_DIR})
include_directories(${GTEST_INCLUDE_DIRECTORIES})
add_library(gtest ${GTEST_DIR}/src/gtest-all.cc ${GTEST_DIR}/src/gtest_main.cc)
enable_testing(true)

################################################################################
# FastArray
################################################################################
include_directories(src ${GTEST_INCLUDE_DIRS})
add_executable(unit-tests src/unit-tests.cpp)
target_link_libraries(unit-tests gtest ${CMAKE_THREAD_LIBS_INIT})
add_test(unit-tests unit-tests)
