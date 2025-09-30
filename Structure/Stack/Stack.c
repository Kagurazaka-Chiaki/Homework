#include <stdio.h>
#include <stdlib.h>

#define MAX 2

struct Stack {
    int *Data;
    int  Pos;
    int  Size;
};

struct Stack *InitStack(void) {
    struct Stack *S = (struct Stack *) malloc(sizeof(struct Stack));
    S->Data         = (int *) malloc(MAX * sizeof(int));
    S->Size         = MAX;
    S->Pos          = -1;
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
    S->Data    = realloc(S->Data, (--(S->Size)) * sizeof(int));
    // printf("|size %llu|", sizeof(S->Data));
    return Result;
}

void FreeStack(struct Stack *S) {
    free(S->Data);
    free(S);
}

struct Queue {
    struct Stack *S1;
    struct Stack *S2;
};

void EnQueue(struct Queue *Q, int value) {
    PushStack(Q->S1, value);
}

int DeQueue(struct Queue *Q) {
    if (Q->S2->Pos == -1) {
        while (Q->S1->Pos != -1) {
            PushStack(Q->S2, PopStack(Q->S1));
        }
    }
    return PopStack(Q->S2);
}

int main(int argc, char const *argv[]) {

    struct Stack *S         = InitStack();
    int           Array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("|%d %d|\n", Array[9], *(Array + 10));
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
    printf("S->Data[9] = %d\n", S->Data[9]);
    FreeStack(S);
    printf("----- Queue via Stack -----\n");
    struct Queue *Q = (struct Queue *) malloc(sizeof(struct Queue));
    Q->S1          = InitStack();
    Q->S2          = InitStack();
    for (int i = 0; i < 10; i++) { EnQueue(Q, Array[i]); }
    for (int i = 0; i < 10; i++) { printf("DeQueue %d \n", DeQueue(Q)); }
    FreeStack(Q->S1);
    FreeStack(Q->S2);
    free(Q);
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