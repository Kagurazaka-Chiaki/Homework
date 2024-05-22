#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define Hash_Table_Length 7

struct ListNode {
        int Data;
        char *String;
        struct ListNode *Next;
};

struct ListNodeRep {
        struct ListNode *Head;
        struct ListNode *Tail;
};

struct HashTable {
        int TableLength;
        int TotalElements;
        struct ListNodeRep **Array;
};

struct ListNode *InitListNode(int Value, char *Word) {
    struct ListNode *New = (struct ListNode *) malloc(sizeof(struct ListNode));
    New->String = Word;
    New->Data = Value;
    New->Next = NULL;
    return New;
}

struct ListNodeRep *InitListNodeRep(void) {
    struct ListNodeRep *New = (struct ListNodeRep *) malloc(sizeof(struct ListNodeRep));
    New->Head = New->Tail = NULL;
    return New;
}

struct HashTable *InitHashTable(int MaxLength) {
    struct HashTable *New = (struct HashTable *) malloc(sizeof(struct HashTable));
    New->Array = (struct ListNodeRep **) malloc(MaxLength * sizeof(struct ListNodeRep *));
    for (int i = 0; i < MaxLength; i++) { New->Array[i] = InitListNodeRep(); }
    New->TableLength = MaxLength;
    New->TotalElements = 0;
    return New;
}

void PrintList(struct ListNodeRep *List) {
    printf("{ Head [%p] Tail [%p] } ", List->Head, List->Tail);
    struct ListNode *pointer = List->Head;
    while (pointer != NULL) {
        printf("{ %p -> [%d %s %p] } ", pointer, pointer->Data, pointer->String, pointer->Next);
        pointer = pointer->Next;
    }
}

void PrintHashTable(struct HashTable *Hash) {
    printf("%p -> {%p %d %d} \n", Hash, Hash->Array, Hash->TableLength, Hash->TotalElements);
    int length = Hash->TableLength;
    for (int i = 0; i < length; i++) {
        printf("[%d] : %p -> ", i, Hash->Array[i]);
        if (Hash->Array[i] != NULL) {
            PrintList(Hash->Array[i]);
        }
        printf("\n");
    }
}

void FreeList(struct ListNodeRep *List) {
    struct ListNode *pointer = List->Head;
    while (pointer != NULL) {
        struct ListNode *flag = pointer;
        pointer = pointer->Next;
        // free(flag->String);
        free(flag);
    }
    free(List);
}

void FreeHashTable(struct HashTable *Hash) {
    for (int i = 0; i < Hash->TableLength; i++) {
        FreeList(Hash->Array[i]);
    }
    free(Hash->Array);
    free(Hash);
}

int Hashing(char *Key) {
    int sum = 0;
    int length = strlen(Key);
    for (int i = 0; i < length; i++) {
        // printf("[%c %d] ", Key[i], Key[i]);
        sum = sum + Key[i];
    }
    sum = sum % Hash_Table_Length;
    return abs(sum);
}

void AppendList(struct ListNodeRep *List, struct ListNode *NewNode) {
    if (List->Head == NULL && List->Tail == NULL) {
        List->Head = List->Tail = NewNode;
    } else {
        // NewNode->Index = List->Tail->Index + 1;
        List->Tail->Next = NewNode;
        List->Tail = List->Tail->Next;
    }
    // List->Length++;
}

int FindListNode(struct HashTable *Hash, char *Keywords) {
    int index = Hashing(Keywords);
    return index;
}

int DeleteListNode(struct ListNodeRep *List, char *Keywords) {
    struct ListNode *flag = NULL;

    if (strcmp(Keywords, List->Head->String) == 0) {
        flag = List->Head;
        List->Head = List->Head->Next;
        if (flag == List->Tail) { List->Tail = NULL; }
        free(flag);
        return 0;
    }

    struct ListNode *pointer = List->Head;
    while (pointer->Next != NULL) {
        if (strcmp(Keywords, pointer->Next->String) == 0) {
            struct ListNode *flag = pointer->Next;
            pointer->Next = pointer->Next->Next;
            // free(flag->String);
            free(flag);
            break;
        } else {
            pointer = pointer->Next;
        }
    }

    return 0;
}

int DeleteHashNode(struct HashTable *Hash, char *Keywords) {
    int index = FindListNode(Hash, Keywords);
    DeleteListNode(Hash->Array[index], Keywords);
    Hash->TotalElements--;
    return 0;
}

void InsertListNode(struct HashTable *Hash, char *Keywords) {
    int index = Hashing(Keywords);
    printf("\n----------\n");
    printf("{%d %p}\n", index, Hash->Array[index]);
    AppendList(Hash->Array[index], InitListNode(0, Keywords));
    Hash->TotalElements++;
}

void BuildHashTableManually(struct HashTable *Hash) {
    // NOLINTNEXTLINE ISO C++11 does not allow conversion from string literal to 'char *'clang(-Wwritable-strings)
    InsertListNode(Hash, "Hello, Hashng");
    // NOLINTNEXTLINE ISO C++11 does not allow conversion from string literal to 'char *'clang(-Wwritable-strings)
    InsertListNode(Hash, "Hello, Hashing");
    // NOLINTNEXTLINE ISO C++11 does not allow conversion from string literal to 'char *'clang(-Wwritable-strings)
    InsertListNode(Hash, "Hello, Hashig");
}

void Resizeing(struct HashTable *Hash) {
    // TODO
}

int main(int argc, char const *argv[]) {
    // setlocale(LC_ALL, "zh_CN");
    // for (int i = 1; i < argc; i++) {
    //     printf("{%s}\n", argv[i]);
    // }
    printf("\n----------\n");
    struct HashTable *Hash = InitHashTable(Hash_Table_Length);
    PrintHashTable(Hash);
    printf("\n----------\n");
    printf("{%p %llu}", Hash->Array[4], (unsigned long long) Hash->Array[4]);
    printf("\n----------\n");
    // wchar_t a = L'中';
    // putwchar(a);
    BuildHashTableManually(Hash);
    printf("\n----------\n");
    PrintHashTable(Hash);
    printf("\n----------\n");
    printf("{%p %s}", Hash->Array[1], Hash->Array[1]->Head->String);
    printf("\n----------\n");
    // NOLINTNEXTLINE ISO C++11 does not allow conversion from string literal to 'char *'clang(-Wwritable-strings)
    printf("Find {%d}\n", FindListNode(Hash, "Hello, Hashing"));
    printf("\n----------\n");
    printf("Delete Hello, Hashing");
    // NOLINTNEXTLINE ISO C++11 does not allow conversion from string literal to 'char *'clang(-Wwritable-strings)
    DeleteHashNode(Hash, "Hello, Hashing");
    printf("\n----------\n");
    PrintHashTable(Hash);
    FreeHashTable(Hash);
    return 0;
}