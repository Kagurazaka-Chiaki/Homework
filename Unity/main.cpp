
/**
 *
**/


#include <cstring>
#include <iostream>

#include "RenderAPI.hpp"

auto ShowBuffer(char *buffer, size_t size, int line_length = 16) -> bool {
    // if (buffer == nullptr || size == 0) {
    //     std::cout << "Buffer is empty or null." << std::endl;
    //     return false;
    // }
    // std::cout << "Buffer contents: " << std::endl;

    for (size_t i = 0; i < size; ++i) {
        std::cout << '[' << i << "] " << std::hex << static_cast<int>(buffer[i]) << ' ';
    }
    std::cout << std::endl;
    return true;
}

auto main(int argc, char const *argv[]) -> int {
    (void) argc; (void) argv;
    /* code */
    std::cout << "Hello, 世界! \xF0\x9F\x98\x89 \n" << std::endl;


    auto render_api = CreateRenderAPI(UnityGfxRenderer::kUnityGfxRendererVulkan);
    if (render_api == nullptr) {
        std::cerr << "Failed to create RenderAPI instance." << std::endl;
        return -1;
    }

    // // char vrs_support[256] = {0};
    char *vrs_support = new char[256];
    if (vrs_support == nullptr) {
        std::cerr << "Failed to allocate memory for VRS support." << std::endl;
        return -1;
    }
    std::memset(vrs_support, '\0', 256);
    render_api->GetVulkanSupportVRS(vrs_support);
    std::cout << "Vulkan Support VRS: " << vrs_support << std::endl;

    // char *output = new char[256];
    // strcpy_s(output, 256, vrs_support);

    delete[] vrs_support;
    // std::cout << "Output: " << output << std::endl;

    // delete[] output;
    return 0;
}
