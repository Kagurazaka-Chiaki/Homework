cmake_minimum_required(VERSION 3.25)

homework_require_eigen3()
homework_require_icu()
homework_require_spdlog()

add_executable(local main.cpp Localize.hpp)
target_link_libraries(local PRIVATE ICU::uc ICU::i18n Eigen3::Eigen)

set(SPDLOG_DIR spdlog/include)

message(STATUS "Subdirectory [Coroutine]")
add_subdirectory(Coroutine)

message(STATUS "Subdirectory [RTTI]")
add_subdirectory(RTTI)

message(STATUS "Subdirectory [Atomic]")
add_subdirectory(Atomic)

message(STATUS "Subdirectory [Macro]")
add_subdirectory(Macro)
