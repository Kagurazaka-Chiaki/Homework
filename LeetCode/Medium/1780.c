
#include <stdbool.h>

bool checkPowersOfThree(int n){
    // int a[16], size = 0;
    // a[size++] = 1;
    // for (int i = 0; i <= n; i++) {
    //     a[size] = a[size - 1] * 3;
    //     ++size;
    //     if (a[size - 1] >= n) {
    //         break;
    //     }
    // }
    // for (int i = 0; i < size; i++) {
    //     printf("%d,", a[i]);
    // }

    int a[16] = {
        1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683,
        59049, 177147, 531441, 1594323, 4782969, 14348907
    };
    int size = 16;
    for (int i = 0; i < (1 << size); i++) {
        int ans = 0;
        for (int j = 0; j < size; j++) {
            if ((1<<j) & i) {
                ans += a[j];
            }
        }
        if (ans == n) {
            return true;
        }
    }
    return false;
}