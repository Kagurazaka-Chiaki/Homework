cmake_minimum_required(VERSION 3.18)

message(STATUS "---------- Enter Test ${PROJECT_NAME_STR}")

include(CTest)

# Project settings
set(PROJECT_UNIT_TESTS_NAME CodingCPP_Unit_Tests)

# Dependencies
find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

# Gather the header and source files
file(GLOB UNIT_TESTS_INC_FILES ${PROJECT_SOURCE_DIR}/test/*.hpp)
file(GLOB UNIT_TESTS_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

# Include paths
set(UNIT_TESTS_INCLUDES ${PROJECT_INCLUDE_DIR}
       ${PROJECT_SOURCE_DIR}/src
       ${Boost_INCLUDE_DIR}
)

# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${UNIT_TESTS_INCLUDES})

# Build unit tests
add_definitions(-DBOOST_TEST_DYN_LINK)
add_executable(${PROJECT_UNIT_TESTS_NAME} ${UNIT_TESTS_SRC_FILES} ${SRC_FILES})
target_link_libraries(${PROJECT_UNIT_TESTS_NAME} ${Boost_LIBRARIES})

enable_testing()

add_test(test_09 ${PROJECT_UNIT_TESTS_NAME})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

message(STATUS "---------- Leave Test ${PROJECT_NAME_STR}")