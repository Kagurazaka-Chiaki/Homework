cmake_minimum_required(VERSION 3.18)

message(STATUS "-> Enter Test ${PROJECT_NAME_STR}")

homework_require_catch2()

add_executable(test_basic test_basic.cpp)
target_link_libraries(test_basic PRIVATE Mathlib Catch2::Catch2WithMain)
add_test("test_basic" test_basic)

add_executable(test_geometry test_geometry.cpp)
target_link_libraries(test_geometry PRIVATE Mathlib Catch2::Catch2WithMain)
add_test("test_geometry" test_geometry)

message(STATUS "-> Leave Test ${PROJECT_NAME_STR}")
