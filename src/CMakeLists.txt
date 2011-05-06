cmake_minimum_required(VERSION 2.8)

#
# External dependencies and paths
#
#find_package(Boost 1.46.0 REQUIRED)
include_directories (
    .
#    ${Boost_INCLUDE_DIRS}
#    ${Trilinos_INCLUDE_DIRS}
#    ${Trilinos_TPL_INCLUDE_DIRS}
)

#link_directories (
#    ${Trilinos_LIBRARY_DIRS} 
#    ${Trilinos_TPL_LIBRARY_DIRS} 
#)

if(GTEST_FOUND)
   enable_testing(true)
   add_executable(unit-tests unit-tests.cpp)
   target_link_libraries(unit-tests 
      ${GTEST_BOTH_LIBRARIES}
      #${Boost_LIBRARIES}
      #${Trilinos_LIBRARIES}
      #${Trilinos_TPL_LIBRARIES}
   )
   add_test(unit-tests unit-tests)
endif()
