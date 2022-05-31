cmake_minimum_required(VERSION 3.18)



find_package(Catch2 REQUIRED)
message(STATUS "Catch2_FOUND      = ${Catch2_FOUND}" )

enable_testing()

add_executable(foo test_main.cpp)
target_link_libraries(foo PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(foo)