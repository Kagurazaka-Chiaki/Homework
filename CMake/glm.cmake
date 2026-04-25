include_guard(GLOBAL)

function(homework_setup_glm)
    if(TARGET glm::glm)
        return()
    endif()

    if(EXISTS "${HOMEWORK_THIRD_PARTY_DIR}/glm/CMakeLists.txt")
        set(GLM_BUILD_TESTS OFF CACHE BOOL "Disable GLM tests in HomeWork" FORCE)
        set(GLM_BUILD_INSTALL OFF CACHE BOOL "Disable GLM install in HomeWork" FORCE)
        add_subdirectory(
            "${HOMEWORK_THIRD_PARTY_DIR}/glm"
            "${CMAKE_BINARY_DIR}/ThirdParty/glm"
            EXCLUDE_FROM_ALL
        )
        message(STATUS "Use vendored glm -> ${HOMEWORK_THIRD_PARTY_DIR}/glm")
    endif()
endfunction()

macro(homework_require_glm)
    homework_setup_glm()
    if(NOT TARGET glm::glm)
        message(FATAL_ERROR "glm is missing. Run: git submodule update --init --recursive ThirdParty/glm")
    else()
        message(STATUS "Find glm target -> ${HOMEWORK_THIRD_PARTY_DIR}/glm")
    endif()
endmacro()
