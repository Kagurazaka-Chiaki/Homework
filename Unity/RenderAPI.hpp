
#include "IUnityGraphics.hpp"

#include "spdlog/spdlog.h"
// Super-simple "graphics abstraction". This is nothing like how a proper platform abstraction layer would look like;
// all this does is a base interface for whatever our plugin sample needs. Which is only "draw some triangles"
// and "modify a texture" at this point.
//
// There are implementations of this base class for D3D9, D3D11, OpenGL etc.; see individual RenderAPI_* files.
class RenderAPI {
  public:
    virtual ~RenderAPI() {
        spdlog::info("RenderAPI destructor called");
        // Cleanup if necessary
        // For example, destroy graphics resources or unregister callbacks
    }

    // Get Vulkan instance and device
    virtual void *GetVulkanInstance() { return nullptr; }

    virtual void *GetVulkanDevice() { return nullptr; }

    // Get VRS support
    virtual void *GetVulkanSupportVRS(char *OutResult) { return nullptr; }
};

// Create a graphics API implementation instance for the given API type.
RenderAPI* CreateRenderAPI(UnityGfxRenderer apiType);
