### 矩阵操作

```cpp
void m_op1(std::unordered_map<int, std::vector<int>> &M, int n, int m, int x, int y) {
    if (M.find(x) == M.end() && M.find(y) == M.end()) {
        M[x] = std::vector<int>(m, 0);
        M[y] = std::vector<int>(m, 0);
        for (int j = 0; j < m; ++j) {
            M[y][j] = ((x + 1) - 1) * m + (j + 1);
        }
        for (int j = 0; j < m; ++j) {
            M[x][j] = ((y + 1) - 1) * m + (j + 1);
        }
    } else if (M.find(x) != M.end() && M.find(y) == M.end()) {
        M[y] = std::vector<int>(m, 0);
        for (int j = 0; j < m; ++j) {
            M[y][j] = ((x + 1) - 1) * m + (j + 1);
        }
        for (int j = 0; j < m; ++j) {
            M[x][j] = ((y + 1) - 1) * m + (j + 1);
        }
    } else if (M.find(x) == M.end() && M.find(y) != M.end()) {
        M[x] = std::vector<int>(m, 0);
        for (int j = 0; j < m; ++j) {
            M[y][j] = ((x + 1) - 1) * m + (j + 1);
        }
        for (int j = 0; j < m; ++j) {
            M[x][j] = ((y + 1) - 1) * m + (j + 1);
        }
    } else if (M.find(x) != M.end() && M.find(y) != M.end()) {
        for (int j = 0; j < m; ++j) {
            std::swap(M[x][j], M[y][j]);
        }
    }
}

void m_op2(std::unordered_map<int, std::vector<int>> &M, int n, int m, int x, int y) {
    if (M.find(x) == M.end()) {
        M[x] = std::vector<int>(m, 0);
        for (int j = 0; j < m; ++j) {
            int i = (j + (y + 1)) % m;
            M[x][j] = ((x + 1) - 1) * m + (i + 1);
        }
    } else {
        std::vector<int> save = {};-

        for (int j = 0; j < m; ++j) {
            save.push_back(M[x][j]);
        }
        for (int j = 0; j < m; ++j) {
            M[x][j] = save[(j + (y + 1)) % m];
        }
    }
}

void m_op3(std::unordered_map<int, std::vector<int>> &M, int n, int m, int x, int y) {
    if (M.find(x) == M.end()) {
        M[x] = std::vector<int>(m, 0);
        for (int j = 0; j < m; ++j) {
            M[x][j] = ((x + 1) - 1) * m + (j + 1);
        }
    }
    if (M.find(x) != M.end()) {
        printf("[%d]\n", M[x][y]);
    }
}

// x 行与 y 行交换
void v_op1(std::vector<std::vector<int>> &M, int n, int m, int x, int y) {
    for (int j = 0; j < m; ++j) {
        std::swap(M[x][j], M[y][j]);
    }
}

// x 行左移 y 格
void v_op2(std::vector<std::vector<int>> &M, int n, int m, int x, int y) {
    
}

// 输出 M[x][y]
void v_op3(std::vector<std::vector<int>> &M, int n, int m, int x, int y) {
    printf("[%d]\n", M[x][y]);
}

void print_vec(std::vector<std::vector<int>> const &M) {
    for (auto const &row: M) {
        for (auto const &col: row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}

void print_map(std::unordered_map<int, std::vector<int>> const &M) {
    for (auto const &row: M) {
        std::cout << row.first << " -> ";
        if (row.second.empty()) {
            std::cout << "empty" << std::endl;
            continue;
        }
        for (auto const &col: row.second) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}

void compute(std::fstream &fcin, std::fstream &fcout) {

    int n, m, T;
    fcin >> n >> m >> T;
    fcout << n << " " << m << " " << T << std::endl;

    std::unordered_map<int, std::vector<int>> M = {};

    // // vector 超过限制内存
    // std::vector<std::vector<int>> M = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         M[i][j] = ((i + 1) - 1) * m + (j + 1);
    //     }
    // }

    // print_vec(M);

    for (int i = 0; i < T; ++i) {
        int t, x, y;
        fcin >> t >> x >> y;
        fcout << t << " " << x << " " << y << " -> " << std::endl;
        switch (t) {
            case 1:
                m_op1(M, n, m, x - 1, y - 1);
                print_map(M);
                // v_op1(M, n, m, x - 1, y - 1);
                // print_vec(M);
                break;
            case 2:
                m_op2(M, n, m, x - 1, y - 1);
                print_map(M);
                // v_op2(M, n, m, x - 1, y - 1);
                // print_vec(M);
                break;
            case 3:
                m_op3(M, n, m, x - 1, y - 1);
                // v_op3(M, n, m, x - 1, y - 1);
                // print_vec(M);
                break;
            default:
                break;
        }
    }
}

```

