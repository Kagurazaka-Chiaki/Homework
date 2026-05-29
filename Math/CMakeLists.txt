cmake_minimum_required(VERSION 3.28)

message(STATUS "Subdirectory [Libraries/math]")
if(NOT TARGET Mathlib)
    include(math.cmake)
    set_target_properties(Mathlib PROPERTIES FOLDER Math)
endif()

if(BUILD_TESTING AND NOT TARGET epsilon_math_tests)
    add_subdirectory(test)
endif()

add_executable(TryMath main.cpp)
set_target_properties(TryMath PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
)
target_link_libraries(TryMath PRIVATE Mathlib)
