#include <stdio.h>
#include <iostream>

using namespace std;

long mod = 1000000007;

long p[1001], dp[1001], n;

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 2; i <= n + 1; i++) {
        dp[i] = (2 * dp[i - 1] - dp[p[i - 1]] + 2) % mod;
    }
    auto result = dp[n + 1] < 0 ? dp[n + 1] + mod : dp[n + 1];
    std::cout << result << std::endl;
    return 0;
}