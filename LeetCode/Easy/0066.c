/**
 * @brief 66. 加一
 * 
 * https://leetcode-cn.com/problems/plus-one/
 * 
**/

/**
 * Note: The returned array must be malloced, assume caller calls free().
**/
int* plusOne(int* digits, int digitsSize, int* returnSize){
    //printf("%d\n", digits[digitsSize - 1]);
    if (digits[digitsSize - 1] < 9) {
        digits[digitsSize - 1]++;
        *returnSize = digitsSize;
        return digits;
    } else {
        int *carry = (int *)malloc((digitsSize + 1) * sizeof(int));
        for (int i = 0; i < digitsSize + 1; i++) { carry[i] = 0; }
        digits[digitsSize - 1]++;
        for (int i = digitsSize - 1; i > -1; i--) {
            digits[i] = digits[i] + carry[i + 1];
            if (digits[i] > 9) { carry[i]++; digits[i] = digits[i] - 10; }
        }
        if (carry[0] == 0) {
            *returnSize = digitsSize;
            return digits;
        } else {
            int *Newdigits = (int *)malloc((digitsSize + 1) * sizeof(int));
            Newdigits[0] = 1;
            for (int i = 1; i < digitsSize + 1; i++) { Newdigits[i] = 0; }
            *returnSize = digitsSize + 1;
            return Newdigits;
        }
    }
}