### 平分物品

现在有 n 个物品，每一个物品都有一个价值，现在想将这些物品分给两个人，要求这两个人每一个人分到的物品的价值总和相同（个数可以不同，总价值相同即可），剩下的物品就需要扔掉，现在想知道最少需要扔多少价值的物品才能满足要求分给两个人。

要求：时间复杂度 $O(3^n)$，空间复杂度 $O(n)$

输入描述：

    第一行输入一个整数 T，代表有 T 组测试数据。
    对于每一组测试数据，一行输入一个整数 n ，代表物品的个数。
    接下来 n 个数，a[i] 代表每一个物品的价值。

    1 <= T <= 10
    1 <= n <= 15
    1 <= a[i] <= 100000

输出描述：

    对于每一组测试数据，输出一个答案代表最少需要扔的价值。
    示例 1
    输入例子：
    1
    5
    30 60 5 15 30
    输出例子： 20
    
例子说明：

    样例解释，扔掉第三个和第四个物品，然后将第一个物品和第五个物品给第一个人，第二个物品给第二个人，每一个人分到的价值为，扔掉的价值为。


```txt
Input:
2
5
30 60 5 15 30
Output:
20
```

```txt
Input:
3
8
442 388 422 856 652 368 49 335  (sum := 3512)
3
44 594 492                      (sum := 1130)
5
480 542 681 863 732             (sum := 3298)
Output:
1892
1130
3298
```

枚举

```cpp
void dfs(std::vector<int> const& in_vec, int p, int n, int drop, int val_1,
         int val_2, int& out_res) {
    if (p == n) {
        if (val_1 == val_2) {
            out_res = std::min(drop, out_res);
        }
        return;
    }
    for (int i = 0; i < 3; ++i) {
        switch (i) {
            case 0:
                dfs(in_vec, p + 1, n, drop + in_vec[p], val_1, val_2, out_res);
                break;
            case 1:
                dfs(in_vec, p + 1, n, drop, val_1 + in_vec[p], val_2, out_res);
                break;
            case 2:
                dfs(in_vec, p + 1, n, drop, val_1, val_2 + in_vec[p], out_res);
                break;
            default:
                break;
        }
    }
}

int min_drop(std::vector<int> const& item) {
    int n = item.size();
    if (n == 1) {
        return item[0];
    }
    if (n == 2) {
        return item[0] == item[1] ? item[0] : item[0] + item[1];
    }
    if (n == 3) {
        auto const& a = item[0];
        auto const& b = item[1];
        auto const& c = item[2];
        if (a + b == c || a + c == b || b + c == a) {
            return 0;
        }
        if (a == b) { return c; }
        if (a == c) { return b; }
        if (b == c) { return a; }
        return a + b + c;
    }

    int res = INT_MAX;
    dfs(item, 0, n, 0, 0, 0, res);
    // std::cout << "res: " << res << std::endl;
    return res;
}

int main() {
    int T;
    std::cin >> T;
    // std::cout << "T: " << T << std::endl;

    for (int t = 0; t < T; ++t) {
        int n;
        std::cin >> n;
        // std::cout << "n: " << n << std::endl;
        std::vector<int> a = std::vector<int>(n, 0);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            sum += a[i];
        }
        auto ans = min_drop(a);
        printf("%d\n", ans);
    }
}
```


### 买票问题

现在有n个人排队买票，已知是早上8点开始卖票，这n个人买票有两种方式：

第一种是每一个人都可以单独去买自己的票，第 i 个人花费 a[i] 秒。

第二种是每一个人都可以选择和自己后面的人一起买票，第 i 个人和第 i+1 个人一共花费 b[i] 秒。

最后一个人只能和前面的人一起买票或单独买票。

由于卖票的地方想早些关门，所以他想知道他最早几点可以关门，请输出一个时间格式形如：08:00:40 am/pm

时间的数字要保持 2 位，若是上午结束，是 am ，下午结束是 pm

时间复杂度 O(n) ,空间复杂度 O(n) 

输入描述：
第一行输入一个整数 T，接下来有 T 组测试数据。

对于每一组测试数据：输入一个数 n，代表有 n 个人买票。

接下来n个数，代表每一个人单独买票的时间 a[i]。

接下来 n-1 个数，代表每一个人和他前面那个人一起买票需要的时间 b[i]
1<= T <=100
1<= n <=2000
1<= a[i] <=50
1<= b[i] <=50

输出描述：
对于每组数据，输出一个时间，代表关门的时间 。
示例1
输入例子：
2
2
20 25
40
1
8
输出例子：
08:00:40 am
08:00:08 am