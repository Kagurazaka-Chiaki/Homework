cmake_minimum_required(VERSION ${CMAKE_VERSION})

# Definitions
set(PROJECT_NAME_STR LeetCode)

# Project title and define versioning
project(${PROJECT_NAME_STR} VERSION 0.1.0)

message(STATUS "Enter ${PROJECT_NAME_STR}")

# file(GLOB DP_SRC_LIST "dp/src/*.cpp")
# add_library(dp SHARED ${INCLUDE_DIR}/dplib.hpp ${DP_SRC_LIST})
# target_link_directories(dp PUBLIC ${INCLUDE_DIR}/dplib.hpp)

# file(GLOB BS_SRC_LIST "binary_search/src/*.cpp")
# add_library(bs SHARED ${BS_SRC_LIST} ${INCLUDE_DIR}/bslib.hpp)
# target_link_directories(bs PUBLIC ${INCLUDE_DIR})

# message(STATUS "Subdirectory [Offer]")
# add_subdirectory(Offer)

# message(STATUS "Subdirectory [Offer2]")
# add_subdirectory(Offer2)

message(STATUS "Subdirectory [Workspace]")
add_subdirectory(workspace)

message(STATUS "Subdirectory [二分查找]")
add_subdirectory(binary_search)

message(STATUS "Subdirectory [链表]")
add_subdirectory(linked_list)

message(STATUS "Subdirectory [动态规划]")
add_subdirectory(dynamic_programming)

message(STATUS "Subdirectory [树]")


add_executable(lib_main main.cpp)
target_link_libraries(lib_main PUBLIC dp bs)

message(STATUS "Leave Project ${PROJECT_NAME_STR}")