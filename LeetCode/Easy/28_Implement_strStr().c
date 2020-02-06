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

/* 超时了！！*/