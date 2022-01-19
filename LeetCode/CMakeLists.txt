cmake_minimum_required(VERSION 3.18)

# Definitions
set(PROJECT_NAME_STR LeetCode)

# Project title and define versioning
project(${PROJECT_NAME_STR} VERSION 0.1.0)

message(STATUS "Enter ${PROJECT_NAME_STR}")

message(STATUS "Subdirectory [CodingInterviews]")
add_subdirectory(CodingInterviews)

message(STATUS "Leave Project ${PROJECT_NAME_STR}")