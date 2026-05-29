# C++ Style Policy

本文档定义一个可复用的 C++ 命名与基础风格模板。

核心目标是提升代码阅读时的视觉识别速度：读者应能仅通过标识符形状，快速区分类型、函数、变量、成员变量、常量、枚举值、命名空间、宏和文件。

次要目标是保持和主流 C++ 工程风格的兼容性。本文档采用混合风格，而不是完全复制 STL、Google C++、LLVM、Qt、Unreal Engine 或 Microsoft/Win32 的任意一套规则。

## 1. 命名总览

| 类别 | 风格 | 示例 |
|---|---|---|
| 类型 | `PascalCase` | `RenderGraph`, `VertexBuffer` |
| 函数 | `camelCase` | `addRenderPass`, `compileGraph` |
| 变量 | `snake_case` | `frame_index`, `shader_path` |
| private/protected 成员变量 | `snake_case_` | `frame_index_`, `render_passes_` |
| 编译期语义常量 | `kPascalCase` | `kMaxFramesInFlight` |
| 枚举值 | `PascalCase` | `RenderTarget`, `ShaderRead` |
| 命名空间 | `lowercase` / `snake_case` | `delta::grfx`, `vc::ast` |
| 宏 | `ALL_CAPS` | `DELTA_GRFX_ENABLE_ASSERTS` |
| 文件 | `snake_case.hpp` / `snake_case.cpp` | `render_graph.hpp` |

示例：

```cpp
class RenderGraph {
public:
    void addRenderPass(std::string_view pass_name);

private:
    std::vector<RenderPass> render_passes_;
    int frame_index_ = 0;
};

inline constexpr int kMaxFramesInFlight = 2;
```

这套规则让不同语义类别具有不同的视觉形状：

```text
RenderGraph           类型
addRenderPass         函数
pass_name             局部变量 / 参数
render_passes_        成员变量
kMaxFramesInFlight    编译期语义常量
```

## 2. 类型

所有用户定义类型使用 `PascalCase`。

适用范围：

```text
class
struct
enum class
using alias
concept
描述性 template type parameter
```

推荐：

```cpp
class VertexBuffer;
struct PipelineDesc;
enum class ResourceState;
using ResourceHandle = std::uint32_t;
```

避免：

```cpp
class vertex_buffer;
struct pipeline_desc;
using resource_handle = std::uint32_t;
```

原因：类型应当从变量和函数中明显区分出来。

## 3. 函数

函数和成员函数使用 `camelCase`。

推荐：

```cpp
void compileGraph();
void addRenderPass();
ShaderModule loadShaderModule(std::string_view path);

renderer.drawFrame();
asset_manager.loadTexture(path);
graph.addRenderPass("main");
```

避免：

```cpp
void compile_graph();
void AddRenderPass();

renderer.draw_frame();
graph.AddRenderPass("main");
```

原因：`camelCase` 能让函数和 `snake_case` 变量形成视觉区分，同时仍然常见于 C++ 工程、游戏引擎、GUI 和应用代码。

### Getter 和 Setter

简单访问器优先使用直接名称：

```cpp
int width() const;
int height() const;
std::string_view name() const;
```

修改器使用 `setXxx`：

```cpp
void setWidth(int width);
void setHeight(int height);
```

通常避免 Java 风格的简单 getter：

```cpp
int getWidth() const; // 简单访问器通常不推荐
```

当操作可能失败、通过输出参数返回结果，或表示非平凡获取过程时，可以使用 `getXxx`：

```cpp
bool getShaderModule(ShaderId id, ShaderModule* out_module) const;
```

### 布尔函数

布尔函数使用谓词式命名：

```cpp
bool isValid() const;
bool hasAttachment() const;
bool canCompile() const;
bool shouldCullPass() const;
```

避免含义不明确的命名：

```cpp
bool valid() const;
bool compile() const;
```

## 4. 变量

局部变量、函数参数和非成员变量使用 `snake_case`。

推荐：

