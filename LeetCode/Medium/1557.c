/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 入度为 0 的点
int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int *result = (int *)malloc(n * sizeof(int));
    int degree[100006];
    memset(degree, 0, sizeof(degree));
    *returnSize = 0;
    for (int i = 0; i < edgesSize; i++) {
        ++degree[edges[i][1]];
    }
    for (int i = 0; i < n; i++) {
        if (degree[i] == 0) {
            result[(*returnSize)++] = i;
        }
    }
    return result;
}