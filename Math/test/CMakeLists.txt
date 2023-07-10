cmake_minimum_required(VERSION 3.18)

message(STATUS "-> Enter Test ${PROJECT_NAME_STR}")

# Catch2 v3
find_package(Catch2 3 REQUIRED)
message(STATUS "Find Catch2 ${Catch2_VERSION}   -> ${Catch2_FOUND}")

add_executable(test_basic test_basic.cpp)
target_link_libraries(test_basic PRIVATE Mathlib Catch2::Catch2WithMain)
add_test("test_basic" test_basic)

message(STATUS "-> Leave Test ${PROJECT_NAME_STR}")
