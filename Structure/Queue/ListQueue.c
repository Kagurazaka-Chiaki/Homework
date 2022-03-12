
#include <stdio.h>
#include <stdlib.h>
// #include <pthread.h>
#include <stdbool.h>

#define MAX 1


struct Detail {
    int Value;
};

struct Node {
    // pthread_mutex_t *mutex;
    struct Detail *Data;
    struct Node *Prev;
    struct Node *Next;
};

struct Queue {
    int Length;
    struct Node *Head;
    struct Node *Tail;
};

void PrintQueueNode(struct Node *Item) {
    printf("%p -> {%p [%d] %p}\n", Item, Item->Prev, Item->Data->Value, Item->Next);
}

void PrintQueue(struct Queue *Q) {
    struct Node *pointer = Q->Head;
    printf("Length: %d | Head: %p | Tail: %p\n", Q->Length, Q->Head, Q->Tail);
    while (pointer != NULL) {
        PrintQueueNode(pointer);
        pointer = pointer->Next;
    }
}

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

void AppendQueue(struct Queue *Q, struct Node *Item) {
    Item->Prev = Q->Tail;
    Q->Tail->Next = Item;
    Q->Tail = Item;
}

void Insert(struct Queue *Q, struct Node *Item) {
    if (Q->Head == NULL && Q->Tail == NULL) {
        Q->Head = Q->Tail = Item;
    } else if (Q->Head->Data->Value >= Item->Data->Value) {
        Item->Next = Q->Head;
        Q->Head->Prev = Item;
        Q->Head = Item;
    } else if (Q->Tail->Data->Value <= Item->Data->Value) {
        Item->Prev = Q->Tail;
        Q->Tail->Next = Item;
        Q->Tail = Item;
    } else {
        struct Node *pointer = Q->Head;
        while (pointer != NULL) {
            if (pointer->Data->Value > Item->Data->Value) {
                Item->Next = pointer;
                Item->Prev = pointer->Prev;
                pointer->Prev->Next = Item;
                pointer->Prev = Item;
                break;
            }
            pointer = pointer->Next;
        }
    }
    Q->Length++;
}

bool is_equal(struct Node *A, struct Node *B) {
    return (A->Data->Value == B->Data->Value);
}

struct Node *SearchQueue(struct Queue *Q, struct Node *Target) {
    struct Node *Result = NULL;
    struct Node *pointer = Q->Head;
    while (pointer != NULL) {
        if (is_equal(pointer, Target) == true) {
            Result = pointer;
            break;
        }
        pointer = pointer->Next;
    }
    return Result;
}

void DeleteQueue(struct Queue *Q, struct Node *Target) {
    struct Node *flag = SearchQueue(Q, Target);
    printf("Find: ");
    PrintQueueNode(flag);
    if (flag->Prev == NULL && flag->Next == NULL) {
        Q->Head = Q->Tail = NULL;
    } else if (flag->Prev == NULL && flag->Next != NULL) {
        Q->Head = Q->Head->Next;
        Q->Head->Prev = flag->Next = NULL;
    } else if (flag->Next == NULL && flag->Prev != NULL) {
        Q->Tail = Q->Tail->Prev;
        Q->Tail->Next = flag->Prev = NULL;
    } else {
        flag->Prev->Next = flag->Next;
        flag->Next->Prev = flag->Prev;
    }
    Q->Length--;
    free(flag->Data);
    free(flag);
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
    int Array[MAX] = { 10 };
    for (int i = 0; i < MAX; i++) {
        struct Node *N = InitQueueNode(Array[i]);
        // JoinQueue(Q, N);
        Insert(Q, N);
        // PrintQueue(Q);
        printf("%d", Q->Length);
        printf("---\n");
    }
    PrintQueue(Q);
    struct Node *L = InitQueueNode(10);
    struct Node *R = SearchQueue(Q, L);
    printf("R: ");
    PrintQueueNode(R);
    DeleteQueue(Q, L);
    PrintQueue(Q);
    // JoinQueue(Q, L);
    FreeQueueNode(L);
    free(L);
    FreeQueue(Q);
    free(Q);
    return 0;
}