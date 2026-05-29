cmake_minimum_required(VERSION 3.31)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/zeta-algo01/CMakeLists.txt")
    add_subdirectory(zeta-algo01)
else()
    message(STATUS "Skip submodule [Algorithm/zeta-algo01]: not initialized")
endif()
