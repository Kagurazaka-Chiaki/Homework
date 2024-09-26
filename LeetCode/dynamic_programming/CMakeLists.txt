cmake_minimum_required(VERSION 3.18)

# Definitions
set(PROJECT_NAME_STR "Dynamic Programming")

# Project title and define versioning
project("DP" VERSION 0.1.0)

message(STATUS "-> Enter Project ${PROJECT_NAME_STR}")

set(SOURCE_DIR ${SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/include)
set(TEST_DIR ${TEST_DIR} ${PROJECT_SOURCE_DIR}/test)

# Include
message(STATUS "-> Include ${INCLUDE_DIR}/dplib")
# include_directories(include)

# Lib
# message(STATUS "-> Lib ...")
file(GLOB SINGLE_CPP_SRC_LIST ${SOURCE_DIR}/*.cpp)
add_library(dp SHARED ${SINGLE_CPP_SRC_LIST})
target_include_directories(dp PUBLIC ${INCLUDE_DIR})


# Build
message(STATUS "-> Building ...")

add_executable(dp_main main.cpp)
target_link_libraries(dp_main PRIVATE dp)

# Unit tests
message(STATUS "-> Unit Tests ...")
add_subdirectory(test)

message(STATUS "-> Leave Project ${PROJECT_NAME_STR}")
