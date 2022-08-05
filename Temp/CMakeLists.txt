# CMake要求本版信息即项目名称，创建时自动生成
cmake_minimum_required(VERSION 3.18)
project(useEigen)

set(CMAKE_CXX_STANDARD 20)

# # 寻找Eigen库
find_package(Eigen3 REQUIRED)
# # 将Eigen库include进来
include_directories(${EIGEN3_INCLUDE_DIRS})

find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_executable(${PROJECT_NAME} TX01.cpp)