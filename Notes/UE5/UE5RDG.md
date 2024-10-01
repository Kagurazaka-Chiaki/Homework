# UE5 Render Dependency Graph (RDG)

## RDG 基础类型

```cpp
// RDG Pass类型.
enum class ERDGPassFlags : uint8
{
    None = 0,                       // 用于无参数的 AddPass 函数.
    Raster = 1 << 0,                // Pass 在图形管道上使用光栅化.
    Compute = 1 << 1,               // Pass 在图形管道上使用 compute.
    AsyncCompute = 1 << 2,          // Pass 在异步计算管道上使用 compute
    Copy = 1 << 3,                  // Pass 在图形管道上使用复制命令.
    NeverCull = 1 << 4,             // 不被裁剪优化, 用于特殊 pass.

    SkipRenderPass = 1 << 5,        // 忽略 BeginRenderPass/EndRenderPass, 留给用户去调用. 
                                    // 只在 Raster 绑定时有效. 将禁用 Pass 合并.

    UntrackedAccess = 1 << 6,       // Pass 访问原始的 RHI 资源，这些资源可能被注册到 RDG 中，但所有资源都保持在当前状态. 
                                    // 此标志阻止图形调度跨越通道的分割障碍。任何拆分都被延迟到 pass 执行之后。
                                    // 资源可能不会在 pass 执行过程中改变状态。影响性能的屏障。不能与 AsyncCompute 组合。
                                    
    Readback = Copy | NeverCull,    // Pass使用复制命令，但写入暂存资源(staging resource).

    CommandMask = Raster | Compute | AsyncCompute | Copy,   // 标志掩码，表示提交给 pass 的RHI命令的类型.
    ScopeMask = NeverCull | UntrackedAccess                 // 可由传递标志作用域使用的标志掩码
};

// Buffer标记.
enum class ERDGBufferFlags : uint8
{
    None = 0,               // 无标记.
    MultiFrame = 1 << 0     // 存续于多帧.
};

// 纹理标记.
enum class ERDGTextureFlags : uint8
{
    None = 0,
    MultiFrame = 1 << 0,            // 存续于多帧.
    MaintainCompression = 1 << 1,   // 防止在此纹理上解压元数据.
};

// UAV 标记.
enum class ERDGUnorderedAccessViewFlags : uint8
{
    None = 0,
    SkipBarrier = 1 << 0 // 忽略屏障.
};

// 父资源类型.
enum class ERDGParentResourceType : uint8
{
    Texture,
    Buffer,
    MAX
};

// 视图类型.
enum class ERDGViewType : uint8
{
    TextureUAV, // 纹理 UAV (用于写入数据)
    TextureSRV, // 纹理 SRV (用于读取数据)
    BufferUAV,  // 缓冲 UAV (用于写入数据)
    BufferSRV,  // 缓冲 SRV (用于读取数据)
    MAX
};

// 用于在创建视图时指定纹理元数据平面
enum class ERDGTextureMetaDataAccess : uint8
{
    None = 0,               // 主平面默认压缩使用.
    CompressedSurface,      // 主平面不压缩使用.
    Depth,      // 深度平面默认压缩使用.
    Stencil,    // 模板平面默认压缩使用.
    HTile,      // HTile 平面.
    FMask,      // FMask 平面.
    CMask       // CMask 平面.
};
```
