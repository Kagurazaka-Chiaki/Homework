cmake_minimum_required(VERSION 3.18)

# Definitions
set(PROJECT_NAME_STR Offer)

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


if (MSVC)
    # 设置 msvc 输入代码编码格式为 utf-8
    set(CMAKE_C_FLAGS /source-charset:utf-8)
endif()

find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

message(STATUS "[find] ${Boost_LIBRARIES}")

# Build
message(STATUS "Building ...")
file(GLOB SINGLE_CPP_SRC_LIST src/*.cpp)
foreach(SRC_PATH ${SINGLE_CPP_SRC_LIST})
    string(REGEX MATCH "[0-9]+.cpp" file_name ${SRC_PATH})
    string(REGEX MATCH "[0-9]+" target_name ${SRC_PATH})
    message(STATUS "Add Executable ${file_name}")
    add_executable(${target_name} src/${file_name})
endforeach(SRC_PATH ${SINGLE_CPP_SRC_LIST})


# Unit tests
message(STATUS "[test] Unit tests")
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


# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

message(STATUS "---------- Leave Project ${PROJECT_NAME_STR}")
message(STATUS "")
