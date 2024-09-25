cmake_minimum_required(VERSION 3.25)

# Definitions
set(PROJECT_NAME_STR "Common")

# Project title and define versioning
project(${PROJECT_NAME_STR} VERSION 0.1.0)

message(STATUS "-> Enter Project ${PROJECT_NAME_STR} ${CXX_STANDARD}")

# # Eigen
# find_package(Eigen3 CONFIG REQUIRED)
# include_directories(${EIGEN3_INCLUDE_DIRS})

# Catch2 v3
find_package(Catch2 CONFIG REQUIRED)
message(STATUS "Find Catch2 ${Catch2_VERSION} -> ${Catch2_FOUND}")

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ICU::uc ICU::i18n Eigen3::Eigen)

set(SPDLOG_DIR spdlog/include)

# Stand-alone build
find_package(spdlog REQUIRED)
message(STATUS "Find spdlog ${spdlog_VERSION}  -> ${spdlog_FOUND}")

set(spdlog_INCLUDE_DIRS ${spdlog_INCLUDE_DIR})

include_directories(${spdlog_INCLUDE_DIR})

add_subdirectory(Coroutine)
message(STATUS "Subdirectory [Coroutine]")

add_subdirectory(RTTI)
