// BM057 岛屿数量

#include "NowCoderTop101.hpp"

#include <array>
#include <vector>

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>>
     * @return int整型
     */

    constexpr static std::array<std::pair<int, int>, 4> dir4 = {
        std::pair<int, int>(0, 1),
        std::pair<int, int>(-1, 0),
        std::pair<int, int>(0, -1),
        std::pair<int, int>(1, 0)
    };

    auto dfs(std::vector<std::vector<char>> &grid, int i, int j) -> void {
        int n      = grid.size();
        int m      = grid.at(0).size();
        grid[i][j] = '0';

        for (auto const &[dx, dy]: dir4) {
            int x = i + dx;
            int y = j + dy;
            if (x < 0 || x > n - 1) { continue; }
            if (y < 0 || y > m - 1) { continue; }
            if (grid[x][y] == '1') {
                dfs(grid, x, y);
            }
        }
    }

    int solve(std::vector<std::vector<char>> &grid) {
        int n = grid.size();
        if (n == 0) { return 0; }
        int m = grid.at(0).size();
        //
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};