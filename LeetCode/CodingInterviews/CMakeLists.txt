cmake_minimum_required(VERSION 3.21)
project(CodingCPP VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

# include(CTest)
# enable_testing()

add_executable(09 09.cpp)
add_executable(30 30.cpp)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)