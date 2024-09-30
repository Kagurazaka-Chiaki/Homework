# 大气渲染

## 物理基础

复制大气散射光学效应的第一步是了解光是如何穿过空气等介质

空气分子与光相互作用的最明显方式是使光偏转, 改变其方向。

如果一束直射到相机上的光线被偏转, 我们就面临着一个称为散射的过程。

从广义上讲, 物质被外部电磁辐射源激发辐射的过程为散射。(众所周知, 光是电磁波)

与物质发射辐射的过程不同, 物质发射辐射即使在没有这种辐射源的情况下也会发生。

根据这个定义, 电磁波的反射、折射甚至衍射都归入散射。

如果入射辐射和散射辐射之间的频率没有变化, 则称该散射是弹性的; 反之则是无弹性的。

散射也适用于粒子之间导致方向变化的任何相互作用。

### 极化率 Polarizability

指物质在受到电场作用时, 获得与该外加磁场成正比的电偶极矩的趋势。

极化率决定了材料的介电常数, 在高频率下, 则决定了其折射率。

单个粒子的极化率通过克劳修斯-莫索蒂关系与介质的平均电化率有关

$$
R = \left( \frac{4 \pi}{3} N_{A} \alpha_{c} \right)
  = \left( \frac{M}{p} \right) \left( \frac{\epsilon_{r} - 1}{\epsilon_{r} + 2} \right)
$$

其中, $R$ 是摩尔折射率, $N_{A}$ 是 Avogadro 常数, $\alpha_{c}$ 是电子极化率, $M$ 是摩尔质量, $p$ 是分子的密度;
$\epsilon_{r} = \dfrac{\epsilon}{\epsilon_{0}}$ 为材料的相对介电常数 (或在光学中, 是折射率的平方) .

光波的振荡电场作用于粒子内的电荷, 使它们以相同的频率移动。

因此, 粒子变成了一个小的辐射偶极子, 其辐射视为散射光。

### 相位函数 Phase Function

描述散射辐射对散射角的依赖性的函数。

相位函数是散射函数的无量纲归一化版本, 使得相函数在 $4 \pi$ 球面上的积分等于 $4 \pi$。

给定波长的相位函数是介质的特性, 而不是入射辐射的特性, 前提是入射辐射是非偏振的。

随着散射体尺寸参数的增加, 其相位函数变得更加各向异性, 越来越多的散射辐射逐渐集中到衍射峰中。

### 瑞利散射 Rayleigh Scattering

瑞利勋爵 (约翰·威廉·斯特鲁特, 1842-1919) 的名字命名的小粒子电磁散射近似理论 (1871)

瑞利散射的适用范围取决于粒子的折射率

Rayleigh 散射相位函数

### 米氏散射 Mie Scattering

在电磁学中, 是麦克斯韦方程的洛伦兹-米-德拜解, 描述了电磁平面波由均匀球体散射

有时称为非分子散射或气溶胶粒子散射发生在大气层下方 4500 米处, 其中可能存在直径大致等于入射光线波长的球形颗粒。

米氏散射理论没有尺寸上限限制, 对于大颗粒, 它收敛到几何光学的极限。

公式在散射粒子的大小与光的波长相当, 而不是小得多或大得多的情况下最有用。

## 体积单散射

- 外散射 Out-Scattering
  - 当定向光照被粒子偏转, 散射光线定向到相机的情况
  - 向外散射会导致光线逐渐变暗, 这取决于行进的距离和空气密度
- 内散射 In-Scattering
  - 当定向光照被粒子偏转, 使定向光照重新定向到相机的情况
  - 内散射允许看到不在相机直射视线中的光源
  - 最明显的光学效应导致光源周围产生光晕, 放大了接收到的光子数量

单束光线可以偏转任意次数。这意味着光线在到达相机之前可以经过非常复杂的路径。

因为渲染高保真度的半透明材料需要模拟每束光线的路径。这称为光线追踪。

单散射, 因为它只考虑了一束光的单一散射事件, 只考虑沿视线发生的内散射。

### 透射率函数 Transmittance Function

$I_{P}$ 为进入 $P$ 点 (大气内相机视线路径内的粒子) 的光量, $I_{C}$ 是进入大气层 C 点的光量

