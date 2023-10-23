

// 278. 第一个错误的版本

#include "bslib/solution.hpp"


auto isBadVersion(int n) -> bool;

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