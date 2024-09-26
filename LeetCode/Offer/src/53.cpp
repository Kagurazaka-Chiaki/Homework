
/**
 *
**/


#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
  public:
    int missingNumber(std::vector<int> &nums) {
        int biggest = nums.size() + 1;
        int assume_sum = biggest * (biggest - 1) / 2;
        int given_sum = 0;
        for (int i: nums) {
            given_sum = given_sum + i;
        }
        int result = assume_sum - given_sum;

        // std::cout << assume_sum  << given_sum << std::endl;

        return result;
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    (void) argc;
    (void) argv;
    return 0;
}