```cpp
int frame_index = 0;
std::string shader_path;
auto pass_count = render_passes.size();

void addRenderPass(std::string_view pass_name, ResourceState initial_state);
```

原因：`snake_case` 可读性好，和 STL 风格兼容，也能和 `camelCase` 函数区分。

## 5. 成员变量

private 和 protected 成员变量使用 `snake_case_`。

推荐：

```cpp
class Renderer {
public:
    void drawFrame();

private:
    int frame_index_ = 0;
    Device* device_ = nullptr;
    std::vector<RenderPass> render_passes_;
};
```

不要使用前导下划线：

```cpp
int _frame_index;
int __frame_index;
int _FrameIndex;
```

原因：前导下划线可能触碰 C++ 保留标识符规则。尾随下划线常见、清晰，也较安全。

### public 数据成员

普通数据结构的 public 数据成员使用常规 `snake_case`，不加尾随下划线。

```cpp
struct WindowDesc {
    int width = 1280;
    int height = 720;
    std::string title;
};
```

原因：尾随下划线用于标记类内部拥有和维护的成员状态，不用于 plain data struct 的公开字段。

## 6. 常量

编译期语义常量使用 `kPascalCase`。

推荐：

```cpp
inline constexpr int kMaxFramesInFlight = 2;
inline constexpr int kDefaultWindowWidth = 1280;
inline constexpr std::string_view kDefaultShaderDir = "assets/shaders";
```

避免：

```cpp
inline constexpr int max_frames_in_flight = 2;
inline constexpr int kmax_frames_in_flight = 2;
inline constexpr int kmaxFramesInFlight = 2;
```

正确形式是：

```text
k + PascalCase
```

示例：

```cpp
kMaxFramesInFlight
kInvalidIndex
kDefaultShaderDir
kMaxTextureBindings
```

### 运行期 const 局部变量

普通运行期 `const` 局部变量不要使用 `k` 前缀。

推荐：

```cpp
const auto frame_index = acquireFrameIndex();
const auto shader_path = config.shader_path;
```

避免：

```cpp
const auto kFrameIndex = acquireFrameIndex();
const auto kShaderPath = config.shader_path;
```

原因：`kPascalCase` 表示语义常量，通常是编译期常量或配置级常量。局部 `const` 值只是不可变的局部变量。

### 运行期配置值

运行期配置值使用 `snake_case`。

```cpp
auto max_frames_in_flight = config.max_frames_in_flight;
```

避免：

```cpp
auto kMaxFramesInFlight = config.max_frames_in_flight;
```

## 7. 枚举

`enum class` 名称和枚举值都使用 `PascalCase`。

推荐：

```cpp
enum class ResourceState {
    Undefined,
    RenderTarget,
    ShaderRead,
    CopySrc,
    CopyDst,
};

ResourceState::RenderTarget;
ResourceState::ShaderRead;
```

避免：

```cpp
ResourceState::render_target;
ResourceState::shader_read;
RESOURCE_STATE_RENDER_TARGET;
```

原因：scoped enum 的枚举值类似具名常量，应当和普通变量形成视觉区分。

## 8. 命名空间

命名空间使用小写或短 `snake_case`。

推荐：

```cpp
namespace delta::grfx {
}

namespace lambda::ccmp {
}

namespace vc::ast {
}
```

避免：

```cpp
namespace Delta::Grfx {
}

namespace RenderGraphSystem {
}
```

原因：命名空间是结构层级，不是类型。小写命名空间更接近常见 C++ 生态，也能降低视觉噪音。

## 9. 宏

宏使用 `ALL_CAPS`，并尽量带项目或模块前缀。

推荐：

```cpp
#define DELTA_GRFX_ENABLE_ASSERTS 1
#define LAMBDA_CCMP_DEBUG_TRACE 1
```

宏应保持少量使用。常见用途包括：

```text
条件编译
平台选择
编译器特性检测
include guard
```

不要用宏表示普通常量。

推荐：

```cpp
inline constexpr int kMaxFramesInFlight = 2;
```

避免：

```cpp
#define MAX_FRAMES_IN_FLIGHT 2
```

