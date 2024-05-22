/**
 * 基于双向链表, 并同时有栈和队列性质的结构
**/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0


struct Detail {
    int Value;
    char *String;
};


struct QuackNode {
    struct Detail *Data;
    struct QuackNode *Next;
    struct QuackNode *Prev;
};


struct Quack {
    int Length;
    struct QuackNode *Head;
    struct QuackNode *Tail;
};


struct Quack *InitQuack(void) {
    struct Quack *New = (struct Quack *) malloc(sizeof(struct Quack));
    New->Head = New->Tail = NULL;
    New->Length = 0;
    return New;
}

struct QuackNode *InitQuackNode(struct Detail *Item) {
    struct QuackNode *NewQuackNode = (struct QuackNode *) malloc(sizeof(struct QuackNode));
    NewQuackNode->Next = NewQuackNode->Prev = NULL;
    NewQuackNode->Data = Item;
    return NewQuackNode;
}

struct Detail *InitDetail(int Data, char *String) {
    struct Detail *New = (struct Detail *) malloc(sizeof(struct Detail));
    New->Value = Data;
    New->String = String;
    return New;
}

struct Detail *QuackPop(struct Quack *Stack) {
    struct QuackNode *flag = Stack->Head;
    struct Detail *PopNode = Stack->Head->Data;
    Stack->Head = Stack->Head->Next;
    if (Stack->Head == NULL) { Stack->Tail = NULL; }
    free(flag);
    Stack->Length--;
    return PopNode;
}

void QuackPush(struct Quack *Stack, struct QuackNode *NewNode) {
    if (Stack->Head == NULL && Stack->Tail == NULL) {
        Stack->Head = Stack->Tail = NewNode;
    } else {
        NewNode->Next = Stack->Head;
        Stack->Head->Prev = NewNode;
        Stack->Head = NewNode;
    }
    Stack->Length++;
}

void QuackEnQueue(struct Quack *Queue, struct QuackNode *NewNode) {
    if (Queue->Head == NULL && Queue->Tail == NULL) {
        Queue->Head = Queue->Tail = NewNode;
    } else {
        NewNode->Prev = Queue->Tail;
        Queue->Tail->Next = NewNode;
        Queue->Tail = NewNode;
    }
    Queue->Length++;
}

struct Detail *QuackDeQueue(struct Quack *Queue) {
    struct QuackNode *flag = Queue->Head;
    struct Detail *LeaveNode = Queue->Head->Data;
    Queue->Head = Queue->Head->Next;
    if (Queue->Head == NULL) { Queue->Tail = NULL; }
    free(flag);
    Queue->Length--;
    return LeaveNode;
}

void ApplyQuackNode(struct Detail *AppliedNode) {
    printf("%s ", AppliedNode->String);
}

void PrintQuack(struct Quack *Q) {
    printf("%p -> {Head %p %d Tail %p} :\n", Q, Q->Head, Q->Length, Q->Tail);
    struct QuackNode *pointer = Q->Head;
    while (pointer != NULL) {
        printf("%p -> {%p %p %p}\n", pointer, pointer->Prev, pointer->Data, pointer->Next);
        pointer = pointer->Next;
    }
}

void FreeQuack(struct Quack *Q) {
    struct QuackNode *pointer = Q->Head;
    while (pointer != NULL) {
        struct QuackNode *flag = pointer;
        pointer = pointer->Next;
        free(flag->Data);
        free(flag);
    }
    Q->Head = Q->Tail = NULL;
}

int main(int argc, char const *argv[]) {
    struct Quack *Q = InitQuack();
    // NOLINTNEXTLINE
    QuackEnQueue(Q, InitQuackNode(InitDetail(1, "A")));
    PrintQuack(Q);
    FreeQuack(Q);
    free(Q);
    return 0;
}