
# 虚拟纹理

## Clipmap

基本思想是，设置一个 mipmap 大小的上限，超过这个上限的 mipmap 会被 clip 掉，也就是不会加载到内存中

## Software Virtual Texture

概念取自于 Virtual Memory 虚拟内存

与虚拟内存类似的是，一个很大的Texture将不会全部加载到内存中，而是根据实际需求，将需要的部分加载。

与虚拟内存不同的是，它不会阻塞执行，可以使用更高的 mipmap 来暂时显示，它对基于图块的压缩贴图有很好的支持。

虚拟纹理基本思路

将纹理的 mipmap chain 分割为相同大小的 tile 或 page, 这里的纹理叫虚纹理，

然后通过某种映射，映射到一张内存中存在的纹理，这里的纹理是物理纹理，

在游戏视野发生变化的时候，一部分物理纹理会被替换出去，一部分物理纹理会被加载。

减少了带宽消耗和内存（显存）消耗

有利于合批，而不用因为使用不同的 Texture 而打断合批

可以根据需求来组织几何使得更利于 Culling

### 地址映射

#### 四叉树映射

#### 单像素映射

#### 双纹理映射

#### Page 和 mip level 映射

#### HashTable 映射

### 纹理过滤 Texture Filtering

由于虚拟纹理并没有完整加载，所以各种采样过滤在页表边界会有问题，需要设计解决这些问题的方法，适当的使用软实现的采样。

#### 双线性过滤 Bi-linear Filtering

#### 各向异性过滤 Anisotropic Filtering

#### 三线性过滤 Tri-linear Filtering

### Feedback Rendering

决定加载哪些 Page 的策略，这个策略就是要有一个叫 Feedback Rendering 的过程。

这个可以设计为一个单独的 Pass，或者跟 Pre-Z 或者 GBuffer 同时。

渲染生成的这张 Texture 里面存的就是虚纹理的 Page 坐标，mip level 和可能的虚纹理 id（用来应对多虚纹理的情况）。

#### Texture Poping

由于 Page 是异步加载有延时的，当加载的 mip 比当前显示的差很远的时候，会使用新加载的更清晰的mip, 这样会看到非常明显的跳变。

假如我们用了软实现的Tri-linear Filtering，那么当加载的mip level跟当前显示的mip level相差很大的时候，

需要做一个delay，等待中间的mip page的加载，然后再去更新。

### 存储和流式加载

#### 存储和压缩

#### 离线烘焙 Feedback Data

### Virtual Texture Pipeline

首先执行一个 Feedback Rendering, 或者从烘培好的 Feedback Data 中取出当前的数据;

然后分析需要加载的 Page，尝试从内存中找到这个 Page，如果没有的话，从磁盘或者光盘中加载。

然后申请一个新的物理纹理 Page，在使用这个纹理之前，假如是之前用过的 Page，我们需要先与GPU解绑。

确定完之后，把这个 Texture 转换成一个 GPU 能用的压缩的 Texture 内容，并将这块 Texture 与 GPU 绑定。

其中分析 Feedback, Unmap, Transcode, Map 过程是可以异步发生的，也就是需要一个任务管理去驱动，他们的关系是生产者消费者的关系。

## 硬件虚拟纹理 Hardware Virtual Texture

首先需要在内存中创建一个 Page Pool，这是用来存放从磁盘中加载的纹理内存, 可以理解为物理纹理。

然后，我们再创建一个特殊格式的 Texture，这个代表那张 Virtual Texture，

这个时候，图形 API 会帮我们创建一个 Page Table 用于映射。

在更新的过程中，我们需要首先更新映射关系，也就是 Page Pool 和 Page Table 的关系，

然后，再将加载的 Page pool 中的内容更新到 Virtual Texture 中。

## 程序虚拟纹理 Procedural Virtual Texture

与离线的 Virtual Texture 一样，仍然需要去维护一个 Virtual Texture 到 Physical Texture 的映射

### Unreal Virtual Texture 流程

Unreal 是基于 Software Virtual Texture，并未涉及 Hardware 的内容，实现了 Procedural Virtual Texture, Unreal 叫 Runtime Virtual Texture,

并未实现 Adaptive Procedural Texture。地址映射使用了 indirection texture 的 page 和 mip level 的映射方式。

Texture Filtering 方面实现了 Bi-linear Filtering，Anisotropic Filtering，Tri-linear Filtering,

Bi-linear Filtering 是基于 border 来实现的，Tri-linear Filtering 则是利用 TAA 的一个实现，这个实现是其特有的，

Anisotropic Filtering 则是自己计算 AnisoBias 来实现的。

Feedback Rendering 是跟 GBuffer 同时的，也就是结果会延迟一帧，

分辨率可以用 VIRTUAL_TEXTURE_FEEDBACK_FACTOR 来控制，是 UAV 来操作的。

Transcode 方面使用的是 Crunch，也就是压缩方式是 DXT，

由于 Unreal 的磁盘上的纹理是 uasset, 所以没有其他通用 image 格式的压缩了。

Virtual Texture

#### 分配虚拟纹理内存 Virtual Texture Allocating

#### 纹理页表映射 FTexturePageMap

负责一个 Layer 的 Page Table, 包括 Page Table 的数据结构和 Map Page 的操作。

Virtual Address 在代码里面为 `vAddress`, 它的编码方式是 Morton Order。
