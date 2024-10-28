cmake_minimum_required(VERSION 3.28)

add_executable(Vision main.cpp HeightMap.hpp image.hpp vertex.hpp)
target_include_directories(Vision PRIVATE ${Stb_INCLUDE_DIR})
target_link_libraries(Vision PRIVATE spdlog::spdlog_header_only)
target_link_libraries(Vision PRIVATE Mathlib)

# Copy the file to the build directory
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/gale.png ${CMAKE_CURRENT_BINARY_DIR}/gale.png COPYONLY)


add_executable(test_vision test_vision.cpp)
target_link_libraries(test_vision PRIVATE Catch2::Catch2WithMain)
target_link_libraries(test_vision PRIVATE spdlog::spdlog_header_only)
add_test(NAME test_vision COMMAND test_vision)
