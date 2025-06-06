
#include "RenderAPI.hpp"
#include <spdlog/spdlog.h>
#include <vulkan/vulkan.h>

// This plugin does not link to the Vulkan loader
// easier to support multiple APIs and systems that don't have Vulkan support
#define VK_NO_PROTOTYPES
#include "IUnityGraphicsVulkan.hpp"

class RenderAPI_Vulkan : public RenderAPI {

    IUnityGraphicsVulkan *m_UnityVulkan;
    UnityVulkanInstance   m_Instance;

  public:
    RenderAPI_Vulkan();

    virtual ~RenderAPI_Vulkan() {
        spdlog::info("RenderAPI_Vulkan destructor called");
        // Cleanup if necessary
        // For example, destroy Vulkan resources or unregister callbacks
    }

    // Get Vulkan instance and device
    virtual void *GetVulkanInstance() override {
        // Implementation for getting Vulkan instance
        return nullptr;
    }

    virtual void *GetVulkanDevice() override {
        // Implementation for getting Vulkan device
        return nullptr;
    }

    // Get VRS support
    virtual void *GetVulkanSupportVRS(char *OutResult) override {
        // Implementation for getting Vulkan VRS support
        spdlog::info("GetVulkanSupportVRS called");


        // get the Vulkan support extensions
        // check if VRS is supported

        auto vk_device = m_Instance.device;
        if (vk_device == nullptr) {
            spdlog::error("Vulkan device is null");
            return nullptr;
        }

        auto vk_instance = m_Instance.instance;
        if (vk_instance == nullptr) {
            spdlog::error("Vulkan instance is null");
            return nullptr;
        }

        auto vk_physical_device = m_Instance.physicalDevice;
        if (vk_physical_device == nullptr) {
            spdlog::error("Vulkan physical device is null");
            return nullptr;
        }

        // get all the extensions
        uint32_t extension_count = 0;
        vkEnumerateDeviceExtensionProperties(vk_physical_device, nullptr, &extension_count, nullptr);
        if (extension_count == 0) {
            spdlog::error("No Vulkan extensions found");
            return nullptr;
        }
        // VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME

        if (OutResult) {
            // Fill OutResult with VRS support information
            spdlog::info("VRS support information");
            snprintf(OutResult, 256, "VRS support information");
        }
        return nullptr;
    }
};