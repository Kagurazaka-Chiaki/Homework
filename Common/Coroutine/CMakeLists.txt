cmake_minimum_required(VERSION 3.28)


project(minicoro LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
# set(CMAKE_CXX_EXTENSIONS      OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


set(CMAKE_BUILD_TYPE DEBUG)

# CTEST_TARGETS_ADDED 1
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)


add_executable(app_minicoro
    main.cpp
    minicoro.hpp
)
target_link_libraries(app_minicoro PRIVATE spdlog::spdlog_header_only)
target_link_libraries(app_minicoro PRIVATE msft_proxy)


if(BUILD_TESTING)
    homework_require_catch2()

    add_executable(test_minicoro
        test_minicoro.cpp
        minicoro.hpp
    )
    add_test("test_minicoro" test_minicoro)
    target_link_libraries(test_minicoro PRIVATE Catch2::Catch2WithMain)
endif()

