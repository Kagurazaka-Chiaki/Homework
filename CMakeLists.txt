cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS Off)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

# SET(CMAKE_BUILE_TYPE DEBUG)

if(UNIX)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++ -Wunused-command-line-argument")
    set(CMAKE_CXX_STANDARD 11)
endif(UNIX)


# Definitions
set(PROJECT_NAME_STR HomeWork)

# Project title and define versioning
project(${PROJECT_NAME_STR} VERSION 0.1.0)

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

message(STATUS "Enter Project ${PROJECT_NAME_STR}")

# add_library(Homework Homework.cpp)

message(STATUS "Subdirectory [LeetCode]")
# add_subdirectory(LeetCode)

message(STATUS "Subdirectory [Temp]")
add_subdirectory(Temp)

message(STATUS "Leave Project ${PROJECT_NAME_STR}")
