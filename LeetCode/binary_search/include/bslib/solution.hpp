
#ifndef BS_SOLUTION_HPP
#define BS_SOLUTION_HPP

#include <vector>

namespace bs {
    class solution {
      public:
        solution() = default;

        // 0034. 在排序数组中查找元素的第一个和最后一个位置
        auto searchRange(std::vector<int> &nums, int target) -> std::vector<int>;

        // 0035. 搜索插入位置
        auto searchInsert(std::vector<int> &nums, int target) -> int;


        // 0268. 丢失的数字
        auto missingNumber(std::vector<int> &nums) -> int;


        // 0278. 第一个错误的版本
        auto firstBadVersion(int n) -> int;


        // 0374. 猜数字大小
        auto guessNumber(int n) -> int;
    };
} // namespace bs

#endif // BS_SOLUTION_HPP
