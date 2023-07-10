
cmake_minimum_required(VERSION 3.18)

# Definitions
set(PROJECT_NAME_STR "临时项目")

# Project title and define versioning
project("useEigen" VERSION 0.1.0)

message(STATUS "-> Enter Project ${PROJECT_NAME_STR}")

# # Eigen
# find_package(Eigen3 CONFIG REQUIRED)
# include_directories(${EIGEN3_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)

add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

message(STATUS "-> Leave Project ${PROJECT_NAME_STR}")