到达 P 的光量将小于 $I_{C}$, $I_{P}$ 之间的 $I_{P}$ 比率称为透射率 $T(\overline{CP})$

$$
T(\overline{CP}) = \frac{I_{P}}{I_{C}}
$$

表示未散射的光的百分比, 对应于大气散射的贡献, 因此 $P$ 点接受的光量为

$$
I_{P} = I_{C} \cdot T(\overline{CP})
$$

#### 散射函数 Scattering Function

并非所有穿过 $P_{i}$ 的光线都会被传输回相机,为了计算实际到达相机的光量, 引入

散射函数 $S$. 其目的是指示在某个方向上偏转了多少光

同时注意到只有那些偏转 $\theta$ 角度的光线才会指向相机

$S\left(\lambda, \theta, h \right)$ 的值表示光被 $\theta$ 弧度偏转的比率

取决于入射光的颜色 (由其波长表示 $\lambda$), 散射角 $\theta$ 和 $P$ 点的高度 $h$

高度之所以重要, 是因为大气密度随海拔高度的变化而变化。密度是决定光散射量的因素之一

从 $P$ 点到 $A$ 点 (结束大气层影响的位置) 总进光量为

$$
I_{PA} = \boxed{I_P} \, S\left(\lambda, \theta, h\right) \, T\left(\overline{PA}\right)
$$

使用之前的透射率函数定义进行拓展

$$
I_{PA}
    = \boxed{I_C \, T\left(\overline{CP}\right)} \, S\left(\lambda,\theta,h\right) \, T\left(\overline{PA}\right)
    =  \underset{\text{in-scattering}}{ \underbrace{I_C \, S\left(\lambda,\theta, h\right)} }
    \; \underset{\text{out-scattering}}{\underbrace{T\left(\overline{CP}\right) \, T\left(\overline{PA}\right)}}
$$

#### 数值积分 Numerical Integration

$A$ 点接收到的总光量, $I_{A}$ 是通过将所有点 $P \in \overline{AB}$ 的贡献相加来计算的。

从数学上讲, 段 $\overline{AB}$ 中有无限多的点, 因此不可能遍历所有点。

能做的是将 $\overline{AB}$ 长度分割成许多较小的段 $\mathrm{d}s$ 并积累每个段的贡献。

$$
I_{A} = \sum_{P \in \overline{AB}} {I_{PA}\, \mathrm{d}s}
$$

在大气着色器中要做的是遍历大气层内的几个点 $P_i$ , 积累它们对整体结果的贡献。

#### 定向光照 Directional Light

如果太阳离得比较近, 最好将其建模为点光源。

在这种情况下, 进入大气的点 $C_{i}$ 接收到的光量取决于与太阳本身的距离。

而对于行星大气, 通常可以假设太阳是如此遥远, 以至于它的光线都以相同的角度到达行星。

如果是这样的话, 可以将太阳建模为定向光源。从定向光源接收到的光无论传播距离如何都保持恒定。

因此, 每个点 $C_{i}$ 接收到相同数量的光, 并且所有点朝向太阳的方向都是相同的。

用常数 $I_{S}$ 代替 $I_{C}$, 它代表光源强度

$$
I_{A} = \sum_{P \in \overline{AB}} {I_{PA}\, \mathrm{d}s}
    \\ =
    \sum_{P \in \overline{AB}}
    { \boxed{I_C  \, S\left(\lambda,\theta,h\right) \, T(\overline{CP})\,  T(\overline{PA})}\, ds }
    \\ =
    I_S \sum_{P \in \overline{AB}}
    { S \left(\lambda,\theta,h\right) \,T(\overline{CP}) \, T(\overline{PA}) \, ds }
$$

#### 吸收系数 Absorption Coefficient

在描述光分子和空气分子之间相互作用的可能结果时, 有三种分别为直接穿过, 被偏转, 被化合物会吸收。

例如, 臭氧存在于高层大气中, 并且已知会对紫外线产生强烈反应。

然而, 它的存在对天空的颜色几乎没有影响, 因为它吸收了可见光谱之外的光。

