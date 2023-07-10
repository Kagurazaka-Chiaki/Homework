cmake_minimum_required(VERSION 3.18)

message(STATUS "Subdirectory [Libraries/math]")
if(NOT TARGET Mathlib)
    include(math.cmake)
    set_target_properties(Mathlib PROPERTIES FOLDER Math)
    add_subdirectory(test)
endif()
