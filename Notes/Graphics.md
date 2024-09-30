

#### 渲染管线


##### 输入装配 input assembler

The input assembler collects the raw vertex data from the buffers you specify and may also use an index buffer to repeat certain elements without having to duplicate the vertex data itself.

从指定的缓冲区收集原始顶点数据，还可以使用索引缓冲区重复某些元素，而无需复制顶点数据本身。

##### 顶点着色器 vertex shader

The vertex shader is run for every vertex and generally applies transformations to turn vertex positions from model space to screen space. It also passes per-vertex data down the pipeline.

顶点着色器针对每个顶点运行，并且通常应用转换以将顶点位置从模型空间转换为屏幕空间。它还沿管道向下传递每个顶点的数据。

可编程

##### 曲面细分 tessellation shader

The tessellation shaders allow you to subdivide geometry based on certain rules to increase the mesh quality. This is often used to make surfaces like brick walls and staircases look less flat when they are nearby.

曲面细分着色器允许根据某些规则细分几何体，以提高网格质量。这通常用于使砖墙和楼梯等表面在附近时看起来不那么平坦。

可编程

##### 几何着色器 geometry shader

The geometry shader is run on every primitive (triangle, line, point) and can discard it or output more primitives than came in. This is similar to the tessellation shader, but much more flexible. However, it is not used much in today's applications because the performance is not that good on most graphics cards except for Intel's integrated GPUs.

几何着色器在每个基元 （三角形、线条、点） 上运行，并且可以丢弃它或输出比传入的基元更多的基元。这类似于曲面细分着色器，但要灵活得多。但是，它在当今的应用程序中使用不多，因为除了 Intel 的集成 GPU 外，大多数显卡的性能都不是那么好。

可编程

##### 光栅化阶段 rasterization stage

The rasterization stage discretizes the primitives into fragments. These are the pixel elements that they fill on the framebuffer. Any fragments that fall outside the screen are discarded and the attributes outputted by the vertex shader are interpolated across the fragments, as shown in the figure. Usually the fragments that are behind other primitive fragments are also discarded here because of depth testing.

光栅化阶段将基元离散为片段。这些是它们在 framebuffer 上填充的像素元素。落在屏幕之外的任何片段都将被丢弃，顶点着色器输出的属性将在片段之间插值，如图所示。通常，由于深度测试，位于其他原始片段后面的片段也会在此处丢弃。

##### 像素着色器 fragment shader

The fragment shader is invoked for every fragment that survives and determines which framebuffer(s) the fragments are written to and with which color and depth values. It can do this using the interpolated data from the vertex shader, which can include things like texture coordinates and normals for lighting.

将为每个幸存的像素调用像素着色器，并确定像素被写入的帧缓冲区以及使用哪些 color 和 depth 值。它可以使用来自顶点着色器的插值数据来执行此操作，其中可以包括纹理坐标和照明法线等内容。

可编程

##### 颜色混合 color blending

The color blending stage applies operations to mix different fragments that map to the same pixel in the framebuffer. Fragments can simply overwrite each other, add up or be mixed based upon transparency.

颜色混合阶段应用操作来混合映射到帧缓冲区中同一像素的不同片段。片段可以简单地相互覆盖、叠加或根据透明度进行混合。


