# Definitions
set(PROJECT_NAME_STR "Structure")

# Project title and define versioning
project("Structure" VERSION 0.1.0)

message(STATUS "-> Enter Project ${PROJECT_NAME_STR}")

add_subdirectory(Common)

add_subdirectory(LinkedList)

add_subdirectory(Tree)

message(STATUS "-> Leave Project ${PROJECT_NAME_STR}")
