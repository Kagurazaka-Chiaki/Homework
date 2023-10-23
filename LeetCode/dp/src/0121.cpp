


#include "dplib/solution.hpp"

auto dp::solution::maxProfit(std::vector<int> &prices) -> int {
    int n = prices.size();
    int cost = 0x3f3f3f3f;
    int profit = -0x3f3f3f3f;
    for (auto const &p: prices) {
        cost = std::min(cost, p);
        profit = std::max(profit, p - cost);
    }
    return profit;
}