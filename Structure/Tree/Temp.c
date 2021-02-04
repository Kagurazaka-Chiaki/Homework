#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LEN 20

void b_sort(void *bs, size_t num, size_t size, int (*compar)(const void *, const void *)) {
    int sorted = 0;
    char *base = (char *) bs;    // void * 算术运算g++会发出警告，为了消除警告，强制转换成char*
    void *ptmp = malloc(size);
    for (; !sorted; num--) {
        sorted = 1;     // 每一趟都假设排序好了
        for (size_t i = 1; i < num; i++)
            if (compar(base + i * size, base + (i - 1) * size) < 0) {
                sorted = 0;
                memcpy(ptmp, base + i * size, size);
                memcpy(base + i * size, base + (i - 1) * size, size);
                memcpy(base + (i - 1) * size, ptmp, size);
            }
    }
    free(ptmp);
}


int compar(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

// 主函数
int main() {
    int max = 100, min = 1;
    int v[LEN];

    srand(time(NULL));

    for (int i = 0; i < LEN; i++) {
        v[i] = rand() % max + min;
        printf("%d %s", v[i], i == LEN - 1 ? "\n" : "");
    }

    b_sort(v, LEN, sizeof(int), compar);

    for (int i = 0; i < LEN; i++)
        printf("%d %s", v[i], i == LEN - 1 ? "\n" : "");

    return 0;
}