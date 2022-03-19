/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int is_exist(int* nums, int numsSize, int target) {
    int result = 0;
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] == target) {
            result++;
            break;
        }
    }
    return result;
}

int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize){

    int *result = (int *)malloc(300 * sizeof(int));
    *returnSize = 0;
    for (int i = 1; i <= 100; i++) {
        int count = 0;
        count += is_exist(nums1, nums1Size, i);
        count += is_exist(nums2, nums2Size, i);
        count += is_exist(nums3, nums3Size, i);
        if (count >= 2) {
            result[(*returnSize)++] = i;
        }
    }
    return result;
}
