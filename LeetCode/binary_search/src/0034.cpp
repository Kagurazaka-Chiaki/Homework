

#include "bslib/solution.hpp"

#include <iostream>

// 0034. 在排序数组中查找元素的第一个和最后一个位置

auto bs::solution::searchRange(std::vector<int> &nums, int target) -> std::vector<int> {
    int n = nums.size();
    std::cout << "n:" << n << std::endl;
    if (n == 0) {
        return {-1, -1};
    }
    int l = 0;
    int r = n - 1;
    while (l < r) {
        std::cout << "l:" << l << ", r:" << r << std::endl;
        int mid = l + (r - l) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (nums[l] != target) {
        return {-1, -1};
    }
    std::cout << "l:" << l << ", r:" << r << std::endl;
    int a = l;
    for (int i = l; i > -1; --i) {
        if (nums[i] != target) {
            break;
        }
        a = i;
    }
    std::cout << "a:" << a << std::endl;
    int b = r;
    for (int i = r; i < n; ++i) {
        if (nums[i] != target) {
            break;
        }
        b = i;
    }
    std::cout << "b:" << b << std::endl;

    int p = 0;
    int q = n - 1;
    while (p < q) {
        int mid = q - (q - p) / 2;
        if (nums[mid] <= target) {
            p = mid;
        } else {
            q = mid - 1;
        }
        std::cout << "p:" << p << ", q:" << q << std::endl;
    }

    return {-1, -1};
}
