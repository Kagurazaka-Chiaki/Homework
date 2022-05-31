#include <stdio.h>
#include <stdlib.h>


struct Detail {
    int Value;
};

struct Node {
    struct Detail *Data;
    struct Node *Next;
};

struct List {
    struct Node *Head;
    struct Node *Tail;
};

struct Detail *InitItem(int Data) {
    struct Detail *New = (struct Detail *) malloc(sizeof(struct Detail));
    New->Value = Data;
    return New;
}

struct Node *InitListNode(int Value) {
    struct Node *New = (struct Node *) malloc(sizeof(struct Node));
    New->Data = InitItem(Value);
    New->Next = NULL;
    return New;
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
    Order = length < Order ? length : Order;
    struct Node *pointer = L->Head;
    for (int i = 0; i < length - 1 - 1; i++) {
        pointer = pointer->Next;
    }
    struct Node *flag = pointer->Next;
    pointer->Next = pointer->Next->Next;
    flag->Next = NULL;
    free(flag->Data);
    free(flag);
}

int Insert(struct List *L, int Order, struct Node *Item) {
    int length = ListLength(L);
    Order = length < Order ? length : Order;
    struct Node *pointer = L->Head;
    for (int i = 0; i < Order - 1; i++) {
        pointer = pointer->Next;
    }
    Item->Next = pointer->Next;
    pointer->Next = Item;
    return 0;
}

void PrintList(struct List *L) {
    struct Node *pointer = L->Head;
    while (pointer != NULL) {
        printf("[%d]->", pointer->Data->Value);
        pointer = pointer->Next;
    }
    printf("\n");
}

void FreeList(struct List *L) {
    struct Node *pointer = L->Head;
    while (pointer != NULL) {
        struct Node *flag = pointer;
        pointer = pointer->Next;
        free(flag->Data);
        free(flag);
    }
}

int main(int argc, char const *argv[]) {
    struct List *L = InitList();
    for (int i = 0; i < 4; i++) {
        Append(L, InitListNode(i));
    }
    PrintList(L);
    Delete(L, 7);
    PrintList(L);
    Insert(L, 6, InitListNode(9));
    PrintList(L);
    FreeList(L);
    free(L);
    return 0;
}
