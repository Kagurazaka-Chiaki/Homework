#include <stdio.h>
#include <stdlib.h>

#define MAX 2

struct Stack {
    int *Data;
    int Pos;
    int Size;
};

struct Stack *InitStack(void) {
    struct Stack *S = (struct Stack *) malloc(sizeof(struct Stack));
    S->Data = (int *) malloc(MAX * sizeof(int));
    S->Size = MAX;
    S->Pos = -1;
    return S;
}

// if (S->Pos + 1 > S->Size - 1) { ... }
struct Stack *ReStack(struct Stack *S) {
    S->Size = 1 + S->Size;
    S->Data = (int *) realloc(S->Data, S->Size * sizeof(int));
    for (int i = S->Pos + 1; i < S->Size; i++) { S->Data[i] = 0; }
    return S;
}

void PrintStack(struct Stack *S) {
    for (int i = 0; i < S->Pos + 1; i++) { printf("[%d]", S->Data[i]); }
    printf("\n{Pos = %d, Size = %d}\n", S->Pos, S->Size);
}

void PushStack(struct Stack *S, int value) {
    if (S->Pos + 1 > S->Size - 1) { ReStack(S); }
    S->Data[++(S->Pos)] = value;
}

int PopStack(struct Stack *S) {
    int Result = S->Data[(S->Pos)--];
    realloc(S->Data, (--(S->Size)) * sizeof(int));
    printf("|size %d|", sizeof(S->Data));
    return Result;
}

void FreeStack(struct Stack *S) {
    free(S->Data);
    free(S);
}

int main(int argc, char const *argv[]) {

    struct Stack *S = InitStack();
    int Array[10] = { 1, 2, 3, 4, 5, 6, 7, 8 ,9 , 10 };
    printf("|%d %d|\n", Array[9], Array[10]);
    for (int i = 0; i < 10; i++) {
        PushStack(S, Array[i]);
        // if (S->Pos + 1 > S->Size - 1) { ReStack(S); }
        // S->Data[++(S->Pos)] = Array[i];
    }
    PrintStack(S);
    printf("Pop %d \n", PopStack(S));
    printf("Pop %d \n", PopStack(S));
    printf("Pop %d \n", PopStack(S));
    PrintStack(S);
    printf("S->Data[9] = %d", S->Data[9]);
    return 0;
}

/*int main(void) {

    char input_char[MAX];
    memset(input_char, '\0', sizeof(input_char));
    while (fgets(input_char, MAX, stdin)) {
        for (int i = strlen(input_char) - 2; i >= 0; i--) {
            printf("%c", input_char[i]);
        }
        printf("\n");
    }

    return 0;
}*/