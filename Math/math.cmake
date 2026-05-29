cmake_minimum_required(VERSION 3.18)

project(Mathlib CXX)

message(STATUS "-> Enter Source mathlib ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}")

set(_Mathlib_SOURCE_DIR_ ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB _MATH_SOURCES_ CONFIGURE_DEPENDS  "${_Mathlib_SOURCE_DIR_}/source/*.cpp")
file(GLOB_RECURSE _MATH_HEADERS_ CONFIGURE_DEPENDS
    "${_Mathlib_SOURCE_DIR_}/include/*.hpp"
    "${_Mathlib_SOURCE_DIR_}/epsilon-math01/*.hpp"
)

# message(STATUS "Mathlib source ${_MATH_SOURCES_}")
# message(STATUS "Mathlib headers ${_MATH_HEADERS_}")

# find spdlog
find_package(spdlog CONFIG REQUIRED)
message(STATUS "Find spdlog ${spdlog_VERSION}  -> ${spdlog_FOUND}")

# message(STATUS ${_MATH_HEADERS_} ${_MATH_SOURCES_})
add_library(Mathlib STATIC ${_MATH_HEADERS_} ${_MATH_SOURCES_})
include_directories(${_Mathlib_SOURCE_DIR_}/include ${_Mathlib_SOURCE_DIR_})
set_target_properties(Mathlib PROPERTIES
    LINKER_LANGUAGE CXX
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
)
target_compile_features(Mathlib PUBLIC cxx_std_23)
target_include_directories(Mathlib PUBLIC
    "${_Mathlib_SOURCE_DIR_}/include"
    "${_Mathlib_SOURCE_DIR_}"
)
target_link_libraries(Mathlib PUBLIC spdlog::spdlog)
install(TARGETS Mathlib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
) #



message(STATUS "<- Exit Source mathlib ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}")
