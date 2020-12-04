#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

bool isPalindrome(int x);
void PrintArray(int *Array, int Length);

int main(void) {
    
    printf("{%d}\n", isPalindrome(121));
    return 0;
}

bool isPalindrome(int x) {
    int save = x;

    // if (x > 2147483647 || x < -2147483647) {
    //     return 0;
    // }

    // int flag = 0;
    // if (x < 0) {
    //     x = ~x + 1;
    //     flag = 1;
    // }

    int count = 0;
    for (long i = 1; x >= i; i = i * 10) {
        //printf("%d\n", (((x % (i * 10)) - (x % i)) / i));
        count++;
    }

    int k = 1;
    for (int i = 1; i < count; i++) {
        k = k * 10;
    }
    
    int sum = 0;
    for (long i = 1; x >= i; i = i * 10) {
        // int temp = sum;
        sum = sum + ((((x % (i * 10)) - (x % i)) / i) * (k / i));
        // if (sum - temp != 0) {
        //     return 0;
        // }
    }
    
    // if (flag == 1) {
    //     sum = sum * (-1);
    // }

    if (save != sum) {
        return false;
    } else {
        return true;
    }
}

void PrintArray(int *Array, int Length) {
    for (int i = 0; i < Length; i++) {
        printf("[%d]-", Array[i]);
    }
    printf("$");
}