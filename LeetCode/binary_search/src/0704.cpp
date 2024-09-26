
/**
 *
**/

#include <vector>

class Solution {
  public:
    int search(std::vector<int> &nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int middle = (left + right) >> 1;
            if (nums[middle] >= target) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return nums[left] == target ? left : -1;
    }
};

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    return 0;
}
