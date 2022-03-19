/**
 * @brief 88. 合并两个有序数组
 * 
 * https://leetcode-cn.com/problems/merge-sorted-array/
 * 
**/

#include <stdio.h>

#define MAX 10

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
void PrintArray(int *Array, int Length);

int main (void) {

    int nums1Size = 6;
    int nums2Size = 6;

    int nums1[MAX] = {1, 2, 3, 0, 0, 0};
    int nums2[MAX] = {2, 5, 6};

    int m = 3;
    int n = 3;

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    PrintArray(nums1, nums1Size);

    return 0;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    
    int k = 0;
    for (int i = m; i < m + n; i++) {
        nums1[i] = nums2[k];
        k++;
    }

    for (int i = 0; i < nums1Size; i++) {
        for (int j = i; j > 0; j--) {
            if (nums1[j] < nums1[j-1]) {
                nums1[j] = nums1[j] + nums1[j-1];
                nums1[j-1] = nums1[j] - nums1[j-1];
                nums1[j] = nums1[j] - nums1[j-1];
            }
        }
    }
}

void PrintArray(int *Array, int Length) {
    for (int i = 0; i < Length; i++) {
        printf("[%d]-", Array[i]);
    }
    printf("$");
}