在地球上, 光吸收化学物质的贡献经常被忽视。对于其他行星来说, 情况并非如此。

例如, 海王星和天王星的典型颜色是由它们的大气中大量存在的甲烷引起的。众所周知, 甲烷会吸收红光, 从而产生蓝色调。

暂不考虑吸收系数

### 瑞利散射 Rayleigh Scattering 1

用瑞利散射方程在数学上描述，该方程 $S \left(\lambda, \theta, h \right )$ 表示原始光 $I_0$ 向方向 $\theta$ 散射的比率

$$
I = I_0 \, S \left(\lambda, \theta, h\right)
$$

$$
S \left(\lambda, \theta, h\right )
    = \frac{\pi^2 \left(n^2-1 \right )^2}{2}
        \underset{\text{density}}{\underbrace{\frac{\rho\left(h\right)}{N}}}
        \overset{\text{wavelength}}{\overbrace{\frac{1}{\lambda^4}}}
        \underset{\text{geometry}}{\underbrace{\left(1+\cos^2\theta \right )}}
$$

- $\lambda$ ：入射光的波长；
- $\theta$ ：散射角度;
- $h$ : $P_{i}$ 点的高度；
- $n = 1.00029$ ：空气的折射率;
- $N=2.504 \cdot 10^{25}$ : 标准大气的分子数密度。这是每立方米的分子数;
- $\rho(h)$: 密度比，在海平面等于 1 ，并且随着 $h$ 而呈指数下降。

#### 瑞利散射系数 Rayleigh Scattering Coefficient

瑞利散射方程表示向特定方向散射的光量。然而并不能说明总共分散了多少能量。

为了计算这一点，需要考虑所有方向的能量色散。

首先，尽管我们一直在二维空间中观察瑞利散射，但它实际上是一种三维现象。

散射角 $\theta$ 可以是 $3 \mathrm{D}$ 空间中的任何方向。

考虑依赖于 $3 \mathrm{D}$ 空间中的角度 $\theta$ 的函数的总贡献，称为立体角积分：

$$
\beta (\lambda, h)
    = \int_{0}^{2\pi} \int_{0}^{\pi} S(\lambda, \theta, h)
    \sin{\theta} \, \mathrm{d}\theta \mathrm{d}\phi
$$

内积分在 $XY$ 平面中移动 $\theta$，而外积分围绕 $X$ 轴旋转结果以考虑第三维。加上 $\sin{\theta}$ 用于球面角 $\phi$。

$$
\beta(\lambda, h)
= \int_{0}^{2\pi} \int_{0}^{\pi}
    \underset{\text{constant}}{\underbrace{
        \frac{\pi^{2} (n^{2} - 1)^{2}}{2} \frac{\rho(h)}{N} \frac{1}{\lambda^{4}}
    }} \left(1+\cos^2\theta \right )
    \sin{\theta} \, \mathrm{d}\theta \mathrm{d}\phi \\
= \frac{\pi^{2} (n^{2} - 1)^{2}}{2} \frac{\rho(h)}{N} \frac{1}{\lambda^{4}}
\int_{0}^{2\pi} \boxed{
    \int_{0}^{\pi} \left(1+\cos^{2}{\theta} \right ) \sin{\theta} \, \mathrm{d}\theta
} \mathrm{d} \phi
$$

$$
\int_{0}^{\pi} \left(1+\cos^2\theta \right ) \sin{\theta} \, \mathrm{d}\theta \\
u = \cos{\theta} \Longrightarrow \mathrm{d} u = - \sin{\theta} \mathrm{d}\theta
$$

$$
= - \int_{0}^{\pi} u^{2} + 1 \, \mathrm{d} u \\
= - \left[ \frac{1}{3} u^{3} + u \right]_{\cos{0}}^{\cos{\pi}}
= - \left( \frac{1}{3} (-1)^{3} + (-1) -  \left(\frac{1}{3} (1)^{3} + (1) \right) \right)
= \frac{8}{3}
$$

$$
\int_{0}^{2\pi} \frac{8}{3} \mathrm{d} \phi = \frac{8}{3} \int_{0}^{2\pi} 1 \mathrm{d} \phi = \frac{16}{3} \pi
$$

