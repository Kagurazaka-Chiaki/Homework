#

##

###

#### 求三角形面积

已知 $A, B, C \in \mathbb{R}^{3}$, 则构成的三角形 $\triangle ABC$ 面积

$$
    a = \|\overrightarrow{AB}\|, b = \|\overrightarrow{BC}\|, c = \|\overrightarrow{CA}\|
$$

$$
    p = \frac{1}{2} (a + b + c)
$$

$$
    S = \sqrt{p(p - a)(p - b)(p - c)}
$$

拓展到圆的内接四边, 且四边长为 $a, b, c, d$：

$$
    p = \frac{1}{2} (a + b + c + d)
$$

$$
    S = \sqrt{p(p - a)(p - b)(p - c)(p - d)}
$$

证明：略

#### 三角形参数方程

对于三角形 $\triangle ABC$ 组成的空间三角形，对于三角形内的任一点 $X$，有如下参数方程

$$
    X = (1 - u - v)A + u B + v C
$$

其中 $u \geq 0, v \geq 0, u + v \leq 1$

推导：$\overrightarrow{AP} = u \overrightarrow{AB} + v \overrightarrow{AC}$

#### 直线与空间三角形是否相交

直线公式: 一点 $P$ 一方向 $D$, 即 $X = OP + tOD$, $O$ 为 原点 $(0, 0, 0)$

联立方程得到

$$
    (1 - u - v)A + u B + v C = OP + tOD
$$

显然

$$
    \begin{bmatrix} -OD \quad B - A \quad C - A \end{bmatrix}
    \begin{bmatrix} t \\ u \\ v \end{bmatrix} = P - A
$$

根据克莱姆法则

$$
\begin{cases}
    t = \dfrac{|O - A \quad B - A \quad C - A|}{|-D \quad B - A \quad C - A|} \\
    u = \dfrac{|- D \quad O - A \quad C - A|}{|-D \quad B - A \quad C - A|} \\
    v = \dfrac{|- D \quad B - A \quad O - A|}{|-D \quad B - A \quad C - A|} \\
\end{cases}
$$

$E1 = V2 - V1，E2 = V3 - V1，T = O - V1, \text{dir} = D$

#### 向量的混合积公式

$$
    | a \quad b \quad c| = a \times b \cdot c = - a \times c \cdot b = - c \times b \cdot a
$$

显然 $\text{det} = \text{dir}.cross(e2) \cdot e1$

$$
\begin{cases}
    t = \frac{1}{\text{det}} \cdot T.cross(e1) \cdot e2 \\
    u = \frac{1}{\text{det}} \cdot D.cross(e2) \cdot T \\
    v = \frac{1}{\text{det}} \cdot T.cross(e1) \cdot D \\
\end{cases}
$$

#### 求点到三角形的投影是否在三角形内

已知 $P, A, B, C \in \mathbb{R}^{3}$, 则构成的三角形 $\triangle ABC$ 所在的平面法向量 $\overline{n}$

$$
    \overrightarrow{n} = \overrightarrow{AB} \times \overrightarrow{AC}
$$

平面的点法式方程为

$$
    n_{x}(x - x_{0}) + n_{y} (y - y_{0}) + n_{z}(z - z_{0}) = 0
$$

对与 $P$ 点垂直投影到平面上的点 $H$, 直线 $PH$ 有参数方程

$$
    \begin{cases}
        x = x_{p} + n_{x} t \\
        y = y_{p} + n_{y} t \\
        z = z_{p} + n_{z} t
    \end{cases}
$$

联立方程求 $t$

$$
n_{x}(x_{p} + n_{x} t - x_{0}) + n_{y} (y_{p} + n_{y} t - y_{0}) + n_{z}(z_{p} + n_{z} t - z_{0}) = 0
$$

$$
n_{x}(x_{p} - x_{0}) + n_{x}^{2} t+ n_{y} (y_{p}  - y_{0}) + n_{y}^{2} t + n_{z}(z_{p} - z_{0}) + n_{z}^{2} t= 0
$$

$$
n_{x}(x_{p} - x_{0}) + n_{y} (y_{p}  - y_{0})  + n_{z}(z_{p} - z_{0}) = - n_{x}^{2} t - n_{y}^{2} t - n_{z}^{2} t
$$

$$
t = - \frac{n_{x}(x_{p} - x_{0}) + n_{y} (y_{p}  - y_{0})  + n_{z}(z_{p} - z_{0})}{n_{x}^{2} + n_{y}^{2} + n_{z}^{2}}
$$

回带入直线 $PH$ 的参数方程得到 $H (x_{h}, y_{h}, z_{h})$, 判断 H 是否在三角形 $\triangle ABC$ 内, 参考

```
    P = A + u * (C - A) + v * (B - A)       // Original equation
    (P - A) = u * (C - A) + v * (B - A)     // Subtract A from both sides
    v2 = u * v0 + v * v1                    // Substitute v0, v1, v2 for less writing

    // We have two unknowns (u and v) so we need two equations to solve
    // for them.  Dot both sides by v0 to get one and dot both sides by
    // v1 to get a second.
    (v2) . v0 = (u * v0 + v * v1) . v0
    (v2) . v1 = (u * v0 + v * v1) . v1

    // Distribute v0 and v1
    v2 . v0 = u * (v0 . v0) + v * (v1 . v0)
    v2 . v1 = u * (v0 . v1) + v * (v1 . v1)

    // Now we have two equations and two unknowns and can solve one
    // equation for one variable and substitute into the other.  Or
    // if you're lazy like me, fire up Mathematica and save yourself
    // some handwriting.
    Solve[v2.v0 == {u(v0.v0) + v(v1.v0), v2.v1 == u(v0.v1) + v(v1.v1)}, {u, v}]
    u = ((v1.v1)(v2.v0)-(v1.v0)(v2.v1)) / ((v0.v0)(v1.v1) - (v0.v1)(v1.v0))
    v = ((v0.v0)(v2.v1)-(v0.v1)(v2.v0)) / ((v0.v0)(v1.v1) - (v0.v1)(v1.v0))
```
