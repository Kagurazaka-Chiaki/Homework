/**
 *
**/


#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int coinChange(vector<int>& coins, int amount) {
    if (coins.empty() || amount < 0) { return -1; }
    if (amount == 0) { return 0; }
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    int result = INF;
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (dp[i] - coins[j]) { continue; }
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];

}

// int main(int argc, char const *argv[]) {
//     (void) argc; (void) argv;
//     /* code */
//     return 0;
// }