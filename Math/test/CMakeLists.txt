cmake_minimum_required(VERSION 3.18)

message(STATUS "-> Enter Test ${PROJECT_NAME_STR}")

homework_require_catch2()

add_executable(test_basic test_basic.cpp)
set_target_properties(test_basic PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
)
target_link_libraries(test_basic PRIVATE Mathlib Catch2::Catch2WithMain)
add_test(NAME test_basic COMMAND test_basic)

add_executable(test_geometry test_geometry.cpp)
set_target_properties(test_geometry PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
)
target_link_libraries(test_geometry PRIVATE Mathlib Catch2::Catch2WithMain)
add_test(NAME test_geometry COMMAND test_geometry)

add_executable(epsilon_math_tests
    axis_tests.cpp
    complex_tests.cpp
    mat_tests.cpp
    mat2_tests.cpp
    mat3_tests.cpp
    mat4_tests.cpp
    quat_tests.cpp
    scalar_tests.cpp
    se3_tests.cpp
    so3_tests.cpp
    vec_tests.cpp
    vec2_tests.cpp
    vec3_tests.cpp
    vec3_ops_tests.cpp
    vec4_tests.cpp
    vec_n_tests.cpp
)
set_target_properties(epsilon_math_tests PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
)
target_link_libraries(epsilon_math_tests PRIVATE Mathlib Catch2::Catch2WithMain)
add_test(NAME epsilon_math_tests COMMAND epsilon_math_tests)

message(STATUS "-> Leave Test ${PROJECT_NAME_STR}")
