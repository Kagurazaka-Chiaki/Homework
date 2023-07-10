cmake_minimum_required(VERSION 3.18)

project(Mathlib CXX)

message(STATUS "-> Enter Source mathlib ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}")

set(_Mathlib_SOURCE_DIR_ ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB _MATH_SOURCES_ CONFIGURE_DEPENDS  "${_Mathlib_SOURCE_DIR_}/src/*.cpp")
file(GLOB _MATH_HEADERS_ CONFIGURE_DEPENDS  "${_Mathlib_SOURCE_DIR_}/include/*.hpp")

# find spdlog
find_package(spdlog REQUIRED)
message(STATUS "Find spdlog ${spdlog_VERSION}  -> ${spdlog_FOUND}")
set(spdlog_INCLUDE_DIRS ${spdlog_INCLUDE_DIR})
include_directories(${spdlog_INCLUDE_DIR})

message(STATUS ${_MATH_HEADERS_} ${_MATH_SOURCES_})
add_library(Mathlib SHARED ${_MATH_HEADERS_})
target_link_libraries(Mathlib PUBLIC spdlog::spdlog)
target_include_directories(Mathlib PUBLIC "${_Mathlib_SOURCE_DIR_}/include")
set_target_properties(Mathlib PROPERTIES LINKER_LANGUAGE CXX)

message(STATUS "<- Exit Source mathlib ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}")
