cmake_minimum_required(VERSION 2.6)

PROJECT(FastArray)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3")

################################################################################
# GTest - http://code.google.com/p/googletest/
################################################################################
add_subdirectory(gtest-1.6.0)
enable_testing(true)

################################################################################
# Boost
################################################################################
set(Boost_ADDITIONAL_VERSIONS 1.47 1.47.0)
find_package(Boost 1.47 REQUIRED)

################################################################################
# Auto-version generation
################################################################################
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/fa_autoversion.hpp
    COMMAND ${PROJECT_SOURCE_DIR}/create-version-header.sh ${PROJECT_SOURCE_DIR}/version-gen.sh ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS 
    COMMENT "Generating auto-version header file from Git..."
    ALL
)

################################################################################
# FastArray
################################################################################
FILE(GLOB SOURCES "src/fa_*.cpp")
FILE(GLOB FA_HEADERS "src/fa_*.hpp")
SET ( HEADERS
    ${CMAKE_CURRENT_BINARY_DIR}/fa_autoversion.hpp
    ${FA_HEADERS}
)

add_library(falib ${SOURCES} ${HEADERS})

SET ( fa_LIBRARIES
    falib
)

include_directories(
    src 
    ${gtest_SOURCE_DIR}/include 
    ${gtest_SOURCE_DIR}
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR} # for fa_version.hpp
    )
    
add_executable(unit-tests src/unit-tests.cpp)

target_link_libraries(unit-tests 
    gtest 
    gtest_main
    ${fa_LIBRARIES} 
    ${Boost_LIBRARIES}
    )

add_test(unit-tests unit-tests)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND}
                  DEPENDS unit-tests)
