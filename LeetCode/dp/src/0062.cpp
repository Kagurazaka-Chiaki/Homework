

#include <vector>

int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) { return 0; }
    if (m == 1 && n == 1) { return 1; }
    // C_{m + n - 2}^{m - 1}
    auto dp = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            // std::cout << '[' << dp[i][j] << ']';
        }
        // std::cout << '\n';
    }
    return dp[m - 1][n - 1];
}