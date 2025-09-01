cmake_minimum_required(VERSION 3.28)

message(STATUS "-> Enter [BISHI]")

file(GLOB SINGLE_CPP_LIST "*.cpp")
foreach(SINGLE_CPP ${SINGLE_CPP_LIST})
    get_filename_component(SINGLE_CPP_NAME ${SINGLE_CPP} NAME_WE)
    add_executable(${SINGLE_CPP_NAME} ${SINGLE_CPP})
endforeach()