$$
\beta(\lambda, h) =
\frac{8 \pi^{3} (n^{2} - 1)^{2}}{3}
\frac{\rho(h)}{N} \frac{1}{\lambda^{4}}
$$

其中 $\beta(\lambda, h)$ 表示与单个粒子碰撞后因散射而损失的能量部分。这通常被称为瑞利散射系数。

最终考虑了各个方向的散射贡献，因此 $\theta$ 不再依赖于该表达式

$\beta$ 确实是用于定义段 $\overline{AB}$ 上透射率 $T\left(\overline{AB}\right)$ 的消光系数。

计算 $\beta$ 是非常昂贵的。在我们将要编写的着色器中，我们将尝试节省尽可能多的计算。

因此，从散射系数中提取所有常数的因子是有用的。$\beta(\lambda)$，它被称为海平面的瑞利散射系数 $(h = 0)$：

$$
\beta(\lambda) = \frac{8 \pi^{3} (n^{2} - 1)^{2}}{3} \frac{1}{N} \frac{1}{\lambda^{4}}
$$

#### 瑞利相位函数 Rayleigh Phase Function

描述瑞利散射的原始方程 $ S(\lambda, \theta)$ 可以分解为两个分量。

一是散射系数，$\beta(\lambda)$ 二是与散射的几何形状有关，并控制其方向

$$
S(\lambda, \theta, h) = \beta(\lambda, h) \gamma(\theta)
$$

$$
\gamma(\theta)
    = \frac{S(\lambda, \theta, h)}{\beta(\lambda, h)} \\
    = \underset{S(\lambda, \theta, h)}{
        \underbrace{
            \frac{\pi^2 ( n^2-1 )^2}{2}
            \frac{\rho(h)}{N}
            \frac{1}{\lambda^4}
            (1 + \cos^{2}\theta )
        }
    } \;
    \underset{1 / \beta(\lambda, h)}{
        \underbrace{ \frac{3}{8\pi^3 (n^{2} - 1)^2} \frac{N}{\rho(h)} \lambda^4 }
    } \\
    = \frac{3}{16\pi} (1 + \cos^{2} \theta)
$$

#### 大气密度比 Atmospheric Density Ratio

从逻辑的角度来看，散射的强度与大气密度成正比是有道理的。每平方米的分子越多，光子被散射的机会就越大。

挑战在于大气的成分非常复杂，由具有不同压力、密度和温度的几层组成。

幸运的是，大部分瑞利散射发生在大气层的前 60 公里处。在对流层内，温度呈线性下降，压力呈指数下降。

$\rho(h)$ 表示 $h$ 米高度的大气测量值，经过归一化后，它从零开始。

在许多科学论文中， $\rho$ 也称为密度比，因为它也可以定义为：

低层大气中的密度比是呈指数衰减，可以用指数曲线来近似密度比：

$$
\rho(h) = \exp \left \{ -\frac{h}{H} \right \}
$$

其中 $H_0$ 是高度标量。对于地球低层大气中的瑞利散射，通常假设 $H = 8500$ 为米。

对于米氏散射，通常是在 $1200$ 米左右。

#### 指数衰减 Exponential Decay

在瑞利散射的情况下，计算每次相互作用受到大气散射的光量：

$$
\beta(\lambda, h) = \frac{ 8 \pi^{2} (n^{2} - 1)^{2}}{3} \frac{\rho(h)}{N} \frac{1}{\lambda^{4}}
$$

当在海平面上时，这意味着使用 $h = 0$ ，它会产生以下结果：

$$
\beta(680 nm) = 0.00000519673
$$

$$
\beta(550 nm) = 0.0000121427
$$

$$
\beta(440 nm) = 0.0000296453
$$

其中 $680$, $550$ 和 $440$ 是松散映射到红色、绿色和蓝色的波长

这些表示与粒子的单次相互作用损失的光的比率。

如果我们假设一束光具有初始强度 $I_0$, 并以散射系数 $\beta$ 穿过大气的一部分，

那么不会因散射而损失的光量为

$$
I_{1}
    = \underset{\text{initial energy}}{\underbrace{I_{0}}}
    - \underset{\text{energy lost}}{\underbrace{I_{0} \beta}}
    = I_{0} (1 - \beta)
