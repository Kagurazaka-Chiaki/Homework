cmake_minimum_required(VERSION 3.18)

# Definitions
set(PROJECT_NAME_STR CodingCPP)

# Project title and define versioning
project(${PROJECT_NAME_STR} VERSION 0.1.0)

message(STATUS "")
message(STATUS "---------- Enter Project ${PROJECT_NAME_STR}")

# include(CTest)
# enable_testing()

## Include paths
#set(DEMO_INCLUDES ${DEMO_INCLUDES} ${PROJECT_SOURCE_DIR}/src)
#set(DEMO_INCLUDES ${DEMO_INCLUDES} ${PROJECT_SOURCE_DIR}/include)

# Dependencies
# find_package(Boost REQUIRED [COMPONENTS <libs>...])
# target_link_libraries(main PRIVATE Boost::boost Boost::<lib1> Boost::<lib2> ...)

if (UNIX)
    message(STATUS "Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lboost_filesystem -lboost_system -lboost_unit_test_framework")
else (WIN32)
    message(STATUS "Windows")
endif ()


find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

message("[find] ${Boost_LIBRARIES}")

# Unit tests
message("[test] Unit tests")
add_subdirectory(test)

# Gather all sources except the main entry point
#file(GLOB_RECURSE INC_FILES src/*/*.hpp)
#file(GLOB_RECURSE SRC_FILES src/*/*.cpp)

# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS})

# Build
#set(SOURCE_FILES src/main.cpp $<TARGET_OBJECTS:demo_objects>)
#set(SOURCE_FILES src/main.cpp ${INC_FILES} ${SRC_FILES})
#add_executable(CodingCPP ${SOURCE_FILES})
# add_executable(CodingCPP_test src/example.cpp)
#target_link_libraries(CodingCPP ${Boost_LIBRARIES})

add_executable(09 src/09.cpp)
add_executable(30 src/30.cpp)

add_executable(06 src/06.cpp)
add_executable(24 src/24.cpp)
add_executable(35 src/35.cpp)

add_executable(05 src/05.cpp)

# message("${Boost_INCLUDE_DIRS}")
# message("${Boost_LIBRARIES}")

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

message(STATUS "---------- Leave Project ${PROJECT_NAME_STR}")
message(STATUS "")
