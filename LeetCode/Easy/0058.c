/** 
 * 
 * @brief 58. 最后一个单词的长度
 * 
 * https://leetcode-cn.com/problems/length-of-last-word/
 * 
**/

#include <stdio.h>

int lengthOfLastWord(char * s);

int main(void) {
    printf("%d", lengthOfLastWord("Hello World!"));
}

int lengthOfLastWord(char * s) {
    int sum = 0;
    int i = 0;
    int flag = 0;
    while (s[i] != '\0') {
        if (s[i] == ' ') {
            sum = 0;
            flag = 1;
        }
        sum++;
        i++;
    }
    if (flag == 0) {
        return sum;
    } else {
        return sum - 1;
    }
}

int lengthOfLastWord(char * s){
    int len = strlen(s);
    int flag = 0;
    int sumflag = 0;
    int sum = 0;
    for (int i = len - 1; i > -1; i--) {
        if (s[i] != ' ') { flag = 1; }
        if (s[i] == ' ' && flag == 1) { flag = 0; sumflag = 1; }
        //printf("{%d %d} ", flag, sumflag);
        if (flag == 1 && sumflag == 0) { sum++; }
    }
    //printf("\n%d", sum);
    return sum;
}