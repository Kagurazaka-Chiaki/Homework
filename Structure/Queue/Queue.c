#include <stdio.h>
#include <stdlib.h>

#define MAX 1

struct Queue {
    int *Data;
    int Head;
    int Tail;
    int Size;
};

struct Queue *InitQueue(void) {
    struct Queue *Q = (struct Queue *) malloc(sizeof(struct Queue));
    Q->Data = (int *) malloc(MAX * sizeof(int));
    Q->Head = Q->Tail = -1;
    Q->Size = MAX;
    return Q;
}

// if (Q->Tail + 1 > Q->Size - 1) { ... }
struct Queue *ReQueue(struct Queue *Q) {
    Q->Size = 1 + Q->Size;
    Q->Data = (int *) realloc(Q->Data, Q->Size * sizeof(int));
    for (int i = Q->Tail + 1; i < Q->Size; i++) { Q->Data[i] = 0; }
    return Q;
}

void PrintQueue(struct Queue *Q) {
    for (int i = Q->Head + 1; i < Q->Tail + 1; i++) { printf("[%d]", Q->Data[i]); }
    printf("\n{Head = %d Size = %d Tail = %d}\n", Q->Head, Q->Size, Q->Tail);
}

void JoinQueue(struct Queue *Q, int value) {
    if (Q->Tail + 1 > Q->Size - 1) { ReQueue(Q); }
    Q->Data[++(Q->Tail)] = value;
}

int LeaveQueue(struct Queue *Q) {
    int Result = Q->Data[++(Q->Head)];
    realloc(Q->Data, (--(Q->Size)) * sizeof(int));
    return Result;
}

void FreeQueue(struct Queue *Q) {
    free(Q->Data);
    free(Q);
}

int main(int argc, char const *argv[]) {

    struct Queue *Q = InitQueue();
    int Array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printf("|%d %d|\n", Array[9], Array[10]);
    for (int i = 0; i < 10; i++) {
        JoinQueue(Q, Array[i]);
    }
    PrintQueue(Q);
    printf("Leave %d\n", LeaveQueue(Q));
    PrintQueue(Q);
    printf("Leave %d\n", LeaveQueue(Q));
    PrintQueue(Q);
    printf("%d", Q->Data[0]);
    return 0;
}
