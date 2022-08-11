
message(STATUS "-> Enter Source ${PROJECT_NAME_STR}")

# file(GLOB SINGLE_CPP_SRC_LIST ${SOURCE_DIR}/*.cpp)
# foreach(SRC_PATH ${SINGLE_CPP_SRC_LIST})
#     string(REGEX MATCH "[0-9]+.cpp" file_name ${SRC_PATH})
#     string(REGEX MATCH "[0-9]+" target_name ${SRC_PATH})
#     # add_executable(${target_name})
#     target_include_directories(${target_name} PUBLIC include)
#     target_sources(
#         ${target_name}
#         ${target}
#         PRIVATE
#         src/${file_name}
#         include/dplib/solution.hpp
#     )
# endforeach(SRC_PATH ${SINGLE_CPP_SRC_LIST})

message(STATUS "-- -> Add Executable main")
add_executable(dp_main main.cpp)
target_link_libraries(dp_main PUBLIC DP)


message(STATUS "-> Leave Source ${PROJECT_NAME_STR}")