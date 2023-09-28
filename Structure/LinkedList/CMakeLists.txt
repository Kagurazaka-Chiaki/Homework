#

# Definitions
set(PROJECT_NAME_STR LinkedList)

message(STATUS "-> Enter Project ${PROJECT_NAME_STR}")

add_single_hpp_lib(lib_linkedlist LinkedList.hpp)
target_link_libraries(lib_linkedlist INTERFACE lib_node)

add_executable(test_linkedlist LinkedList.cpp)
target_link_libraries(test_linkedlist PUBLIC lib_linkedlist)

message(STATUS "-> Leave Project ${PROJECT_NAME_STR}")
