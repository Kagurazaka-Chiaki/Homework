cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS Off)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

# SET(CMAKE_BUILE_TYPE DEBUG)

if (UNIX)
    message(STATUS "Linux/Unix")
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++ -Wunused-command-line-argument")
elseif (WIN32)
    message(STATUS "Windows")
    if (MSVC)
        message(STATUS "MSVC")
        # 设置 msvc 输入代码编码格式为 utf-8
        set(CMAKE_C_FLAGS /source-charset:utf-8)
        set(CMAKE_CXX_FLAGS /source-charset:utf-8)
    elseif (MINGW)
        message(STATUS "MINGW")
        # CMAKE_TOOLCHAIN_FILE
    endif ()
endif ()


# Definitions
set(PROJECT_NAME_STR HomeWork)

# Project title and define versioning
project(${PROJECT_NAME_STR} VERSION 0.1.0)

MESSAGE(STATUS "Operation system is ${CMAKE_SYSTEM}")

# CTEST_TARGETS_ADDED 1
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

MESSAGE(STATUS "Enable testing ${CMAKE_SYSTEM}")

enable_testing()
include(CTest)

# Dependencies
# Eigen
find_package(Eigen3 CONFIG REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})
message(STATUS "Find Eigen3  -> ${Eigen3_FOUND}")

# Catch2
find_package(Catch2 CONFIG REQUIRED)
message(STATUS "Find Catch2  -> ${Catch2_FOUND}")
# These tests can use the Catch2-provided main
# add_executable(tests test.cpp)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# OpenGL
find_package(glad CONFIG REQUIRED)
message(STATUS "Find glad    -> ${glad_FOUND}")
# target_link_libraries(main PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
message(STATUS "Find glfw3   -> ${glfw3_FOUND}")
# target_link_libraries(main PRIVATE glfw)

find_package(glm CONFIG REQUIRED)
message(STATUS "Find glm     -> ${glm_FOUND}")
# target_link_libraries(main PRIVATE glm::glm)

find_path(STB_INCLUDE_DIRS "stb_c_lexer.h")
message(STATUS "Find stb     -> 1")
# find_path(STB_INCLUDE_DIRS "stb_c_lexer.h")
# target_include_directories(main PRIVATE ${STB_INCLUDE_DIRS})

find_package(tinyobjloader CONFIG REQUIRED)
message(STATUS "Find tinyobjloader -> ${tinyobjloader_FOUND}")
# target_link_libraries(main PRIVATE tinyobjloader::tinyobjloader)

# Enter Project
message(STATUS "Enter Project ${PROJECT_NAME_STR}")
# add_library(Homework Homework.cpp)

message(STATUS "Subdirectory [LeetCode]")
add_subdirectory(LeetCode)

message(STATUS "Subdirectory [Temp]")
# add_subdirectory(Temp)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

message(STATUS "Leave Project ${PROJECT_NAME_STR}")
