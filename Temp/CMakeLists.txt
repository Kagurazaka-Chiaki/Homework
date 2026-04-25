
cmake_minimum_required(VERSION 3.28)

# Definitions
set(PROJECT_NAME_STR "临时项目")

# Project title and define versioning
project("useEigen" VERSION 0.1.0)

message(STATUS "-> Enter Project ${PROJECT_NAME_STR} ${CXX_STANDARD}")

homework_require_eigen3()
homework_require_icu()

add_executable(${PROJECT_NAME} main.cpp)

if(HOMEWORK_ENABLE_CXX_MODULES)
    target_sources(${PROJECT_NAME} PRIVATE FILE_SET CXX_MODULES FILES kemp.ixx)
else()
    message(STATUS "Skip C++ modules for ${PROJECT_NAME}: HOMEWORK_ENABLE_CXX_MODULES=OFF")
endif()


target_link_libraries(${PROJECT_NAME} PRIVATE
    ICU::uc ICU::i18n Eigen3::Eigen
)

if(BUILD_TESTING)
    homework_require_catch2()

    add_executable(test_dummy test_dummy.cpp)
    target_link_libraries(test_dummy PRIVATE Catch2::Catch2WithMain)
    add_test(NAME test_dummy COMMAND test_dummy)

    add_executable(tests test.cpp)
    target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
endif()

message(STATUS "-> Leave Project ${PROJECT_NAME_STR}")

add_executable(obs Observer.cpp)
