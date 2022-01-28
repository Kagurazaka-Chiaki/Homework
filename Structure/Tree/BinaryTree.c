#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define INF 0x3F3F3F3F

#define GAP 3
#define MAX_HEIGHT 1000
#define MAXIMUM_CHILDREN 3

// 宏定义函数
// #define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
// #define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

struct Node {
    int data;
    struct Node *Children[MAXIMUM_CHILDREN];
};


struct BiTNode {
    int Data;
    int Height;
    struct BiTNode *Left;
    struct BiTNode *Right;
};


struct BiTree {
    struct BiTNode *Root;
    // int Height;
};


struct LinkedStack {
    int Total;
    struct LinkedStackNode *Head;
};


struct LinkedStackNode {
    int PopTimes;
    struct BiTNode *TreeNode;
    struct LinkedStackNode *Next;
};


struct BiTNode *NormalInsertBiTNode(struct BiTNode *Root, int Value);
struct BiTNode *AVLInsertBiTNode(struct BiTNode *Root, int Value);
struct BiTNode *InsertBiTNode(struct BiTNode *Root, int Value);

void PrintTreeNode(struct BiTNode *TreeNode) {
    printf("%p->{%p|%d|%p} --> ", TreeNode, TreeNode->Left, TreeNode->Data, TreeNode->Right);
    printf("\n");
}


struct BiTNode *InitBiTNode(int Value) {
    struct BiTNode *New = (struct BiTNode *) malloc(sizeof(struct BiTNode));
    New->Data = Value;
    New->Left = NULL;
    New->Right = NULL;
    New->Height = 0;
    return New;
}


struct BiTree *InitBiTree() {
    struct BiTree *New = (struct BiTree *) malloc(sizeof(struct BiTree));
    New->Root = NULL;
    // InitBiTNode(0);
    // New->Height = 0;
    return New;
}


/**
 * Dot 语言打印树结构
**/
void DotPrint(struct BiTNode *TreeNode) {
    if (TreeNode != NULL) {
        printf("%d -> {", TreeNode->Data);
        if (TreeNode->Left != NULL) {
            printf(" %d", TreeNode->Left->Data);
        }
        printf(" ");
        if (TreeNode->Right != NULL) {
            printf("%d ", TreeNode->Right->Data);
        }
    }
    printf("}\n");
}


void DFS(struct BiTNode *Root) {
    if (Root == NULL) { return; }
    // PrintTreeNode(Root);
    DFS(Root->Left);
    // PrintTreeNode(Root);
    DotPrint(Root);
    DFS(Root->Right);
    // PrintTreeNode(Root);
}


int Height(struct BiTNode *Root) {
    if (Root == NULL) { return 0; }
    // int Left = Height(Root->Left);
    // int Right = Height(Root->Right);
    // printf("[%d]", abs(Left - Right));
    // PrintTreeNode(Root);
    // return 1 + ((Left > Right) ? Left : Right);
    return max(Height(Root->Left), Height(Root->Right)) + 1;
}


int GetHeight(struct BiTNode *TreeNode) {
    return (TreeNode == NULL) ? -1 : TreeNode->Height;
}


int PrintHeightDiff(struct BiTNode *Root) {
    if (Root == NULL) { return 0; }
    if (Root->Left == NULL && Root->Right == NULL) {
        PrintTreeNode(Root);
        return 1;
    }
    int Left = PrintHeightDiff(Root->Left);
    int Right = PrintHeightDiff(Root->Right);
    printf("[%d]", (Left - Right));
    return 1 + ((Left > Right) ? Left : Right);
}


/**
 * abs (Left - Right) <= 1
**/
int IsHeightBalanced(struct BiTNode *Root) {
    if (Root == NULL) { return 0; }
    int Left = IsHeightBalanced(Root->Left);
    int Right = IsHeightBalanced(Root->Right);
    if (Left == 0 || Right == 0) { return 0; }
    if (Left - Right > 1 || Right - Left > 1) { return 0; }
    return 1 + ((Left > Right) ? Left : Right);
}


int BiTreeWidth(struct BiTNode *Root) {
    if (Root == NULL) { return 0; }
    return 2 + BiTreeWidth(Root->Left) + BiTreeWidth(Root->Right);
}


struct BiTNode *CreateBiTreeManually(void) {
    struct BiTNode *NewTree = InitBiTNode(0);
    struct BiTNode *pointer = NewTree;
    pointer->Left = InitBiTNode(1);
    pointer->Right = InitBiTNode(2);
    pointer = pointer->Left;
    pointer->Left = InitBiTNode(3);
    pointer->Right = InitBiTNode(4);
    return NewTree;
}


struct BiTNode *RotateLeft(struct BiTNode *Root) {
    if (Root == NULL) { return NULL; }
    if (Root->Right == NULL) { return Root; }

    struct BiTNode *Pivot = Root->Right;
    Root->Right = Pivot->Left;
    Pivot->Left = Root;
    Root->Height = max(Height(Root->Left), Height(Root->Right)) + 1;
    Pivot->Height = max(Height(Pivot->Right), Height(Root)) + 1;
    Root = Pivot;
    return Root;
}


struct BiTNode *RotateRight(struct BiTNode *Root) {
    if (Root == NULL) { return NULL; }
    if (Root->Left == NULL) { return Root; }

    struct BiTNode *Piovt = Root->Left;
    Root->Left = Piovt->Right;
    Piovt->Right = Root;
    Root->Height = max(Height(Root->Left), Height(Root->Right)) + 1;
    Piovt->Height = max(Height(Piovt->Left), Height(Root)) + 1;
    Root = Piovt;
    return Root;
}


