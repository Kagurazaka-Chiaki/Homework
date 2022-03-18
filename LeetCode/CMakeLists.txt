cmake_minimum_required(VERSION 3.18)

# Definitions
set(PROJECT_NAME_STR LeetCode)

# Project title and define versioning
project(${PROJECT_NAME_STR} VERSION 0.1.0)

message(STATUS "Enter ${PROJECT_NAME_STR}")

# message(STATUS "Subdirectory [Offer]")
# add_subdirectory(Offer)

message(STATUS "Subdirectory [Dynamic Programming]")
add_subdirectory(DP)

message(STATUS "Leave Project ${PROJECT_NAME_STR}")