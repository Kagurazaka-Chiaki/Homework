
//


#include "dplib/solution.hpp"

auto dp::solution::minPathSum(std::vector<std::vector<int>> const &grid) -> int {

    int const m = grid.size();
    if (m == 0) { return 0; }
    int const n = grid[0].size();
    if (n == 0) { return 0; }

    auto dp = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; ++i) {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    }

    for (int i = 1; i < n; ++i) {
        dp[0][i] = grid[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = std::min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
            // std::cout << '[' << grid[i][j] << ']' << '[' << dp[i][j];
        }
        // std::cout << '\n';
    }

    return dp[m - 1][n - 1];

}