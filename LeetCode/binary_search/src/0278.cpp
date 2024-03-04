

// 278. 第一个错误的版本

#include "bslib/solution.hpp"

#include <cstdlib>

auto isBadVersion(int n) -> bool {
    return std::rand() % 2 == 0 ? true : false;
}

auto bs::solution::firstBadVersion(int n) -> int {
    int left = 1;
    int right = n;
    while (left < right) {
        int mid = ((right - left) >> 1) + left;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}