$$

当光在具有散射系数 $\beta$ 的均匀介质中传播时

$$
I_1 = I_0 \left (1-\frac{\beta}{2} \right ) \quad
I_2 = \boxed{I_1} \left ( 1 - \frac{\beta}{2} \right )
    = I_0 \left (1-\frac{\beta}{2} \right )^2
$$

显然

$$
I = \lim_{n\rightarrow \infty }I_0 \left(1-\frac{\beta}{n}\right)^{n}
$$

$$
\lim_{n\rightarrow \infty } \left(1-\frac{\beta}{n}\right)^n = e^{-\beta}
= \exp \{ - \beta \}
$$

因此

$$
I = I_0 \exp \{-\beta x \}
$$

#### 均匀透射率 Uniform Transmittance

回顾透射率函数

$$
I_{P} = I_{C} \cdot T(\overline{CP})
$$

散射的光量取决于行进的距离。旅程越长，衰减越强。根据指数衰减

$$
I_{P} = I_{C} \cdot \exp{ \left \{ -\beta \overline{CP} \right \} }
$$

#### 大气透射率 Atmospheric Transmittance

散射系数很大程度上取决于大气密度。每立方米的空气分子越多，撞击的可能性就越大。

行星大气层的密度据高度的变化而变化。这意味着不能一步计算 $\overline{CP}$ 到位。

需要计算每个点 $Q \in \overline{CP}$ 的外散射，并使用 Q 点的散射系数。

例如，存在点 $Q \in \overline{CP}$，划分为 $\overline{CQ}$ 和 $\overline{QP}$, 则

$$
I_{Q} = I_{C} \exp{\left \{-\beta{(\lambda, h_{0})} \overline{CQ} \right \}}
$$

$$
I_{P} = \boxed{I_{Q}} \exp{\left \{-\beta{(\lambda, h_{1})} \overline{QP} \right \}}
$$

$$
I_{P} = I_{C} \exp{\left \{-\beta{(\lambda, h_{0})} \overline{CQ} \right \}}
    \exp{\left \{-\beta{(\lambda, h_{1})} \overline{QP} \right \}}
$$

$$
I_{P} = I_{C}
    \exp{
        \left \{
            -\beta{(\lambda, h_{0})} \overline{CQ}
            -\beta{(\lambda, h_{1})} \overline{QP}
        \right \}
    }
$$

用任意数量的段重复这个过程，越来越接近实际值。则有数值积分如下

$$
I_P = I_C \cdot
\exp \left \{
    - \sum_{Q \in \overline{CP}} { \beta( \lambda, h_{Q}) } \, \mathrm{d} s
\right \}
$$

其中 $h_{Q}$ 是点 $Q$ 的高度。最终大气在任意段上的透射率方程

$$
T(\overline{CP}) =
\exp \left \{
    - \underset{\beta(\lambda)}{\underset{\text{constant}}{
        \underbrace{ \frac{8 \pi^{3} (n^{2} - 1)^{2}}{3} \frac{1}{N} \frac{1}{\lambda^{4}} }}}
    \overset{\text{optical depth} \, D(\overline{CP})}{
        \overbrace{ \sum_{Q \in \overline{CP}} { \rho(h_{Q}) } \, \mathrm{d} s}}
\right \}
$$

由求和表示的数量被称为 光学深度 $D(\overline{CP})$ ，也是将在着色器中实际计算的量。

剩下的部分是一个乘法系数，只能计算一次，对应于海平面的散射系数。

在最后的着色器中，我们将只计算光学深度，并提供海平面 $\beta$ 的散射系数作为输入。

$$
T(\overline{CP}) = \exp \left \{
    - \beta(\lambda) D(\overline{CP})
\right \}
$$

到达 P 点的光为

$$
I_{P} = I_{C} \cdot \exp \left \{
    - \beta(\lambda) D(\overline{CP})
\right \}
$$

#### 光采样 Light Sampling

大气散射方程为

$$
I = I_S \sum_{P \in \overline{AB}} {
        S(\lambda, \theta, h)  T(\overline{CP})  T(\overline{PA}) \mathrm{d} s
    }
