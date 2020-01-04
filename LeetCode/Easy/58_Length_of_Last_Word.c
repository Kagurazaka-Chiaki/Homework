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