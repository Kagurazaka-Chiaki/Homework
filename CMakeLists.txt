cmake_minimum_required(VERSION 3.18)


if(UNIX)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++ -Wunused-command-line-argument")
    set(CMAKE_CXX_STANDARD 11)
endif(UNIX)

set(CMAKE_CXX_STANDARD 20)

SET(CMAKE_BUILE_TYPE DEBUG)

# Definitions
set(PROJECT_NAME_STR HomeWork)

# Project title and define versioning
project(${PROJECT_NAME_STR} VERSION 0.1.0)

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

message(STATUS "Enter Project ${PROJECT_NAME_STR}")

# add_library(Homework Homework.cpp)

message(STATUS "Subdirectory [LeetCode]")
add_subdirectory(LeetCode)

message(STATUS "Leave Project ${PROJECT_NAME_STR}")
