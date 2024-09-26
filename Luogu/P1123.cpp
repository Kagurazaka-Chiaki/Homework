
#include <cstring>
#include <iostream>

// 方向数组用来控制搜索时的方向
int const d[8][2] = {
        1, 0,
        -1, 0,
        0, 1,
        0, -1,
        1, 1,
        -1, 1,
        1, -1,
        -1, -1
};
int t, n, m, s[8][8], mark[8][8], ans, mx;

void dfs(int x, int y) {
    if (y == m + 1) {
        dfs(x + 1, 1);
        return;
    }
    if (x == n + 1) {
        mx = std::max(ans, mx);
        return;
    }

    dfs(x, y + 1);

    if (mark[x][y] == 0) {
        ans += s[x][y];
        for (int fx = 0; fx < 8; ++fx) {
            ++mark[x + d[fx][0]][y + d[fx][1]];
        }
        dfs(x, y + 1);
        for (int fx = 0; fx < 8; ++fx) {
            --mark[x + d[fx][0]][y + d[fx][1]];
        }
        ans -= s[x][y];
    }
}

int main() {
    std::cin >> t;
    while (t--) {
        memset(s, 0, sizeof(s));
        memset(mark, 0, sizeof(mark));
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                std::cin >> s[i][j];
            }
        }
        mx = 0;
        dfs(1, 1);
        printf("%d\n", mx);
    }
    return 0;
}
