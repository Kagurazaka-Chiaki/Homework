
include_guard(GLOBAL)

include("${CMAKE_CURRENT_LIST_DIR}/function.cmake")

if(NOT DEFINED HOMEWORK_THIRD_PARTY_DIR)
    get_filename_component(
        HOMEWORK_THIRD_PARTY_DIR
        "${CMAKE_CURRENT_LIST_DIR}/../ThirdParty"
        ABSOLUTE
    )
endif()

include("${CMAKE_CURRENT_LIST_DIR}/glm.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/stb.cmake")

homework_setup_glm()
homework_setup_stb()

macro(homework_require_eigen3)
    if(NOT TARGET Eigen3::Eigen)
        find_package(Eigen3 CONFIG REQUIRED)
        message(STATUS "Find Eigen3 ${Eigen3_VERSION} -> ${Eigen3_FOUND}")
    endif()
endmacro()

macro(homework_require_catch2)
    if(NOT TARGET Catch2::Catch2WithMain)
        find_package(Catch2 CONFIG REQUIRED)
        message(STATUS "Find Catch2 ${Catch2_VERSION} -> ${Catch2_FOUND}")
    endif()
endmacro()

macro(homework_require_spdlog)
    if(NOT TARGET spdlog::spdlog)
        find_package(spdlog CONFIG REQUIRED)
        message(STATUS "Find spdlog ${spdlog_VERSION} -> ${spdlog_FOUND}")
    endif()
endmacro()

macro(homework_require_icu)
    if(NOT TARGET ICU::uc OR NOT TARGET ICU::i18n)
        find_package(ICU COMPONENTS uc i18n REQUIRED)
        message(STATUS "Find ICU ${ICU_VERSION} -> ${ICU_FOUND}")
    endif()
endmacro()

macro(homework_require_assimp)
    if(NOT TARGET assimp::assimp)
        find_package(assimp CONFIG REQUIRED)
        message(STATUS "Found assimp: ${assimp_FOUND}")
    endif()
endmacro()

