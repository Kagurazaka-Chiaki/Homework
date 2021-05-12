
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1


struct Detail {
    int Value;
};

struct Node {
    pthread_mutex_t *mutex;
    struct Detail *Data;
    struct Node *Prev;
    struct Node *Next;
};

struct Queue {
    int Length;
    struct Node *Head;
    struct Node *Tail;
};



struct Detail *InitItem(int Data) {
    struct Detail *New = (struct Detail *) malloc(sizeof(struct Detail));
    New->Value = Data;
    return New;
}

struct Queue *InitQueue() {
    struct Queue *New = (struct Queue *)malloc(sizeof(struct Queue));
    New->Head = New->Tail = NULL;
    New->Length = 0;
    return New;
}

struct Node *InitQueueNode(int Value) {
    struct Node *New = (struct Node *)malloc(sizeof(struct Node));
    New->Prev = New->Next = NULL;
    New->Data = InitItem(Value);
    return New;
}

struct Queue *ReQueue(struct Queue *Q) { }

void JoinQueue(struct Queue *Q, struct Node *Item) {
    if (Q->Head == NULL && Q->Tail == NULL) {
        Q->Head = Q->Tail = Item;
    } else {
        Item->Next = Q->Head;
        Q->Head->Prev = Item;
        Q->Head = Item;
    }
    Q->Length++;
}

struct Node *LeaveQueue(struct Queue *Q) {
    if (Q->Length == 0) { return NULL; }

    struct Node *Result = NULL;

    if (Q->Length == 1) {
        Result = Q->Head;
        Q->Head = Q->Tail = NULL;
        Result->Prev = Result->Next = NULL;
    } else {
        Result = Q->Head;
        Q->Head = Q->Head->Next;
        Q->Head->Prev = NULL;
        Result->Next = NULL;
    }
    Q->Length--;
    return Result;
}

void PrintQueueNode(struct Node *Item) {
    printf("%p [%d] %p\n", Item->Prev, Item->Data->Value, Item->Next);
}

void PrintQueue(struct Queue *Q) {
    struct Node *pointer = Q->Head;
    while (pointer != NULL) {
        PrintQueueNode(pointer);
        printf("%d", Q->Length);
        pointer = pointer->Next;
    }
}

void FreeQueueNode(struct Node *Item) {
    free(Item->Data);
}

void FreeQueue(struct Queue *Q) {
    struct Node *temp = NULL;
    while (Q->Length != 0) {
        temp = LeaveQueue(Q);
        FreeQueueNode(temp);
        free(temp);
    }
}


int main(int argc, char const *argv[]) {
    struct Queue *Q = InitQueue();
    int Array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int i = 0; i < 10; i++) {
        struct Node *N = InitQueueNode(Array[i]);
        JoinQueue(Q, N);
        PrintQueue(Q);
        printf("%d", Q->Length);
        printf("---\n");
    }
    // struct Node *L = LeaveQueue(Q);
    // PrintQueueNode(L);
    // PrintQueue(Q);
    // JoinQueue(Q, L);
    FreeQueue(Q);
    free(Q);
    return 0;
}