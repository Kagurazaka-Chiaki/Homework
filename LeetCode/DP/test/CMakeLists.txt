
message(STATUS "-> Enter Test ${PROJECT_NAME_STR}")

# Build tests
file(GLOB SINGLE_CPP_TEST_LIST ${TEST_DIR}/*.cpp)
foreach(TEST_SRC_PATH ${SINGLE_CPP_TEST_LIST})
    string(REGEX MATCH "test_[0-9]+.cpp" file_name ${TEST_SRC_PATH})
    string(REGEX MATCH "test_[0-9]+" target_name ${TEST_SRC_PATH})
    message(STATUS "-- -> Add Executable ${target_name} ${file_name}")
    add_executable(${target_name} ${file_name})
    target_link_libraries(${target_name} PRIVATE Catch2::Catch2WithMain DP)
    add_test("test.${target_name}" ${target_name})
endforeach(TEST_SRC_PATH ${SINGLE_CPP_TEST_LIST})

message(STATUS "-> Leave Test ${PROJECT_NAME_STR}")
