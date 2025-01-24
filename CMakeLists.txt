#

set(CMAKE_VERSION 3.28 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILE_TYPE DEBUG)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

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
    message(STATUS "$ENV{VCPKG_ROOT}")
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
    # 多核编译
    add_compile_options("/MP")
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

# glm
find_package(glm CONFIG REQUIRED)
message(STATUS "Find glm ${glm_VERSION} -> ${glm_FOUND}")

# Spdlog
find_package(spdlog CONFIG REQUIRED)
message(STATUS "Find spdlog ${spdlog_VERSION} -> ${spdlog_FOUND}")

# ICU
find_package(ICU COMPONENTS uc i18n REQUIRED)
message(STATUS "Find ICU ${ICU_VERSION} -> ${ICU_FOUND}")

# Proxy
find_package(proxy CONFIG REQUIRED)
message(STATUS "Found Proxy: ${proxy_DIR}")

# stb
find_package(Stb REQUIRED)
message(STATUS "Found stb: ${Stb_INCLUDE_DIR}")

# Assimp
find_package(assimp CONFIG REQUIRED)
message(STATUS "Found assimp: ${assimp_FOUND}")

# Custom Functions
include(CMake/function.cmake)

# include(CMake/package.cmake)

# Enter Project
message(STATUS "Enter Project ${PROJECT_NAME_STR}")
# add_library(Homework Homework.cpp)

message(STATUS "Subdirectory [Math]")
add_subdirectory(Math)

message(STATUS "Subdirectory [Structure]")
add_subdirectory(Structure)

message(STATUS "Subdirectory [LeetCode]")
add_subdirectory(LeetCode)

message(STATUS "Subdirectory [Luogu]")
add_subdirectory(Luogu)

message(STATUS "Subdirectory [Luogu]")
add_subdirectory(NowCoder)

message(STATUS "Subdirectory [Templates]")
add_subdirectory(Templates)

message(STATUS "Subdirectory [Common]")
add_subdirectory(Common)

message(STATUS "Subdirectory [Temp]")
add_subdirectory(Temp)

message(STATUS "Subdirectory [Notes]")
add_subdirectory(Notes)

message(STATUS "Subdirectory [Pathfinding]")
add_subdirectory(Pathfinding)

message(STATUS "Subdirectory [Playground]")
add_subdirectory(Playground)

message(STATUS "Subdirectory [Vision]")
add_subdirectory(Vision)

message(STATUS "Subdirectory [Model]")
add_subdirectory(Model)

message(STATUS "Subdirectory [Modules]")
# add_subdirectory(Modules) # C++20 Modules Not Supported

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

message(STATUS "Leave Project ${PROJECT_NAME_STR}")
