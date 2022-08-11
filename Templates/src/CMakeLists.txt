

message(STATUS "-> Enter Source ${PROJECT_NAME_STR}")

message(STATUS "-- -> Add Executable main")
add_executable(template_main main.cpp)
target_link_libraries(template_main PUBLIC Template)


message(STATUS "-> Leave Source ${PROJECT_NAME_STR}")
