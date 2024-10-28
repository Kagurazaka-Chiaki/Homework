cmake_minimum_required(VERSION ${CMAKE_VERSION})

message(STATUS "Enter LeetCode [Workspace] ${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB SINGLE_CPP_SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB SINGLE_HPP_SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

# message(STATUS "Single Source List: ${SINGLE_CPP_SRC_LIST}")
# message(STATUS "Single Header List: ${SINGLE_HPP_SRC_LIST}")

add_library(leetcode_lib STATIC ${SINGLE_HPP_SRC_LIST})
target_include_directories(leetcode_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(leetcode_lib PROPERTIES LINKER_LANGUAGE CXX)

foreach(SINGLE_CPP_SRC ${SINGLE_CPP_SRC_LIST})
    get_filename_component(SINGLE_CPP_SRC_NAME ${SINGLE_CPP_SRC} NAME)
    string(REPLACE ".cpp" "" SINGLE_EXEC_NAME ${SINGLE_CPP_SRC_NAME})
    message(STATUS "Single Executable: ${SINGLE_EXEC_NAME} ${SINGLE_CPP_SRC}")

    # 正则表达式获取序号，如 001.two_sum.cpp -> 0001.exe
    string(REGEX MATCH "([0-9]+)" SINGLE_EXEC_NUM ${SINGLE_EXEC_NAME})

    # 添加前导 0
    string(LENGTH ${SINGLE_EXEC_NUM} SINGLE_EXEC_NUM_LEN)
    math(EXPR SINGLE_EXEC_NUM_LEN "${SINGLE_EXEC_NUM_LEN} - 1")
    if(SINGLE_EXEC_NUM_LEN EQUAL 2)
        set(SINGLE_EXEC_NUM "0${SINGLE_EXEC_NUM}")
        math(EXPR SINGLE_EXEC_NUM_LEN "${SINGLE_EXEC_NUM_LEN} + 1")
    endif()
    if(SINGLE_EXEC_NUM_LEN EQUAL 1)
        set(SINGLE_EXEC_NUM "00${SINGLE_EXEC_NUM}")
        math(EXPR SINGLE_EXEC_NUM_LEN "${SINGLE_EXEC_NUM_LEN} + 1")
    endif()

    message(STATUS "Single Executable Number: ${SINGLE_EXEC_NUM}")

    add_executable(${SINGLE_EXEC_NUM} ${SINGLE_CPP_SRC})
    target_link_libraries(${SINGLE_EXEC_NUM} PRIVATE leetcode_lib)
endforeach()

message(STATUS "Leave LeetCode [Workspace] ${CMAKE_CURRENT_SOURCE_DIR}")
