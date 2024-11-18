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

OverDraw（过度绘制）是指在计算机图形学和用户界面渲染中，屏幕上的某个像素在单帧渲染过程中被绘制多次的现象。这意味着同一位置的像素被重复绘制，而最终用户只能看到最后一次绘制的结果。

**过度绘制的影响：**

1. **性能降低**：过多的绘制操作会增加 CPU 和 GPU 的负担，导致应用运行速度变慢。
2. **功耗增加**：重复的绘制过程消耗更多的电能，影响设备的电池续航。
3. **界面卡顿**：在资源有限的设备上，过度绘制可能导致界面不流畅，影响用户体验。

**引起过度绘制的常见原因：**

- **视图层次结构复杂**：过深的视图嵌套或过多的重叠视图。
- **背景透明度**：使用透明的背景或不必要的半透明效果。
- **布局重复**：在布局中叠加了多个功能相似的视图。

**如何检测和优化过度绘制：**

- **使用开发者工具**：例如，在 Android 中，可以使用开发者选项中的“显示过度绘制区域”来检测。
- **优化布局**：简化视图层次，减少不必要的嵌套和重叠。
- **重用视图**：通过复用视图和使用适当的设计模式来减少绘制次数。
- **减少透明效果**：尽量避免使用不必要的透明度，使用实色背景替代。

通过减少过度绘制，可以提升应用的性能，降低功耗，提供更佳的用户体验。

在计算机图形学中，“Primis”可能是对“图形基元”（Graphics Primitives）的简称或误写。图形基元是构成计算机图形和图像的最基本元素或形状，用于创建复杂的图形和场景。

常见的图形基元包括：

- **点（Point）**：二维或三维空间中的一个位置，没有尺寸。
- **线（Line）**：由两个点定义的直线段。
- **多边形（Polygon）**：由一系列顶点连接而成的封闭形状，通常用于表示平面形状。
- **三角形（Triangle）**：最简单的多边形，由三个顶点组成，是构建复杂三维模型的基础。
- **曲线（Curve）**：如贝塞尔曲线，用于描绘平滑的弧线。
- **立体图形（Solid Primitives）**：如立方体、球体、圆柱体等三维形状。

通过对这些基本元素进行组合、变换和渲染，计算机能够生成复杂的二维图像和三维模型。例如，在三维图形中，复杂的模型通常是由大量的三角形组合而成，这些三角形被称为多边形网格。

图形基元在计算机图形学中起着关键作用，它们是图形 API（如 OpenGL、DirectX）和图形引擎处理中最基本的操作单位。理解和有效地使用图形基元对于图形程序的开发和优化至关重要。
