/**
 * 2327. Number of People Aware of a Secret
**/
#include <vector>

class Solution {

    unsigned int const M = 1000000007;

  public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        if (n < 1) { return 0; }
        if (n == 1 || n == 2) { return n; }
        std::vector<long long> day(n + 1, 0);
        day[1]        = 1;
        long long ans = 0;
        for (int i = 1; i < n + 1; ++i) {
            if (i >= n - forget + 1) {
                ans += day[i];
            }
            for (int j = i + delay; j <= std::min(i + forget - 1, n); ++j) {
                day[j] = (day[i] + day[j]) % M;
            }
        }
        return ans % M;
    }
};