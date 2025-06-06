cmake_minimum_required(VERSION 3.25)

# # Eigen
# find_package(Eigen3 CONFIG REQUIRED)
# include_directories(${EIGEN3_INCLUDE_DIRS})

# Catch2 v3
find_package(Catch2 CONFIG REQUIRED)
message(STATUS "Find Catch2 ${Catch2_VERSION} -> ${Catch2_FOUND}")

find_package(ICU REQUIRED COMPONENTS uc i18n)
message(STATUS "Find ICU ${ICU_VERSION} -> ${ICU_FOUND}")

add_executable(local main.cpp Localize.hpp)
target_link_libraries(local PRIVATE ICU::uc ICU::i18n Eigen3::Eigen)

set(SPDLOG_DIR spdlog/include)

# Stand-alone build
find_package(spdlog REQUIRED)
message(STATUS "Find spdlog ${spdlog_VERSION}  -> ${spdlog_FOUND}")

set(spdlog_INCLUDE_DIRS ${spdlog_INCLUDE_DIR})

include_directories(${spdlog_INCLUDE_DIR})

message(STATUS "Subdirectory [Coroutine]")
add_subdirectory(Coroutine)

message(STATUS "Subdirectory [RTTI]")
add_subdirectory(RTTI)

message(STATUS "Subdirectory [Atomic]")
add_subdirectory(Atomic)

message(STATUS "Subdirectory [Macro]")
add_subdirectory(Macro)