$$

第一步是将散射函数分解为两个基本分量：

$$
S(\lambda, \theta, h) = \beta (\lambda, h ) \gamma(\theta) = \beta(\lambda) \rho(h) \gamma(\theta)
$$

由于角度 $\theta$ 和波长 $\lambda$ 不依赖于采样点，相位函数 $\gamma(\theta)$ 和海平面的散射系数 $\beta(\lambda)$ 恒定

$$
I = I_S \, \beta(\lambda) \, \gamma(\theta)
    \sum_{P \in \overline{AB}}
    \underset{\text{light contribution of}\,L(P)}{
        \underbrace{
            T(\overline{CP})  T(\overline{PA}) \rho(h) \mathrm{d} s
        }
    }
$$

组合透射率被建模为指数衰减，其中系数是光经过的路径上的光学深度之和

$$
T(\overline{CP})  T(\overline{PA}) =
\exp \left \{
    - \beta(\lambda) \left( D(\overline{CP}) + D(\overline{PA}) \right)
\right \}
$$

光学深度定义为

$$
D(\overline{PA}) = \sum_{Q \in \overline{PA}} {
    \exp \left \{ - \frac{h_{Q}}{H} \right \}
} \, \mathrm{d} s
$$

考虑 $P$ 点对于光采样的贡献

$$
L(P) =
    \underset{\text{combined transmittance}}{
        \underbrace{
            \exp \left \{
                - \beta(\lambda) \left( D(\overline{CP}) + D(\overline{PA}) \right)
            \right \}
        }
    } \, \underset{\text{optical depth of} \,\mathrm{d} s}{\underbrace{\rho(h) \mathrm{d} s}}
$$

Rayleigh 散射方程, $I_S$ 为初始光源强度

$$
I = I_S \, \beta(\lambda) \, \gamma(\theta)
    \sum_{P \in \overline{AB}} L(P)
$$

### 米氏散射 Mie Scattering 1

加上 Mie 散射后

$$
I = I_S \,
\sum_{k \in \{Ray, Mie\}}
\beta_{k}(\lambda) \, \gamma_{k}(\theta)
    \sum_{P \in \overline{AB}} L_{k}(P)
$$

## 多散射模型

真实大气为多散射模型，下一次散射均由前一级确定，这个递归表示为

