cmake_minimum_required(VERSION 2.6)

include_directories( . ${GTEST_INCLUDE_DIRS})

#if(GTEST_FOUND)

enable_testing(true)
add_executable(unit-tests unit-tests.cpp)
target_link_libraries(unit-tests gtest)
add_test(unit-tests unit-tests)

#endif()
