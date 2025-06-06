
#include "RenderAPI_Vulkan.hpp"
#include <spdlog/spdlog.h>

RenderAPI *CreateRenderAPI_Vulkan() {
    return new RenderAPI_Vulkan();
}

RenderAPI_Vulkan::RenderAPI_Vulkan() {
    // Constructor implementation
    spdlog::info("RenderAPI_Vulkan constructor called");
}

