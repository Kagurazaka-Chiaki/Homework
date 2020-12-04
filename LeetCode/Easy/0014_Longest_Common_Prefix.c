char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) { return ""; }
    char *LCP = strs[0];
    //printf("[%s]\n", LCP);
    int j = 0;
    for (int i = 1; i < strsSize; i++) {
        j = 0;
        while (LCP[j] != '\0' && strs[i][j] != '\0') {
            if (LCP[j] != strs[i][j]) { break; }
            j++;
        }
        LCP[j] = '\0';
        if (LCP == ((void *)0)) { return ""; }
    }
    return LCP;
}