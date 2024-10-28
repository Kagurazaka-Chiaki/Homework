cmake_minimum_required(VERSION 3.18)

# Definitions
set(PROJECT_NAME_STR "Binary Search")

# Project title and define versioning
project("BS" VERSION 0.1.0)

message(STATUS "-> Enter Project ${PROJECT_NAME_STR}")

set(INCLUDE_DIR ${INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_DIR ${SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
set(TEST_DIR ${TEST_DIR} ${PROJECT_SOURCE_DIR}/test)

# Include
message(STATUS "-> Include ${INCLUDE_DIR}/bslib")
# include_directories(include)

# Lib
message(STATUS "-> Lib ...")
file(GLOB BS_CPP_SRC_LIST ${SOURCE_DIR}/*.cpp)
add_library(bs STATIC ${BS_CPP_SRC_LIST})
target_include_directories(bs PUBLIC ${INCLUDE_DIR})

# Build
message(STATUS "-> Building ...")


add_executable(bs_main main.cpp)
target_link_libraries(bs_main PRIVATE bs)


# Unit tests
message(STATUS "-> Unit Tests ...")
add_subdirectory(test)

message(STATUS "-> Leave Project ${PROJECT_NAME_STR}")
