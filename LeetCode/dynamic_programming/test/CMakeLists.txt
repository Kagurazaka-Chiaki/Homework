
message(STATUS "-> Enter Test ${PROJECT_NAME_STR}")

# message(STATUS ${CMAKE_CURRENT_BINARY_DIR})

# get_filename_component(CMAKE_CURRENT_BINARY_PARENT_DIR ${CMAKE_CURRENT_BINARY_DIR} DIRECTORY)

# message(STATUS ${CMAKE_CURRENT_BINARY_PARENT_DIR})

# install(FILES $<TARGET_LINKER_FILE:dp> DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Build tests
file(GLOB SINGLE_CPP_TEST_LIST ${TEST_DIR}/*.cpp)
foreach(TEST_SRC_PATH ${SINGLE_CPP_TEST_LIST})

    string(REGEX MATCH "test_[0-9]+.cpp" file_name ${TEST_SRC_PATH})
    string(REGEX MATCH "test_[0-9]+" target_name ${TEST_SRC_PATH})

    # message(STATUS "-- -> Add Executable ${target_name} ${file_name}")
    add_executable(${target_name} ${file_name})
    # set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PARENT_DIR})

    target_link_libraries(${target_name} PRIVATE Catch2::Catch2WithMain)

    target_link_libraries(${target_name} PRIVATE dp)

    # CMake 3.21
    # On non-DLL platforms, this expression always evaluates to an empty string.
    add_custom_command(TARGET ${target_name} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:${target_name}> $<TARGET_RUNTIME_DLLS:${target_name}>
        COMMAND_EXPAND_LISTS
    )

    add_test("${target_name}" ${target_name}) # WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_PARENT_DIR})

    message(STATUS "-- -> Add Test ${target_name}")

endforeach(TEST_SRC_PATH ${SINGLE_CPP_TEST_LIST})

message(STATUS "-> Leave Test ${PROJECT_NAME_STR}")