struct BiTNode *NormalInsertBiTNode(struct BiTNode *Root, int Value) {
    if (Root == NULL) { return InitBiTNode(Value); }
    if (Root->Data > Value) {
        Root->Left = InsertBiTNode(Root->Left, Value);
    } else if (Root->Data < Value) {
        Root->Right = InsertBiTNode(Root->Right, Value);
    }
    return Root;
}


struct BiTNode *AVLInsertBiTNode(struct BiTNode *Root, int Value) {
    if (Root == NULL) { return InitBiTNode(Value); }
    if (Root->Data < Value) {
        Root->Right = InsertBiTNode(Root->Right, Value);
    } else if (Root->Data > Value) {
        Root->Left = InsertBiTNode(Root->Left, Value);
    } else {
        return Root;
    }

    Root->Height = 1 + max(Height(Root->Left), Height(Root->Right));

    if (Height(Root->Left) - Height(Root->Right) > 1) {
        printf("1\n");
        if (Value > Root->Left->Data) {
            Root->Left = RotateLeft(Root->Left);
            Root = RotateRight(Root);
        } else {
            Root = RotateRight(Root);
        }
    } else if (Height(Root->Right) - Height(Root->Left) > 1) {
        printf("2");
        if (Value < Root->Right->Data) {
            Root->Right = RotateRight(Root->Right);
            Root = RotateLeft(Root);
        } else {
            Root = RotateLeft(Root);
        }
    }

    return Root;
}


struct BiTNode *InsertBiTNode(struct BiTNode *Root, int Value) {
    // 普通插入
    // return NormalInsertBiTNode(Root, Value);

    // AVL 树插入
    return AVLInsertBiTNode(Root, Value);
}


struct LinkedStack *InitLinkStack(void) {
    struct LinkedStack *New = (struct LinkedStack *) malloc(sizeof(struct LinkedStack));
    New->Head = NULL;
    New->Total = 0;
    return New;
}


struct LinkedStackNode *InitLinkStackNode(struct BiTNode *TreeNode) {
    struct LinkedStackNode *New = (struct LinkedStackNode *) malloc(sizeof(struct LinkedStackNode));
    New->TreeNode = TreeNode;
    New->PopTimes = 0;
    New->Next = NULL;
    return New;
}


struct LinkedStackNode *StackPop(struct LinkedStack *Stack) {
    if (Stack->Head == NULL) { return NULL; }
    struct LinkedStackNode *PopNode = Stack->Head;
    Stack->Head = Stack->Head->Next;
    PopNode->Next = NULL;
    Stack->Total--;
    return PopNode;
}


int StackPush(struct LinkedStack *Stack, struct LinkedStackNode *NewStackNode) {
    if (NewStackNode == NULL) { return 0; }
    if (Stack->Head == NULL) {
        Stack->Head = NewStackNode;
    } else {
        NewStackNode->Next = Stack->Head;
        Stack->Head = NewStackNode;
    }
    Stack->Total++;
    return 0;
}


void ApplyTreeNode(struct BiTNode *TreeNode) {
    PrintTreeNode(TreeNode);
}


void NonRecursiveDFS(struct BiTree *T) {
    struct LinkedStack *stack = InitLinkStack();
    struct LinkedStackNode *current = NULL;
    StackPush(stack, InitLinkStackNode(T->Root));
    while (stack->Total != 0) {
        current = StackPop(stack);
        if ((++(current->PopTimes)) == 2) {
            ApplyTreeNode(current->TreeNode);
            if (current->TreeNode->Right != NULL) {
                StackPush(stack, InitLinkStackNode(current->TreeNode->Right));
            }
            free(current);
        } else {
            StackPush(stack, current);
            if (current->TreeNode->Left != NULL) {
                StackPush(stack, InitLinkStackNode(current->TreeNode->Left));
            }
        }
    }
    free(stack);
}


void FreeBiTree(struct BiTNode *Root) {
    if (Root == NULL) { return; }
    FreeBiTree(Root->Left);
    FreeBiTree(Root->Right);
    free(Root);
}

bool Range(int X, int A, int B) {
    if (A <= X && X <= B) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int TreeValueNext(struct BiTNode *Root, int Value, int *Stack) {
    if (Root == NULL) { return -1; }

    TreeValueNext(Root->Left, Value, Stack);

    if (Stack[0] == 0 && Stack[1] == 0) {
        Stack[0] = Root->Data;
        if (Value <= Stack[0]) {
            Stack[2] = Stack[0];
        }
    }

    if (Stack[0] != 0) {
        Stack[1] = Stack[0];
        Stack[0] = Root->Data;
        if (Value >= Stack[1] && Value <= Stack[0]) {
            Stack[2] = Stack[0];
        }
    }

    TreeValueNext(Root->Right, Value, Stack);

    return Root->Data;
}

int main(void) {

    // struct BiTNode *Root = InitBiTNode(0);
    // Root = CreateBiTreeManually();
    // DFS(Root);
    // // Root = RotateLeft(Root);
    // // Root = RotateRight(Root);
    // printf("\n");
    // DFS(Root);

    struct BiTree *Tree = InitBiTree();
    int Array[8] = { 25, 20, 30, 18, 22, 32, 35, 24 };
    for (int i = 0; i < 8; i++) {
        Tree->Root = InsertBiTNode(Tree->Root, Array[i]);
        DFS(Tree->Root);
        printf("\n");
    }

    int *S = (int *) malloc(3 * sizeof(int));
    TreeValueNext(Tree->Root, 19, S);
    printf("\n[%d]\n", S[2]);

    // Tree->Root = RotateLeft(Tree->Root);
    // DFS(Tree->Root);
    FreeBiTree(Tree->Root);
    free(Tree);

    // NonRecursiveDFS(Tree);
    return 0;
}
