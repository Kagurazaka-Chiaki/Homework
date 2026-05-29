# C++ Style Explanation

本文档说明当前个人 C++ 风格选择的理由。它不是对其他风格的否定，而是解释为什么在个人项目中采用这套命名策略。

## 1. 郑重声明

我个人认为，仅通过代码风格来批判一个人的价值并不合理。尤其是因为 `East Const` 还是 `West Const` 这类选择就对人进行否定，更没有必要。

但在一个项目中保持相对统一的风格仍然有价值，所以这里把个人项目的风格写清楚，以免产生误解。

本文档只说明我个人项目中的偏好；在其他项目、团队或组织中，应优先服从所在项目的既有规范和安排。

## 2. 当前方案的定位

当前风格可以概括为：

```text
Types:        PascalCase
Functions:    camelCase
Variables:    snake_case
Members:      snake_case_
Constants:    kPascalCase
Enum values:  PascalCase
Namespaces:   lowercase / snake_case
Macros:       ALL_CAPS
Files:        snake_case.hpp / snake_case.cpp
```

这是一套视觉分层型混合风格。它的核心目标不是追求某个组织规范的纯粹一致，而是：

```text
视觉识别速度
个人 C++ 工程长期维护
主流 C++ 工程风格兼容性
```

核心假设是：

```text
不同语义类别，应当有不同视觉形状。
```

例如：

```cpp
RenderGraph           // 类型
addRenderPass         // 函数
render_pass           // 变量
render_pass_          // 成员变量
kMaxFramesInFlight    // 常量
RENDER_DEBUG          // 宏
```

这种风格不是最纯的，但扫描速度很快。

## 3. 为什么不是单一纯风格

纯风格主要优化一致性。当前方案主要优化阅读时的语义分层。

纯 `snake_case` 示例：

```cpp
render_graph graph;
graph.add_render_pass(render_pass);
auto max_frames_in_flight = get_max_frames_in_flight();
```

它很统一，但读者需要更多依赖上下文判断：

```text
render_graph 是类型还是变量？
max_frames_in_flight 是常量还是变量？
```

当前混合风格示例：

```cpp
RenderGraph graph;
graph.addRenderPass(render_pass);
auto clamped = std::min(frame_count, kMaxFramesInFlight);
```

视觉上可以更快区分：

```text
RenderGraph           type
addRenderPass         function
render_pass           variable
kMaxFramesInFlight    constant
```

因此，这套规则真正追求的是：

```text
我不追求某个组织的纯风格。
我追求 C++ 代码在阅读时的语义分层。
```

## 4. 其他风格的价值

不同风格服务于不同目标。以下比较只用于说明取舍，不表示其他风格低劣。

| 风格 | 主要价值 | 代价 |
|---|---|---|
| STL `snake_case` | 标准库一致、朴素、适合算法和库代码 | 类型、函数、变量的视觉分层弱 |
| Google-like | 工程可读性强，常量识别快 | 混合风格，不够纯粹 |
| LLVM-like | 编译器和工具链工程成熟，短名高效 | 历史包袱较重，缩写多 |
| Unreal-like | 引擎反射和类型类别识别极强 | 前缀体系侵入性强，离开 Unreal 后显重 |
| Qt-like | GUI API、属性系统和信号槽使用体验稳定 | Qt 生态绑定较强，成员变量习惯不同 |
| Microsoft / Win32 | 平台 SDK 一致，历史兼容性强 | 现代 C++ 中噪音较大 |
| all `snake_case` | 一致、STL-like | 视觉层次弱 |
| all `camelCase` | 跨语言应用代码友好 | C++ 类型和变量不够醒目 |
| all `PascalCase` | 公共 API 醒目、强势统一 | 普通变量和函数显得过重 |
| `m_` members | 成员变量识别快，历史悠久 | 噪音略高，现代 C++ 中显旧 |

## 5. STL 风格

STL 风格几乎全用 `snake_case`：

```cpp
std::make_unique
std::string_view
std::unordered_map
std::filesystem::current_path
```

如果完全模仿 STL，可能写成：

```cpp
class render_graph {
public:
    void add_render_pass();

private:
    std::vector<render_pass> render_passes_;
};
```

它的价值是：

```text
统一
朴素
和标准库一致
适合算法库、数学库、小型工具库和 header-only library
```

代价是类型、函数和变量的视觉区分较弱。在大型工程、图形引擎、编译器、VM 或工具应用中，扫描速度可能下降。

## 6. Google-like 风格

Google C++ 风格大致接近：

