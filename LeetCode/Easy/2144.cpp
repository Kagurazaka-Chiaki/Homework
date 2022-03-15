#include <algorithm>
#include <vector>

class Solution {
public:

    static int cmp(const int *a, const int *b) {
        return - *(int *) a + *(int *) b;
    }

    int minimumCost(std::vector<int>& cost) {
        int ans = 0;
        std::sort(cost.rbegin(), cost.rend());
        for (int i = 0; i < cost.size(); ++i) {
            ans += cost[i];
            if (i + 1 < cost.size()) {
                ans += cost[i + 1];
            } else {
                break;
            }
            i += 2;
        }
        return ans;
    }
};