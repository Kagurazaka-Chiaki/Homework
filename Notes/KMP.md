```
0011
1100101100110
```

```dot
digraph dfa {
    layout=neato;
    rankdir=LR;
    splines="spline";
    edge [penwidth=1.0, arrowsize=0.5]
    node [shape = doublecircle] 5;
    node [shape = point] Q ;
    node [shape = circle];
    Q [pos="0,0!"]
    1 [pos="1,0!"   , label = "ε"    ];
    2 [pos="2,0!"   , label = "0"    ];
    3 [pos="3,0!"   , label = "00"   ];
    4 [pos="4,0!"   , label = "001"  ];
    5 [pos="5.2,0!" , label = "0011" ];

    Q -> 1 [label = "0, 1"]

    1 -> 2 [label = "0"]
    1:ne -> 1:nw [label = "1"]

    2 -> 3 [label = "0"]
    2:nw -> 1:ne [label = "1"]

    3 -> 4 [label = "1"]
    3:ne -> 3:nw [label = "0"]

    4:sw -> 1:se [label = "0"]
    4 -> 5 [label = "1"]

    5:ne -> 5:nw [label = "0, 1"]
}
```

|              状态转换表               |
| :-----------------------------------: |
| $1 \rightarrow f(1, 0) \rightarrow 0$ |
| $1 \rightarrow f(1, 0) \rightarrow 0$ |
| $0 \rightarrow f(0, 0) \rightarrow 1$ |
| $0 \rightarrow f(0, 1) \rightarrow 2$ |
| $1 \rightarrow f(1, 2) \rightarrow 3$ |
| $0 \rightarrow f(0, 3) \rightarrow 0$ |
| $1 \rightarrow f(1, 0) \rightarrow 0$ |
| $1 \rightarrow f(1, 0) \rightarrow 0$ |
| $0 \rightarrow f(0, 0) \rightarrow 1$ |
| $0 \rightarrow f(0, 1) \rightarrow 2$ |
| $1 \rightarrow f(1, 2) \rightarrow 3$ |
| $1 \rightarrow f(1, 3) \rightarrow 4$ |
|    $0 \rightarrow \textrm{helt.}$     |

:::

### 前缀函数和 Next 数组

明天再写