/**
 * Note: The returned array must be malloced, assume caller calls free().
**/

int* memLeak(int memory1, int memory2, int* returnSize) {
    int *result = (int *)malloc(3 * sizeof(int));

    int time = 1;
    while(true) {
        if (memory1 >= memory2) {
            if (time <= memory1) {
                memory1 -= time;
            } else {
                break;
            }
        } else {
            if (time <= memory2) {
                memory2 -= time;
            } else {
                break;
            }
        }
        time++;
    }
    result[0] = time;
    result[1] = memory1;
    result[2] = memory2;

    *returnSize = 3;
    return result;
}
