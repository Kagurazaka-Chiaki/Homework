cmake_minimum_required(VERSION 3.28)

add_executable(pathfinding main.cpp)

if(HOMEWORK_ENABLE_CXX_MODULES)
    add_library(foo)
    target_sources(foo
        PUBLIC
        FILE_SET CXX_MODULES FILES
        foo.cxx
    )
    target_link_libraries(pathfinding PRIVATE foo)
else()
    message(STATUS "Skip C++ modules for pathfinding: HOMEWORK_ENABLE_CXX_MODULES=OFF")
endif()

