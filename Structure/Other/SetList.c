/**
 * 集合链表的结构
**/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

struct ListNode {
    int Index;
    char *String;
    struct ListNode *Next;
};

struct ListNodeRep {
    int Length;
    struct ListNode *Head;
    struct ListNode *Tail;
};

struct SetNode {
    struct ListNodeRep *Table;
    struct SetNode *Next;
};

struct SetNodeRep {
    struct SetNode *Head;
    struct SetNode *Tail;
};

struct SetNodeRep *InitSetNodeRep(void) {
    struct SetNodeRep *New = (struct SetNodeRep *) malloc(sizeof(struct SetNodeRep));
    New->Head = New->Tail = NULL;
    return New;
}

struct SetNode *InitSetNode(struct ListNodeRep *List) {
    struct SetNode *New = (struct SetNode *) malloc(sizeof(struct SetNode));
    New->Table = List;
    New->Next = NULL;
    return New;
}

struct ListNodeRep *InitListNodeRep(void) {
    struct ListNodeRep *New = (struct ListNodeRep *) malloc(sizeof(struct ListNodeRep));
    New->Head = New->Tail = NULL;
    New->Length = 0;
    return New;
}

struct ListNode *InitListNode(char *Word) {
    struct ListNode *New = (struct ListNode *) malloc(sizeof(struct ListNode));
    New->String = Word;
    New->Next = NULL;
    New->Index = 1;
    return New;
}

void PrintList(struct ListNodeRep *List) {
    printf("{ List %p Head %p Tail %p Length %d }\n", List, List->Head, List->Tail, List->Length);
    struct ListNode *pointer = List->Head;
    while (pointer != NULL) {
        printf("%p -> {%s %d %p}\n", pointer, pointer->String, pointer->Index, pointer->Next);
        pointer = pointer->Next;
    }
}

void PrintSet(struct SetNodeRep *Set) {
    struct SetNode *pointer = Set->Head;
    while (pointer != NULL) {
        printf("{ Set : %p -> [%p %p] }\n", pointer, pointer->Table, pointer->Next);
        PrintList(pointer->Table);
        pointer = pointer->Next;
    }
}

void FreeList(struct ListNodeRep *List) {
    struct ListNode *pointer = List->Head;
    while (pointer != NULL) {
        struct ListNode *flag = pointer;
        pointer = pointer->Next;
        free(flag->String);
        free(flag);
    }
    free(List);
}

void FreeSet(struct SetNodeRep *Set) {
    struct SetNode *pointer = Set->Head;
    while (pointer != NULL) {
        struct SetNode *flag = pointer;
        pointer = pointer->Next;
        FreeList(flag->Table);
        free(flag);
    }
}

void AppendSet(struct SetNodeRep *Set, struct SetNode *NewNode) {
    if (Set->Head == NULL && Set->Tail == NULL) {
        Set->Head = Set->Tail = NewNode;
    } else {
        Set->Tail->Next = NewNode;
        Set->Tail = Set->Tail->Next;
    }
}

void AppendList(struct ListNodeRep *List, struct ListNode *NewNode) {
    if (List->Head == NULL && List->Tail == NULL) {
        List->Head = List->Tail = NewNode;
    } else {
        NewNode->Index = List->Tail->Index + 1;
        List->Tail->Next = NewNode;
        List->Tail = List->Tail->Next;
    }
    List->Length++;
}

char *CopyCharPointer(char *OriginalChar) {
    char *Copy = (char *) malloc(MAX * sizeof(char));
    strcpy(Copy, OriginalChar);
    return Copy;
}

struct ListNode *MergeList(struct ListNode *List1, struct ListNode *List2) {
    if (List1 == NULL) { return List2; }
    if (List2 == NULL) { return List1; }
    // if ( List1->PageRankWeight - List2->PageRankWeight < 0) {
    if (strcmp(List1->String, List2->String) < 0) {
        // printf("1, {%p %lf}\n", List1, List1->String);
        List1->Next = MergeList(List1->Next, List2);
        return List1;
    } else {
        // printf("2, {%p %lf}\n", List2, List2->String);
        List2->Next = MergeList(List1, List2->Next);
        return List2;
    }
}

struct ListNode *MergeSort(struct ListNode *Original) {
    if (Original == NULL || Original->Next == NULL) { return Original; }
    struct ListNode *fast = Original;
    struct ListNode *slow = Original;
    struct ListNode *break_point = NULL;
    while (fast != NULL && fast->Next != NULL) {
        break_point = slow;
        slow = slow->Next;
        fast = fast->Next->Next;
    }
    break_point->Next = NULL;
    struct ListNode *right = MergeSort(slow);
    struct ListNode *left = MergeSort(Original);
    return MergeList(left, right);
}

struct ListNodeRep *SortList(struct ListNodeRep *Original) {
    struct ListNode *head = Original->Head;
    head = (head == NULL) ? NULL : MergeSort(head);
    struct ListNode *pointer = head;
    while (pointer->Next != NULL) { pointer = pointer->Next; }
    Original->Tail = pointer;
    Original->Head = head;
    return Original;
}

void SortSet(struct SetNodeRep *Set) {
    struct SetNode *pointer = Set->Head;
    while (pointer != NULL) {
        pointer->Table = SortList(pointer->Table);
        pointer = pointer->Next;
    }
}

int main(int argc, char const *argv[]) {
    struct SetNodeRep *Set = InitSetNodeRep();
    for (int i = 1; i < argc; i++) {
        printf("{%s}\n", argv[i]);
        struct ListNodeRep *list = InitListNodeRep();
        FILE *file = fopen(argv[i], "r+");
        if (file == NULL) { printf("ERROR\n");  return 0; }
        char *input_word = (char *) malloc(MAX * sizeof(char));
        while (fscanf(file, "%s", input_word) != EOF) {
            char *copy = CopyCharPointer(input_word);
            struct ListNode *new_node = InitListNode(copy);
            AppendList(list, new_node);
        }
        fclose(file);
        free(input_word);
        PrintList(list);
        AppendSet(Set, InitSetNode(list));
        // free(list);
    }
    printf("\n----------\n");
    PrintSet(Set);
    printf("\n----------\n");
    SortSet(Set);
    PrintSet(Set);
    // free(Set->Head->Table);
    printf("\n----------\n");
    FreeSet(Set);
    free(Set);
    return 0;
}
