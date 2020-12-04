#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define INF 0x3F3F3F3F

#define MAXIMUM_CHILDREN 3
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))


struct Node {
    int data;
    struct Node *Children[MAXIMUM_CHILDREN];
};


struct BiTNode {
    int data;
    struct BiTNode *Left;
    struct BiTNode *Right;
};


struct BiTree {
    struct BiTNode *Root;
    int Height;
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


void PrintTreeNode(struct BiTNode *TreeNode) {
    printf("%p->{%p|%d|%p} --> ", TreeNode, TreeNode->Left, TreeNode->data, TreeNode->Right);
    printf("\n");
}


struct BiTNode *InitBiTNode(int value) {
    struct BiTNode *New = (struct BiTNode *) malloc(sizeof(struct BiTNode));
    New->data = value;
    New->Left = NULL;
    New->Right = NULL;
    return New;
}


struct BiTree *InitBiTree() {
    struct BiTree *New = (struct BiTree *) malloc(sizeof(struct BiTree));
    New->Root = InitBiTNode(0);
    New->Height = 0;
    return New;
}


void DFS(struct BiTNode *Root) {
    if (Root == NULL) { return; }
    // PrintTreeNode(Root);
    DFS(Root->Left);
    PrintTreeNode(Root);
    DFS(Root->Right);
    //PrintTreeNode(Root);
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


struct BiTNode *InsertBiTNode(struct BiTNode *Root, int value) {
    if (Root == NULL) { return InitBiTNode(value); }
    if (Root->data > value) {
        Root->Left = InsertBiTNode(Root->Left, value);
    } else if (Root->data < value) {
        Root->Right = InsertBiTNode(Root->Right, value);
    }
    return Root;
}


int Height(struct BiTNode *Root) {
    if (Root == NULL) { return 0; }
    int Left = Height(Root->Left);
    int Right = Height(Root->Right);
    printf("[%d]", abs(Left - Right));
    PrintTreeNode(Root);
    return 1 + ((Left > Right) ? Left : Right);
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


struct BiTNode *RotateRight(struct BiTNode *Root) {
    // TODO
    return NULL;
}


struct BiTNode *RotateLeft(struct BiTNode *Root) {
    // TODO
    return NULL;
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


int main(void) {

    // struct BiTNode *Tree = InitBiTNode(0);
    struct BiTree *Tree = InitBiTree();
    // CreateBiTreeManually();
    //PrintTreeNode(Tree);

    // int *stack = (int *) malloc(200 * sizeof(int));
    // int pos = -1;

    int Array[4] = { 3, 1, 2, 4 };

    for (int i = 0; i < 4; i++) {
        Tree->Root = InsertBiTNode(Tree->Root, Array[i]);
    }
    DFS(Tree->Root);
    // NonRecursiveDFS(Tree);

    printf("---------\n");
    // PrintHeightDiff(Tree);
    Height(Tree->Root);
    printf("---------\n");
    printf("%d\n", IsHeightBalanced(Tree->Root));
    printf("---------\n");
    printf("%d\n", BiTreeWidth(Tree->Root));
    FreeBiTree(Tree->Root);
    free(Tree);
    // free(stack);
    return 0;
}
