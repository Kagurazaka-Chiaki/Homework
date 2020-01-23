#include <stdio.h>

int maxSubArray(int* nums, int numsSize){
    //if (numsSize == 0) { return -2147483648; }

    //if (numsSize == 1) { return nums[0]; }

    int max = -2147483648;
    int current_value = 0;
    for (int i = 0; i < numsSize; i++) {
        current_value = current_value + nums[i];
        if (current_value > max) { max = current_value; }
        if (current_value < 0) { current_value = 0; }
    }

    /*

    int flag = 0;
    for (int i = 0; i < numsSize; i++) { if (nums[i] > 0) { flag = 1; } }
    
    int max = 0;
    if (flag == 1) {
        int current_value = 0;
        for (int i = 0; i < numsSize; i++) {
            current_value = current_value + nums[i];
            if (current_value > max) {
                max = current_value;
            } else if (current_value < 0) {
                current_value = 0;
            }
        }
    } else {
        max = -2147483648;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] > max) { max = nums[i]; }
        }
    }
    
    */

    return max;
}