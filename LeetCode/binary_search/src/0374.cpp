


#include <bslib/solution.hpp>

auto guess(int num) -> int;

int bs::solution::guessNumber(int n) {
    int left = 1;
    int right = n;
    int ans = -1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (guess(mid) == 0) {
            return mid;
        }
        if (guess(mid) == -1) { // [left, mid]
            right = mid;
        } else if (guess(mid) == 1) { // [mid + 1, right]
            left = mid + 1;
        }
    }
    return ans;
}