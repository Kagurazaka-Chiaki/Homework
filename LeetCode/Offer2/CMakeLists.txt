cmake_minimum_required(VERSION 3.18)

# Definitions
set(PROJECT_NAME_STR Offer2)

# Project title and define versioning
project(${PROJECT_NAME_STR} VERSION 0.1.0)

message(STATUS "")
message(STATUS "---------- Enter Project ${PROJECT_NAME_STR}")

if (UNIX)
    message(STATUS "Linux")
else (WIN32)
    message(STATUS "Windows")
endif ()


if (MSVC)
    # 设置 msvc 输入代码编码格式为 utf-8
    set(CMAKE_C_FLAGS /source-charset:utf-8)
endif()


add_subdirectory(src)
add_subdirectory(test)

message(STATUS "---------- Leave Project ${PROJECT_NAME_STR}")
message(STATUS "")