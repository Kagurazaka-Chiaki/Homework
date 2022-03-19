/**
 * @brief 35. 搜索插入位置
 * 
 * https://leetcode-cn.com/problems/search-insert-position/
 * 
**/

int searchInsert(int* nums, int numsSize, int target){
    int pos = 0;
    int flag1 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            pos = i;
            flag1 = 1;
        }
    }
    if (flag1 == 0) {
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] < target) {
                pos = i + 1;
            }
        }
    }
    return pos;
}