原因：`ALL_CAPS` 应继续保留为宏的危险信号。

## 10. 文件

文件名使用 `snake_case`。

推荐：

```text
render_graph.hpp
render_graph.cpp
vertex_buffer.hpp
shader_module.cpp
asset_manager.hpp
pipeline_cache.cpp
source_location.hpp
```

避免：

```text
RenderGraph.hpp
VertexBuffer.cpp
assetManager.cpp
```

原因：`snake_case` 文件名在 Windows、Linux、macOS、Git、CMake 和命令行工具中都比较稳定。

## 11. 缩写词

在 `PascalCase` 和 `camelCase` 中，把缩写词当作普通单词处理。

推荐：

```cpp
class HttpClient;
class GpuBuffer;
class AstNode;

void loadHttpRequest();
void createGpuBuffer();
void parseAstNode();
```

避免：

```cpp
class HTTPClient;
class GPUBuffer;
class ASTNode;

void loadHTTPRequest();
void createGPUBuffer();
```

原因：全大写缩写会制造噪音，也容易产生难看的大小写边界。

例外：宏仍然使用 `ALL_CAPS`。

```cpp
#define DELTA_GRFX_USE_GPU_VALIDATION 1
```

## 12. 模板参数

通用模板可以使用短约定名。

```cpp
template <typename T>
class Span;
```

领域相关模板优先使用描述性 `PascalCase` 名称。

```cpp
template <typename ResourceT>
class ResourcePool;

template <typename PassT>
void addPass(PassT&& pass);
```

在复杂模板中避免含义不清的名称：

```cpp
template <typename X, typename Y, typename Z>
```

除非其含义在数学或上下文中非常明确。

## 13. Concepts

Concept 使用 `PascalCase`。

```cpp
template <typename T>
concept RendererBackend = requires(T backend) {
    backend.drawFrame();
};

template <RendererBackend BackendT>
class Renderer;
```

原因：concept 表示类型约束，应在视觉上接近类型。

## 14. 错误和状态类型

错误、状态和结果类型使用 `PascalCase`。

```cpp
enum class ErrorCode {
    None,
    FileNotFound,
    InvalidShader,
};

struct CompileResult {
    bool success = false;
    ErrorCode error = ErrorCode::None;
};
```

持有错误值的变量使用 `snake_case`。

```cpp
auto error_code = compile_result.error;
```

## 15. 完整示例

```cpp
#ifndef DELTA_GRFX_RENDER_GRAPH_HPP
#define DELTA_GRFX_RENDER_GRAPH_HPP

#include <string_view>
#include <vector>

namespace delta::grfx {

inline constexpr int kMaxFramesInFlight = 2;
inline constexpr std::string_view kDefaultShaderDir = "assets/shaders";

enum class ResourceState {
    Undefined,
    RenderTarget,
    ShaderRead,
    CopySrc,
    CopyDst,
};

struct RenderPassDesc {
    std::string_view name;
    ResourceState initial_state = ResourceState::Undefined;
};

class RenderGraph {
public:
    void addRenderPass(RenderPassDesc desc);
    void compileGraph();

    int passCount() const;

private:
    std::vector<RenderPassDesc> render_passes_;
    int frame_index_ = 0;
};

} // namespace delta::grfx

#endif // DELTA_GRFX_RENDER_GRAPH_HPP
```

## 16. 非目标

本文档不试图完全模仿以下任意风格：

```text
STL
LLVM
Google C++
Qt
Unreal Engine
Chromium
Microsoft / Win32
```

本文档选择的是一套混合风格，主要优化：

```text
视觉识别速度
个人长期维护
C++ 生态兼容性
跨平台工具稳定性
engine / compiler / algorithm 项目的阅读体验
```

## 17. 总结

可以用以下规则快速记忆：

```text
Types are nouns with PascalCase.
Functions are actions with camelCase.
Variables are data with snake_case.
Members are owned state with snake_case_.
Constants are semantic constants with kPascalCase.
Macros are loud because macros are dangerous.
Files are snake_case for tooling stability.
```
