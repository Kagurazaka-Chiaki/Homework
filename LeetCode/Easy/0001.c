#include <stdio.h>
#include <stdlib.h>


#define SIZE 100

int *twoSum(int *nums, int numsSize, int target, int *returnSize);
void PrintArray(int *Array, int Length);

int main(void) {

    int nums[SIZE] = {2, 7, 11, 15, 6, 3};
    int target = 9;
    int *returnSize;

    printf("%d\n", nums[0]);

    int *p = twoSum(nums, SIZE, target, returnSize);
    printf("\n----------\n");
    PrintArray(p, 4);

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int *List = (int *) malloc(80000 * sizeof(int));
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int diff = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == diff) {
                int countplus = count + 1;
                //printf("[%d %d %d %d %d]-", diff, i, nums[i], nums[j], j);
                //printf("%d %d", count, countplus);
                //printf("[%d %d]\n", count, i);
                //printf("[%d %d]\n", countplus, j);
                List[count] = i;
                List[countplus] = j;
                count = count + 2;
            }
        }
    }
    *returnSize = count;
    return List;
}

void PrintArray(int *Array, int Length) {
    for (int i = 0; i < Length; i++) {
        printf("[%d]-", Array[i]);
    }
    printf("$");
}