

find_package(Vulkan REQUIRED)
message(STATUS "Found Vulkan: ${Vulkan_INCLUDE_DIRS}")

add_library(RenderAPI SHARED
    PlatformBase.hpp
    RenderAPI.hpp
    RenderAPI.cpp
    RenderAPI_Vulkan.cpp
    RenderAPI_Vulkan.hpp

    IUnityGraphicsVulkan.hpp
    IUnityInterface.hpp
)
target_include_directories(RenderAPI PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(RenderAPI PUBLIC cxx_std_20)
target_link_libraries(RenderAPI PUBLIC
    spdlog::spdlog
    Vulkan::Vulkan
)

add_executable(UnityTest main.cpp)
target_link_libraries(UnityTest PRIVATE RenderAPI)
target_include_directories(UnityTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)