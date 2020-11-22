#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 3

struct Node {
    int data;
    struct Node *children[MAX];
};

struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
};

struct BiTNode *InitBiTNode(int value);
void PrintTreeNode(struct BiTNode *BiTree);
int DFS(struct BiTNode *BiTree);
struct BiTNode *CreateBiTreeManually(void);
struct BiTNode *InsertBiTNode(struct BiTNode *BiTree, int value);

void PrintTreeNode(struct BiTNode *BiTree) {
    printf("%p->{%p|%d|%p}\n", BiTree, BiTree->left, BiTree->data, BiTree->right);
}

struct BiTNode *InitBiTNode(int value) {
    struct BiTNode *BiTree = (struct BiTNode *) malloc(sizeof(struct BiTNode));
    BiTree->data = value;
    BiTree->left = NULL;
    BiTree->right = NULL;
    return BiTree;
}

int DFS(struct BiTNode *BiTree) {
    if (BiTree == NULL) { return 0; }
    PrintTreeNode(BiTree);
    DFS(BiTree->left);
    //PrintTreeNode(BiTree);
    DFS(BiTree->right);
    //PrintTreeNode(BiTree);
}

struct BiTNode *CreateBiTreeManually(void) {
    struct BiTNode *NewTree = InitBiTNode(0);
    struct BiTNode *pointer = NewTree;
    pointer->left = InitBiTNode(1);
    pointer->right = InitBiTNode(2);
    pointer = pointer->left;
    pointer->left = InitBiTNode(3);
    pointer->right = InitBiTNode(4);
    return NewTree;
}

struct BiTNode *InsertBiTNode(struct BiTNode *BiTree, int value) {
    if (BiTree == NULL) { return InitBiTNode(value); }
    if (BiTree->data > value) {
        BiTree->left = InsertBiTNode(BiTree->left, value);
    } else if (BiTree->data < value) {
        BiTree->right = InsertBiTNode(BiTree->right, value);
    }
    return BiTree;
}

int Height(struct BiTNode *BiTree) {
    if (BiTree == NULL) { return 0; }
    int left = Height(BiTree->left);
    int right = Height(BiTree->right);
    printf("[%d]", abs(left - right));
    PrintTreeNode(BiTree);
    return 1 + ((left > right) ? left : right);
}

int PrintHeightDiff(struct BiTNode *BiTree) {
    if (BiTree == NULL) { return 0; }
    if (BiTree->left == NULL && BiTree->right == NULL) {
        PrintTreeNode(BiTree);
        return 1;
    }
    int left = PrintHeightDiff(BiTree->left);
    int right = PrintHeightDiff(BiTree->right);
    printf("[%d]", (left - right));
    return 1 + ((left > right) ? left : right);
}

// abs (left - right) <= 1
int IsHeightBalanced(struct BiTNode *BiTree) {
    if (BiTree == NULL) { return 0; }
    int left = IsHeightBalanced(BiTree->left);
    int right = IsHeightBalanced(BiTree->right);
    if (left == 0 || right == 0) { return 0; }
    if (left - right > 1 || right - left > 1) { return 0; }
    return 1 + ((left > right) ? left : right);
}

int BiTreeWidth(struct BiTNode *BiTree) {
    if (BiTree == NULL) { return 0; }
    return 2 + BiTreeWidth(BiTree->left) + BiTreeWidth(BiTree->right);
}

struct BiTNode *RotateRight(struct BiTNode *BiTree) {

}

struct BiTNode *RotateLeft(struct BiTNode *BiTree) {

}

int main(void) {

    struct BiTNode *Tree = InitBiTNode(0);
    // CreateBiTreeManually();
    //PrintTreeNode(Tree);

    int *stack = (int *) malloc(200 * sizeof(int));
    int pos = -1;

    int Array[MAX] = { 3, 1, 2 };

    for (int i = 0; i < MAX; i++) {
        InsertBiTNode(Tree, Array[i]);
    }
    DFS(Tree);
    printf("---------\n");
    // PrintHeightDiff(Tree);
    Height(Tree);
    printf("---------\n");
    printf("%d\n", IsHeightBalanced(Tree));
    printf("---------\n");
    printf("%d\n", BiTreeWidth(Tree));
    return 0;
}
