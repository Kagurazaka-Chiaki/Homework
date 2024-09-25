cmake_minimum_required(VERSION 3.18)

project(Mathlib CXX)

message(STATUS "-> Enter Source mathlib ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}")

set(_Mathlib_SOURCE_DIR_ ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB _MATH_SOURCES_ CONFIGURE_DEPENDS  "${_Mathlib_SOURCE_DIR_}/source/*.cpp")
file(GLOB _MATH_HEADERS_ CONFIGURE_DEPENDS  "${_Mathlib_SOURCE_DIR_}/include/*.hpp")

# message(STATUS "Mathlib source ${_MATH_SOURCES_}")
# message(STATUS "Mathlib headers ${_MATH_HEADERS_}")

# find spdlog
find_package(spdlog REQUIRED)
message(STATUS "Find spdlog ${spdlog_VERSION}  -> ${spdlog_FOUND}")
set(spdlog_INCLUDE_DIRS ${spdlog_INCLUDE_DIR})
include_directories(${spdlog_INCLUDE_DIR})

# message(STATUS ${_MATH_HEADERS_} ${_MATH_SOURCES_})
add_library(Mathlib STATIC ${_MATH_HEADERS_} ${_MATH_SOURCES_})
# target_link_libraries(Mathlib PUBLIC spdlog::spdlog)
include_directories(${_Mathlib_SOURCE_DIR_}/include)
set_target_properties(Mathlib PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(Mathlib PUBLIC "${_Mathlib_SOURCE_DIR_}/include")
install(TARGETS Mathlib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
) #



message(STATUS "<- Exit Source mathlib ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}")
