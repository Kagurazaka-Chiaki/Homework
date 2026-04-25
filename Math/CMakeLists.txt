cmake_minimum_required(VERSION 3.28)

message(STATUS "Subdirectory [Libraries/math]")
if(NOT TARGET Mathlib)
    include(math.cmake)
    set_target_properties(Mathlib PROPERTIES FOLDER Math)
    if(BUILD_TESTING)
        add_subdirectory(test)
    endif()
endif()

add_executable(TryMath main.cpp)
target_link_libraries(TryMath PRIVATE Mathlib)
