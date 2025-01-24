cmake_minimum_required(VERSION 3.28)

add_executable(app_model
    main.cpp

    # Model.cpp
    # Model.h
)
target_link_libraries(app_model PRIVATE assimp::assimp spdlog::spdlog glm::glm)
target_compile_definitions(app_model PRIVATE
    IMGUI_IMPL_OPENGL_ES2
)