$$
I^{i + 1}(A, v, s) =
    \int_{A}^{B} T(PA) \int_{0}^{4 \pi}
        I^{i}(P, v^{'}, s) \beta(v, v^{'}) \,
    \mathrm{d} v^{'} \mathrm{d} s
$$

在摄像机 $A$ 点、从观察方向 $v$、光线入射方向 $s$ 贡献的第 $i + 1$ 级散射等于对观察路径 $AB$ 上的每一点 $P$ 的贡献度进行积分。

### 预计算的大气散射 Precomputed Atmospheric Scattering

设定 $L(x, v, s)$ 表示 x 点接受 $v$ 方向传来的光，$s$ 表示太阳光方向也就是入射大气层的方向；

$x_{0}(x, v)$ 表示是射线 $x + tv$ 的末端

$x$ 点的散射光来源于其一是太阳光 $s$ 在经过一定光学深度的衰减后到达的，其二是来自地面的反射光.

大气透射率 $T$ 是由于吸收和散射光而产生的，在散射建模部分可以只知道 $T$ 与光学深度 $D$ 有关;

$$
T(x, x_{0}) = \exp \left \{
    - \int_{x}^{x_{0}} \beta_{Ray}(y) + \beta_{Mie}(y) \mathrm{d} y
\right \}
$$

$\mathcal{I}[L]$ 是在 $x_{0}$ 处反射向 $x$ (视线 $V$ 方向的反方向 $-V$) 的光, 在大气边界处为 0.

$$
\mathcal{I}[L] = \dfrac{\alpha(x_{0})}{\pi} \cdot
\int_{2 \pi} L(x_{0}, \omega, s) \cdot \omega \cdot n(x_{0}) \mathrm{d} \omega
\quad \text{or} \quad \mathcal{I}[L] =  0
$$

$\mathcal{J}[L]$ 是太阳光 $s$ 在 $y$ 点发生的内散射;

$$
\mathcal{J}[L] = \int_{4 \pi} \sum_{Ray, Mie}
\beta(y) P(v, \omega) L(y, \omega, s) \, \mathrm{d} \omega
$$

所有的光在到达 $x$ 点前都会被衰减，所以，点 $x$ 处的总光为 $L(x,v,s)$为：

$$
L(x,v,s) = \left(
    L_{0} + \mathcal{R}[L] + \mathcal{S}[L]
\right)(x, v, s)
$$

其中，$L_{0}$ 是 $L_{sun}$ 经过 $T(x, x_0)$ 衰减后到达 $x$ 点的值, 当 $v \neq s$ 或被地面遮挡时, $L_{0} = 0$;

$$
L_{0} = T(x, x_{0}) L_{sun} \quad \text{or} \quad L_{0} = 0
$$

$\mathcal{R}[L]$ 是在 $x_0$ 反射的光，同样的在这部分光在到达 $x$ 之前也会被衰减;

$$
\mathcal{R}[L] =  T(x, x_{0}) \mathcal{I}[L] (x_{0}, s)
$$

$\mathcal{S}[L]$ 是在 $x$ 与 $x_0$ 之间发生的内向散射光;

$$
\mathcal{S}[L] = \int_{x}^{x_{0}} T(x, y) \mathcal{J}[L] (y, v, s) \, \mathrm{d} y
$$

注意到，L 可以用线性算子 $\mathcal{R}$ 和 $\mathcal{S}$ 的级数来表示，其中第 $i$ 项对应光反射或散射了 $i$ 次

$$
L = L_{0} + [\mathcal{R} + \mathcal{S}](L_{0}) + [\mathcal{R} + \mathcal{S}]((\mathcal{R} + \mathcal{S})[L_{0})]
$$

既是

$$ L = L_{0} + L_{1} + L_{2} + \cdots = L_{0} + L_{\ast} $$

单次散射

$$
\mathcal{S}[L_{0}](x, v, s)
    = \overline{\mathcal{S}}[\overline{L}_{0}](x, v, s)
    - T(x, x_{s}) \overline{\mathcal{S}}[\overline{L}_{0}](x_{s}, v, s)
$$

多次散射

$$
\hat{\mathcal{R}}[\overline{L}_{\ast}] =  T(x, x_{o}) \frac{\alpha(x_{o})}{\pi}
\frac{1 + n(x_{o} \cdot \overline{n}(x_{o}))}{2} \mathcal{\overline{E}}[\overline{L}_{\ast}](x_{o}, s)
$$

$$
\mathcal{\overline{E}}[\overline{L}_{\ast}](x_{o}, s) =
\int_{2 \pi} \overline{L}_{\ast}(x_{o}, \omega, s) \cdot \omega \cdot \overline{n}(x_{o}) \, \mathrm{d} \omega
$$

注意到 $\overline{\mathcal{S}}[\overline{L}_{x}] = \overline{\mathcal{S}}[\overline{L}](x, v, s)$

$$
L \simeq L_{0}
    + \mathcal{R}[L_{0}]
    + \hat{\mathcal{R}}[\overline{L}_{\ast}]
    + \overline{\mathcal{S}}[\overline{L}_{x}]_{x}
    - T(x, x_{s}) \overline{\mathcal{S}}[\overline{L}_{x}]_{x_{s}}
$$

前两个方程中的 $T$ 与 $\mathcal{E}$ 可以直接从两张 2D 预计算的纹理获得，

至于第三项的 $\overline{\mathcal{S}}[\overline{L}]$ 可以从一张预计算的 4D 纹理获取，

这样原本复杂的计算部分可以直接转换为纹理采样，然后再参与 $L(x,v,s)$ 的计算。预计算的过程如下

$$
\cdots
$$

#### 查找表 Lookup Table (LUT)

$$
\cdots
$$

##### Transmittance LUT

$$
\cdots
$$

##### Sky View LUT

$$
\cdots
$$

##### Aerial Perspective LUT

$$
\cdots
$$

##### Multiple Scattering LUT

$$
\cdots
$$
