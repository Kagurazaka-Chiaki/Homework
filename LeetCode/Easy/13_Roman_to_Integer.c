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