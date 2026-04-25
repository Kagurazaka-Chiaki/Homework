#

set(CMAKE_VERSION 3.31)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
# set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

cmake_minimum_required(VERSION ${CMAKE_VERSION})

if(UNIX)
    message(STATUS "Linux/Unix")
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++ -Wunused-command-line-argument")
endif(UNIX)

# if(WIN32)
#     message(STATUS "Windows ${CMAKE_CXX_COMPILER}")
#     set(CMAKE_C_COMPILER "$ENV{CLANG_CL_EXE}")
#     set(CMAKE_CXX_COMPILER "$ENV{CLANG_CL_EXE}")
#     message(STATUS "Windows ${CMAKE_CXX_COMPILER}")
#     # if(${CMAKE_CXX_COMPILER} MATCHES "clang")
#     #     message(STATUS "重置工具链")
#     #     set(CMAKE_TOOLCHAIN_FILE "")
#     # endif(${CMAKE_CXX_COMPILER} MATCHES "clang")
# endif(WIN32)


# Definitions
set(PROJECT_NAME_STR HomeWork)

# Project title and define versioning
project(${PROJECT_NAME_STR} VERSION 0.1.0)

message(STATUS "Operation system is ${CMAKE_SYSTEM} ${CMAKE_CXX_COMPILER_ID}")

if(MSVC)
    message(STATUS "MSVC ${MSVC_VERSION}")
    # 支持 C++ 异常处理并设置 MSVC 输入代码编码格式为 utf-8
    add_compile_options("/EHsc") # "/source-charset:utf-8" "/execution-charset:utf-8"
    message(STATUS "VCPKG_ROOT=$ENV{VCPKG_ROOT}")
    # 多核编译
    add_compile_options("/MP")
    # 设置 C++ 标准
    # add_compile_options("/std:c++20")
    # 使 MSVC 的 __cplusplus 宏符合实际的 C++ 标准
    add_compile_options("/Zc:__cplusplus")
    # C++ 模块支持
    # add_compile_options("/experimental:module")
endif(MSVC)



# if(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
#     message(STATUS "Clang ${CMAKE_CXX_COMPILER_VERSION}")
# endif(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")

message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

# CTEST_TARGETS_ADDED 1
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

message(STATUS "Enable testing ${CMAKE_SYSTEM}")

enable_testing()
include(CTest)

# Build groups
option(HOMEWORK_ENABLE_ALGO_MODULES "Build algorithm/problem-solving modules" ON)
option(HOMEWORK_ENABLE_SUPPORT_MODULES "Build lightweight support modules" ON)
option(HOMEWORK_ENABLE_EXPERIMENTAL_MODULES "Build experimental modules with extra dependencies" ON)
option(HOMEWORK_ENABLE_GRAPHICS_MODULES "Build graphics/model/unity modules" ON)
option(HOMEWORK_ENABLE_CXX_MODULES "Enable experimental C++20 module targets" OFF)

if(HOMEWORK_ENABLE_GRAPHICS_MODULES OR HOMEWORK_ENABLE_EXPERIMENTAL_MODULES)
    set(HOMEWORK_BUILD_FLAVOR "full")
else()
    set(HOMEWORK_BUILD_FLAVOR "lite")
endif()

message(STATUS "HomeWork build flavor: ${HOMEWORK_BUILD_FLAVOR}")
message(
    STATUS
    "HomeWork modules: algo=${HOMEWORK_ENABLE_ALGO_MODULES}, "
    "support=${HOMEWORK_ENABLE_SUPPORT_MODULES}, "
    "experimental=${HOMEWORK_ENABLE_EXPERIMENTAL_MODULES}, "
    "graphics=${HOMEWORK_ENABLE_GRAPHICS_MODULES}, "
    "tests=${BUILD_TESTING}, "
    "cxx_modules=${HOMEWORK_ENABLE_CXX_MODULES}"
)

macro(homework_add_module dir enabled_var)
    if(${enabled_var})
        message(STATUS "Subdirectory [${dir}]")
        add_subdirectory(${dir})
    else()
        message(STATUS "Skip subdirectory [${dir}]")
    endif()
endmacro()

include(CMake/package.cmake)

# Enter Project
message(STATUS "Enter Project ${PROJECT_NAME_STR}")
# add_library(Homework Homework.cpp)

homework_add_module(Math HOMEWORK_ENABLE_SUPPORT_MODULES)
homework_add_module(Structure HOMEWORK_ENABLE_ALGO_MODULES)
homework_add_module(LeetCode HOMEWORK_ENABLE_ALGO_MODULES)
homework_add_module(Luogu HOMEWORK_ENABLE_ALGO_MODULES)
homework_add_module(NowCoder HOMEWORK_ENABLE_ALGO_MODULES)
homework_add_module(Templates HOMEWORK_ENABLE_SUPPORT_MODULES)
homework_add_module(Common HOMEWORK_ENABLE_EXPERIMENTAL_MODULES)
homework_add_module(Temp HOMEWORK_ENABLE_EXPERIMENTAL_MODULES)
homework_add_module(Notes HOMEWORK_ENABLE_SUPPORT_MODULES)
homework_add_module(Pathfinding HOMEWORK_ENABLE_SUPPORT_MODULES)
homework_add_module(Playground HOMEWORK_ENABLE_SUPPORT_MODULES)
homework_add_module(Vision HOMEWORK_ENABLE_GRAPHICS_MODULES)
homework_add_module(Model HOMEWORK_ENABLE_GRAPHICS_MODULES)

message(STATUS "Subdirectory [Modules]")
# add_subdirectory(Modules) # C++20 Modules Not Supported

homework_add_module(Unity HOMEWORK_ENABLE_GRAPHICS_MODULES)
homework_add_module(Concurrency HOMEWORK_ENABLE_SUPPORT_MODULES)
homework_add_module(Automaton HOMEWORK_ENABLE_SUPPORT_MODULES)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

message(STATUS "Leave Project ${PROJECT_NAME_STR}")
