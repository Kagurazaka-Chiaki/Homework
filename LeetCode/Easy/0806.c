/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){
    int *result = (int *)malloc(2 * sizeof(int));
    int line = 1, prev = -1, curr = 0;
    for (int i = 0; s[i]; i++) {
        int w = widths[s[i] - 'a'];
        if (curr + w > 100) {
            prev = curr;
            curr = w;
            ++line;
        } else {
            curr += w;
        }
    }
    result[0] = line;
    result[1] = curr;
    *returnSize = 2;
    return result;
}