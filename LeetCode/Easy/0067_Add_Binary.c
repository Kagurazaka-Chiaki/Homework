char * addBinary(char * a, char * b){    
    int Apos = strlen(a);
    int Bpos = strlen(b);
    
    int A = 0;
    int B = 0;

    int Lpos = 0;
    if (Apos > Bpos) { Lpos = Apos; } else { Lpos = Bpos; }
    
    char *C = (char *)malloc(80000 * sizeof(char));
    memset(C, '0', sizeof(C));
    C[Lpos + 1 + 1] = '\0';

    char *S = (char *)malloc(80000 * sizeof(char));
    memset(S, '0', sizeof(S));
    S[Lpos + 1 + 1] = '\0';

    for (int i = Lpos + 1; i > -1; i--) {
        if (i == Lpos + 1) {
            C[i] = '0';
            S[i] = '0';
        } else {
            if (Apos > 0) { A = (a[--Apos] - '0'); } else { A = 0; }
            if (Bpos > 0) { B = (b[--Bpos] - '0'); } else { B = 0; }
            C[i] = ('0' + (((C[i + 1] - '0') & (A ^ B)) | (A & B)));
            S[i] = ((A ^ B ^ (C[i + 1] - '0')) + '0');
        }
    }
    
    if (C[1] == '1') {
        S[Lpos + 1] = '\0';
    } else {
        for (int i = 0; i < Lpos + 1; i++) {
            S[i] = S[i + 1];
        }
        S[Lpos] = '\0';
    }
    return S;
}