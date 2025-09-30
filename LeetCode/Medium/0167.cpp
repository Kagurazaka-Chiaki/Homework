/**
 * 0167. Two Sum II - Input Array Is Sorted
**/

#include <vector>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r) {
            int s = numbers[l] + numbers[r];
            if (s == target) {
                break;
            } else {
                if (s > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return {l + 1, r + 1};
    }
};