```cpp
class RenderGraph;
void addRenderPass();
int frame_index;
const int kMaxFramesInFlight = 2;
```

当前方案吸收了它的几个优点：

```text
TypeName
functionName
variable_name
kConstantName
```

没有完全照搬的原因是，Google C++ Style 还包含 include 顺序、异常、RTTI、所有权、注释等组织级规则。个人仓库更需要稳定的命名策略，不一定需要完整复制公司级规范。

## 7. LLVM-like 风格

LLVM / Clang 中常见：

```cpp
class MachineFunction;
void emitInstruction();
bool isReg();
```

它适合编译器、工具链和系统级 C++，尤其适合 AST、IR、Pass、Analysis、CodeGen 等概念。

代价是缩写较多，历史包袱较重，对新人不一定友好。个人新项目可以参考它的工程气质，但不必完全模仿。

## 8. Unreal-like 风格

Unreal Engine 风格常见：

```cpp
UObject
AActor
FVector
TArray
bIsVisible
```

这些前缀服务于 Unreal 的宏系统、反射系统、对象模型和编辑器生态：

```text
U    UObject 类型
A    Actor 类型
F    普通 struct/class
T    template
b    bool
```

在 Unreal 内部，这套体系识别速度极快。但离开 Unreal 后，前缀体系会显得很重。个人 C++ 仓库通常不需要承担这种复杂度，除非明确在写 Unreal 插件或 Unreal 项目代码。

## 9. Qt-like 风格

Qt 风格常见：

```cpp
class QWidget;
void setWindowTitle();
QString objectName() const;
int m_width;
```

它的价值是 GUI、属性系统、信号槽和长期 API 稳定性。当前方案和 Qt 的函数风格接近，但成员变量选择 `member_`，而不是 `m_member`。

原因是 trailing underscore 更简洁，也更符合不少现代 C++ 项目的习惯。

## 10. Microsoft / Win32 风格

Win32 API 风格常见：

```cpp
CreateWindowEx
GetMessage
LPWSTR lpWindowName
DWORD dwStyle
```

它服务于二进制 API、历史兼容和平台 SDK 一致性。直接写 Windows API 层时应尊重 API 原名。

但在现代 C++ 项目内部，匈牙利命名和历史类型前缀通常噪音较大，也不太适合 RAII、template 和普通现代 C++ 抽象。

## 11. 全 camelCase 与全 PascalCase

全 `camelCase` 接近 JavaScript、Java、C# 或 GUI 应用代码：

```cpp
class renderGraph;
void addRenderPass();
int frameIndex;
```

它少下划线，跨语言应用开发者熟悉，但 C++ 类型不够醒目，变量和函数也更容易混在一起。

全 `PascalCase` 接近部分 C#、Unreal 或 Win32 风格：

```cpp
class RenderGraph;
void AddRenderPass();
int FrameIndex;
```

它让公共 API 很醒目，但普通局部变量和成员函数也显得过重，变量、函数、类型之间的视觉区分反而变弱。

## 12. 成员变量 m_ 风格

`m_` 成员变量风格常见于很多 C++ 老项目：

```cpp
class Renderer {
private:
    int m_frame_index;
    Device* m_device;
};
```

它的优点是一眼识别 member，历史悠久，也能避免和局部变量冲突。

当前方案选择：

```cpp
int frame_index_;
Device* device_;
```

原因是尾随下划线已经能解决成员识别问题，而且视觉噪音更低。

## 13. 常量为什么不用全大写

全大写常量具有很强的视觉提醒：

```cpp
constexpr int MAX_FRAMES_IN_FLIGHT = 2;
```

但在 C/C++ 中，全大写长期和宏绑定：

```cpp
#define MAX_FRAMES_IN_FLIGHT 2
```

如果普通 `constexpr` 也全大写，会削弱宏的危险信号。

当前方案将二者分开：

```cpp
inline constexpr int kMaxFramesInFlight = 2;  // 常量
#define DELTA_GRFX_ENABLE_ASSERTS 1           // 宏
```

这样常量保持可见，宏也继续保持足够醒目的警示作用。

## 14. 总结

当前风格不是：

```text
我的风格比其他风格高级。
```

而是：

```text
这套风格更适合我个人长期维护的 C++ 工程仓库，尤其是 graphics / compiler / VM / tooling / algorithms 等项目。
```

它的分工可以概括为：

```text
Types        像 C++ 类型
Functions    像工程行为
Variables    像数据
Members      像对象状态
Constants    像编译期语义常量
Macros       保持危险信号
Files        保持跨平台工具友好
```
