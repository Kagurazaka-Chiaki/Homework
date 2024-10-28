

/**
 *
**/


#include <bslib/solution.hpp>

#include <iostream>
#include <vector>

// add << operator for std::vector
template<typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> const &vec) {
    os << "[";
    if (vec.empty()) { return os << "]"; }
    for (auto const &v: vec) {
        if (&v != &vec.back()) {
            os << v << ", ";
        } else {
            os << v;
        }
    }
    return os << "]";
}

int binary_search_left(std::vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    while (l < r) {
        int m = l + ((r - l) / 2);
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return nums[l] != target ? -1 : l;
}

int binary_search_right(std::vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    while (l < r) {
        int m = r - ((r - l) / 2);
        if (nums[m] <= target) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return nums[r] != target ? -1 : r;
}

auto main(int argc, char const *argv[]) -> int {
    (void) argc;
    (void) argv;
    /* code */

    auto test_vector = std::vector<int>{
        1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 10
    };

    auto bs = bs::solution();

    auto res = bs.searchRange(test_vector, 3);

    std::cout << res << std::endl;

    return 0;
}
