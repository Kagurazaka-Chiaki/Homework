#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node *Next;
};

struct List {
    struct Node *Head;
    struct Node *Tail;
};

struct Node *InitListNode(int Value) {
    struct Node *NewNode = (struct Node *) malloc(sizeof(struct Node));
    NewNode->Data = Value;
    NewNode->Next = NULL;
    return NewNode;
}

struct List *InitList() {
    struct List *L = (struct List *) malloc(sizeof(struct List));
    L->Head = L->Tail = NULL;
    return L;
}

int ListLength(struct List *L) {
    int count = 0;
    struct Node *pointer = L->Head;
    while (pointer != NULL) {
        count++;
        pointer = pointer->Next;
    }
    return count;
}

void Append(struct List *L, struct Node *Item) {
    if (L->Head == NULL && L->Tail == NULL) {
        L->Head = L->Tail = Item;
    } else {
        L->Tail->Next = Item;
        L->Tail = L->Tail->Next;
    }
}

void Delete(struct List *L, int Order) {

    int length = ListLength(L);

    struct Node *pointer = L->Head;
    for (int i = 0; i < length - 1 - 1; i++) {
        pointer = pointer->Next;
    }

    struct Node *flag = pointer->Next;
    pointer->Next = pointer->Next->Next;
    flag->Next = NULL;
    free(flag);

}

void PrintList(struct List *L) {
    struct Node *pointer = L->Head;
    while (pointer != NULL) {
        printf("[%d]->", pointer->Data);
        pointer = pointer->Next;
    }
    printf("\n");
}


void FreeList(struct List *L) {
    struct Node *pointer = L->Head;
    while (pointer != NULL) {
        struct Node *flag = pointer;
        pointer = pointer->Next;
        free(flag);
    }
}

int main(int argc, char const *argv[]) {
    struct List *L = InitList();
    for (int i = 0; i < 2; i++) {
        Append(L, InitListNode(i));
    }
    PrintList(L);
    Delete(L, 7);
    PrintList(L);
    FreeList(L);
    free(L);
    return 0;
}
