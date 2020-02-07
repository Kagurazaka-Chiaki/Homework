int strStr(char * haystack, char * needle){
    if(strlen(needle) == 0) { return 0; }
    int count = 0;
    while (haystack[count] != '\0') {
        int j = 0;
        int i = count;
        int flag = 0;
        while (needle[j] != '\0') {
            if (haystack[i] != needle[j]) { flag = 1; break;}
            i++;
            j++;
        }
        if (flag == 1) { count++; } else { return count; }
    }
    return -1;
}

/* 上面的暴力匹配超时了！！！ */


int *GetNext(char *P);

int strStr(char * haystack, char * needle){
    //printf("[%d %d]\n", strlen(haystack), strlen(needle));
    int len_T = strlen(haystack);
    int len_P = strlen(needle);
    if (len_P == 0) { return 0; }
    int *next = GetNext(needle);
    //for (int i = 0; i < len_P; i++) {
    //    printf("[%d]", next[i]);
    //}
    int i = 0;
    int j = 0;
    while(i < len_T && j < len_P) {
        if (j == -1 || (haystack[i] == needle[j])) {
            i++; j++;
        } else {
            j = next[j];
        }
        if (j == len_P) { return i - j; }
    }
    return -1;
}

int *GetNext(char *P) {
    int len = strlen(P);
    int *next = (int *)malloc(len * sizeof(int));
    int pos = -1;
    next[++pos] = -1;
    int j = 0;
    int k = -1;
    while (j < len -1) {
        if (k == -1 || P[j] == P[k]) {
            j++;
            k++;
            next[++pos] = k;
        } else {
            k = next[k];
        }
    }
    return next;
}