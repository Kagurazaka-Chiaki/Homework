/**
 * 
 * 13. 罗马数字转整数
 * 
 * https://leetcode-cn.com/problems/roman-to-integer/
 * 
**/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int romanToInt(char *s);

int main(void) {

    printf("{%d}\n", 'I'); // 1    73
    printf("{%d}\n", 'V'); // 5    86
    printf("{%d}\n", 'X'); // 10   88
    printf("{%d}\n", 'L'); // 50   76
    printf("{%d}\n", 'C'); // 100  67
    printf("{%d}\n", 'D'); // 500  68
    printf("{%d}\n", 'M'); // 1000 77

    printf("%d", romanToInt("XIX")); // (X IX) (XL V)
                                     // (10 9) (40 5)
    return 0;
}

int romanToInt(char *s) {
    int sum = 0;

    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == 'I') {
            if (s[i+1] == 'V') {
                sum = sum + 4;
                i++;
            } else if (s[i+1] == 'X') {
                sum = sum + 9;
                i++;
            } else {
                sum = sum + 1;
                i++;
            }
        } else if (s[i] == 'V') {
            sum = sum + 5;
            i++;
        } else if (s[i] == 'X') {
            if (s[i+1] == 'L') {
                sum = sum + 40;
                i++;
            } else if (s[i+1] == 'C') {
                sum = sum + 90;
                i++;
            } else {
                sum = sum + 10;
                i++;
            }
        } else if (s[i] == 'L') {
            sum = sum + 50;
            i++;
        } else if (s[i] == 'C') {
            sum = sum + 100;
        } else if (s[i] == 'D') {
            sum = sum + 500;
        } else if (s[i] == 'M') {
            sum = sum + 1000;
        }
        i++;
    }
    
    
    printf("\n");
    return sum;
}

int romanToInt(char * s){
    int len = strlen(s);
    int *sumarray = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) { sumarray[i] = 0; }
    for (int i = len - 1; i > -1; i--) {
        if (s[i] == 'I') {
            sumarray[i] = 1;
        } else if (s[i] == 'V') {
            sumarray[i] = 5;
        } else if (s[i] == 'X') {
            sumarray[i] = 10;
        } else if (s[i] == 'L') {
            sumarray[i] = 50;
        } else if (s[i] == 'C') {
            sumarray[i] = 100;
        } else if (s[i] == 'D') {
            sumarray[i] = 500;
        } else if (s[i] == 'M') {
            sumarray[i] = 1000;
        }
    }
    int sum = sumarray[len - 1];
    //for (int i = 0; i < len; i++) { printf("[%d]", sumarray[i]); }
    int init = sumarray[len - 1];
    for (int i = len - 1 - 1; i > -1; i--) {
        if (sumarray[i] >= init) {
            sum = sum + sumarray[i];
        } else {
            sum = sum - sumarray[i];
        }
        init = sumarray[i];
    }
    return sum;
}