cmake_minimum_required(VERSION 3.28)

# Create a library
add_library(foo)
# Add the module file to the library
target_sources(foo
    PUBLIC
    FILE_SET CXX_MODULES FILES
    foo.cxx
)

add_executable(pathfinding main.cpp)
target_link_libraries(pathfinding PRIVATE foo)

