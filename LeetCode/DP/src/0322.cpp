/**
 *
**/


#include "dplib/solution.hpp"

inline int const INF = 0x3f3f3f3f;

auto dp::solution::coinChange(std::vector<int> const &coins, int amount) -> int {
    if (coins.empty() || amount < 0) { return -1; }
    if (amount == 0) { return 0; }
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    int result = INF;
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (dp[i] - coins[j]) { continue; }
            dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}
