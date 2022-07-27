# CMake要求本版信息即项目名称，创建时自动生成
cmake_minimum_required(VERSION 3.18)
project(useEigen)

# 申明采用C++11标准，项目创建时自动生成
set(CMAKE_CXX_STANDARD 20)

# # 寻找Eigen库
# find_package(Eigen3 REQUIRED)
# # 将Eigen库include进来
# include_directories(${EIGEN3_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} TX01.cpp)