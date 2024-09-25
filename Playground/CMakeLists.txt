cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 20)


add_executable(playground main.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
