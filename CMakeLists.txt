#

set(CMAKE_VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILE_TYPE DEBUG)
set(CMAKE_CXX_EXTENSIONS Off)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)
# set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

cmake_minimum_required(VERSION ${CMAKE_VERSION})

if(UNIX)
    message(STATUS "Linux/Unix")
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++ -Wunused-command-line-argument")
endif(UNIX)

if(WIN32)
    message(STATUS "Windows ${CMAKE_CXX_COMPILER}")
    if(${CMAKE_CXX_COMPILER} MATCHES "clang")
        message(STATUS "重置工具链")
        set(CMAKE_TOOLCHAIN_FILE "")
    endif(${CMAKE_CXX_COMPILER} MATCHES "clang")
endif(WIN32)


# Definitions
set(PROJECT_NAME_STR HomeWork)

# Project title and define versioning
project(${PROJECT_NAME_STR} VERSION 0.1.0)

message(STATUS "Operation system is ${CMAKE_SYSTEM} ${CMAKE_CXX_COMPILER_ID}")

if(MSVC)
    message(STATUS "MSVC ${MSVC_VERSION}")
    # 支持 C++ 异常处理并设置 MSVC 输入代码编码格式为 utf-8
    add_compile_options("/EHsc" "/source-charset:utf-8")
    message(STATUS "$ENV{VCPKG_ROOT}")
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}\\scripts\\buildsystems\\vcpkg.cmake")
endif(MSVC)


if(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    message(STATUS "Clang ${CMAKE_CXX_COMPILER_VERSION}")
endif(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")

message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

# CTEST_TARGETS_ADDED 1
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

message(STATUS "Enable testing ${CMAKE_SYSTEM}")

enable_testing()
include(CTest)

# Dependencies
# Eigen
find_package(Eigen3 CONFIG REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})
message(STATUS "Find Eigen3 ${Eigen3_VERSION} -> ${Eigen3_FOUND}")

# Catch2 v3
find_package(Catch2 CONFIG REQUIRED)
message(STATUS "Find Catch2 ${Catch2_VERSION} -> ${Catch2_FOUND}")
# These tests can use the Catch2-provided main
# add_executable(tests test.cpp)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# Spdlog
find_package(spdlog CONFIG REQUIRED)
message(STATUS "Find spdlog ${spdlog_VERSION} -> ${spdlog_FOUND}")

# Custom Functions
include(CMake/function.cmake)

# include(CMake/package.cmake)

# Enter Project
message(STATUS "Enter Project ${PROJECT_NAME_STR}")
# add_library(Homework Homework.cpp)

message(STATUS "Subdirectory [Math]")
# add_subdirectory(Math)

message(STATUS "Subdirectory [Structure]")
add_subdirectory(Structure)

# message(STATUS "Subdirectory [LeetCode]")
# add_subdirectory(LeetCode)

# message(STATUS "Subdirectory [Luogu]")
# add_subdirectory(Luogu)

# message(STATUS "Subdirectory [Luogu]")
# add_subdirectory(NowCoder)

message(STATUS "Subdirectory [Templates]")
# add_subdirectory(Templates)

message(STATUS "Subdirectory [Temp]")
add_subdirectory(Temp)

message(STATUS "Subdirectory [Notes]")
add_subdirectory(Notes)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

message(STATUS "Leave Project ${PROJECT_NAME_STR}")
