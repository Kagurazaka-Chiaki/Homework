#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MatrixGraph {
        int EdgeNum;
        int VertexNum;
        int **Matrix;
};

struct Quack {
        int Length;
        struct QuackNode *Head;
        struct QuackNode *Tail;
};

struct QuackNode {
        int Data;
        struct QuackNode *Next;
        struct QuackNode *Prev;
};

struct MatrixGraph *InitMatrixGraph(int VertexAmount, int EdgeAmount) {
    struct MatrixGraph *NewGraph = (struct MatrixGraph *) malloc(sizeof(struct MatrixGraph));
    NewGraph->Matrix = (int **) malloc(VertexAmount * sizeof(int *));
    for (int i = 0; i < VertexAmount; i++) {
        NewGraph->Matrix[i] = (int *) calloc(VertexAmount, sizeof(int));
    }
    NewGraph->VertexNum = VertexAmount;
    NewGraph->EdgeNum = EdgeAmount;
    return NewGraph;
}

bool ValidVertex(struct MatrixGraph *Graph, int Vertex) {
    return ((Graph != NULL) && (Vertex >= 0) && (Vertex < Graph->VertexNum));
}

bool IsAdjacent(struct MatrixGraph *Graph, int Original, int Target) {
    return ((bool) Graph->Matrix[Original][Target]);
}

void InsertUndirectedEdge(struct MatrixGraph *Graph, int Original, int Target, int Weight) {
    if (Graph->Matrix[Original][Target] == 0) {
        Graph->Matrix[Original][Target] = ((Weight == 0) ? 1 : Weight);
        Graph->Matrix[Target][Original] = ((Weight == 0) ? 1 : Weight);
        Graph->EdgeNum++;
    }
}

void RemoveUndirectedEdge(struct MatrixGraph *Graph, int Original, int Target) {
    if (Graph->Matrix[Original][Target] == 0) {
        Graph->Matrix[Original][Target] = 0;
        Graph->Matrix[Target][Original] = 0;
        Graph->EdgeNum--;
    }
}

void InsertDirectedEdge(struct MatrixGraph *Graph, int Original, int Target, int Weight) {
    if (Graph->Matrix[Original][Target] == 0) {
        Graph->Matrix[Original][Target] = ((Weight == 0) ? 1 : Weight);
        Graph->EdgeNum++;
    }
}

void RemoveDirectedEdge(struct MatrixGraph *Graph, int Original, int Target) {
    if (Graph->Matrix[Original][Target] == 0) {
        Graph->Matrix[Original][Target] = 0;
        Graph->EdgeNum--;
    }
}

void PrintMatrixGraph(struct MatrixGraph *Graph) {
    printf("\n%p -> {%d %d %p}\n\n", Graph, Graph->VertexNum, Graph->EdgeNum, Graph->Matrix);
    for (int i = 0; i < Graph->VertexNum; i++) {
        for (int j = 0; j < Graph->VertexNum; j++) {
            printf("[%d]", Graph->Matrix[i][j]);
        }
        printf("\n");
    }
}

void NormalPrint(struct MatrixGraph *Graph) {
}

void FreeMatrixGraph(struct MatrixGraph *Graph) {
    for (int i = 0; i < Graph->VertexNum; i++) { free(Graph->Matrix[i]); }
    free(Graph->Matrix);
    free(Graph);
}

void Sample1(struct MatrixGraph *Graph) {
    InsertDirectedEdge(Graph, 0, 1, 14);
    InsertDirectedEdge(Graph, 0, 2, 9);
    InsertDirectedEdge(Graph, 0, 3, 7);
    InsertDirectedEdge(Graph, 1, 4, 5);
    InsertDirectedEdge(Graph, 2, 1, 4);
    InsertDirectedEdge(Graph, 2, 5, 3);
    InsertDirectedEdge(Graph, 3, 2, 10);
    InsertDirectedEdge(Graph, 3, 5, 15);
    InsertDirectedEdge(Graph, 5, 4, 8);
}

void Sample2(struct MatrixGraph *Graph) {
}

void Sample4(struct MatrixGraph *Graph) {
    InsertDirectedEdge(Graph, 0, 1, 0);
    InsertDirectedEdge(Graph, 1, 2, 0);
    InsertDirectedEdge(Graph, 1, 3, 0);
    InsertDirectedEdge(Graph, 2, 0, 0);
    InsertDirectedEdge(Graph, 3, 0, 0);
    InsertDirectedEdge(Graph, 3, 2, 0);
    InsertDirectedEdge(Graph, 4, 5, 0);
    InsertDirectedEdge(Graph, 4, 6, 0);
    InsertDirectedEdge(Graph, 5, 1, 0);
    InsertDirectedEdge(Graph, 6, 3, 0);
    InsertDirectedEdge(Graph, 6, 5, 0);
}

void SampleFinal(struct MatrixGraph *Graph) {
    InsertUndirectedEdge(Graph, 0, 1, 7);
    InsertUndirectedEdge(Graph, 0, 2, 6);
    InsertUndirectedEdge(Graph, 1, 2, 7);
    InsertUndirectedEdge(Graph, 1, 3, 1);
    InsertUndirectedEdge(Graph, 2, 3, 4);
    InsertUndirectedEdge(Graph, 2, 4, 4);
    InsertUndirectedEdge(Graph, 3, 4, 6);
    InsertUndirectedEdge(Graph, 3, 5, 2);
    InsertUndirectedEdge(Graph, 4, 5, 2);
    InsertUndirectedEdge(Graph, 4, 6, 6);
    InsertUndirectedEdge(Graph, 5, 6, 1);
    InsertUndirectedEdge(Graph, 5, 7, 7);
    InsertUndirectedEdge(Graph, 6, 7, 1);
    InsertUndirectedEdge(Graph, 6, 8, 9);
    InsertUndirectedEdge(Graph, 7, 8, 4);
    InsertUndirectedEdge(Graph, 7, 9, 7);
    InsertUndirectedEdge(Graph, 8, 9, 4);
}

void BuildGraphManually(struct MatrixGraph *Graph) {
    // Sample1(Graph);
    // Sample4(Graph);
    SampleFinal(Graph);
}

struct Quack *InitQuack(void) {
    struct Quack *NewQuack = (struct Quack *) malloc(sizeof(struct Quack));
    NewQuack->Head = NewQuack->Tail = NULL;
    NewQuack->Length = 0;
    return NewQuack;
}

struct QuackNode *InitQuackNode(int Value) {
    struct QuackNode *NewQuackNode = (struct QuackNode *) malloc(sizeof(struct QuackNode));
    NewQuackNode->Next = NewQuackNode->Prev = NULL;
    NewQuackNode->Data = Value;
    return NewQuackNode;
}

int QuackPop(struct Quack *Stack) {
    struct QuackNode *flag = Stack->Head;
    int pop_value = Stack->Head->Data;
    Stack->Head = Stack->Head->Next;
    if (Stack->Head == NULL) { Stack->Tail = NULL; }
    free(flag);
    Stack->Length--;
    return pop_value;
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

int QuackDeQueue(struct Quack *Queue) {
    struct QuackNode *flag = Queue->Head;
    int leave_value = Queue->Head->Data;
    Queue->Head = Queue->Head->Next;
    if (Queue->Head == NULL) { Queue->Tail = NULL; }
    free(flag);
    Queue->Length--;
    return leave_value;
}

void ApplyQuackNode(int AppliedValue) {
    printf("%d ", AppliedValue);
}

void PrintQuack(struct Quack *Q) {
    printf("%p -> {Head %p %d Tail %p} :\n", Q, Q->Head, Q->Length, Q->Tail);
    struct QuackNode *pointer = Q->Head;
    while (pointer != NULL) {
        printf("%p -> {%p %d %p}\n", pointer, pointer->Prev, pointer->Data, pointer->Next);
        pointer = pointer->Next;
    }
}

void FreeQuack(struct Quack *Q) {
    struct QuackNode *pointer = Q->Head;
    while (pointer != NULL) {
        struct QuackNode *flag = pointer;
        pointer = pointer->Next;
        free(flag);
    }
}

void MatrixGraphDFS(struct MatrixGraph *Graph) {
    printf("深度优先遍历 (DFS) :\n");
    int length = Graph->VertexNum;
    bool *visited = (bool *) malloc(length * sizeof(bool));
    for (int i = 0; i < length; i++) {
        visited[i] = false;
        printf("[%d]", visited[i]);
    }
    printf("\n\n");
    struct Quack *stack = InitQuack();
    QuackPush(stack, InitQuackNode(Graph->Matrix[0][0]));
    // PrintQuack(stack);
    while (stack->Length != 0) {
        int temp = QuackPop(stack);
        if (visited[temp] == true) { continue; }
        ApplyQuackNode(temp);
        visited[temp] = true;
        for (int i = 0; i < length; i++) { printf("[%d]", visited[i]); }
        printf("\n");
        for (int y = Graph->VertexNum - 1; y > -1; y--) {
            if (IsAdjacent(Graph, temp, y) == false) { continue; }
            if (!visited[y]) { QuackPush(stack, InitQuackNode(y)); }
        }
        // PrintQuack(stack);
    }
    printf("\n----------\n");
    free(stack);
    free(visited);
}

void MatrixGraphBFS(struct MatrixGraph *Graph) {
    printf("广度优先遍历 (BFS) :\n");
    int length = Graph->VertexNum;
    bool *visited = (bool *) malloc(length * sizeof(bool));
    for (int i = 0; i < length; i++) {
        visited[i] = false;
        printf("[%d]", visited[i]);
    }
    printf("\n\n");
    struct Quack *queue = InitQuack();
    QuackEnQueue(queue, InitQuackNode(Graph->Matrix[0][0]));
    // PrintQuack(queue);
    while (queue->Length != 0) {
        int temp = QuackDeQueue(queue);
        if (visited[temp] == true) { continue; }
        ApplyQuackNode(temp);
        visited[temp] = true;
        for (int i = 0; i < length; i++) { printf("[%d]", visited[i]); }
        printf("\n");
        for (int y = 0; y < Graph->VertexNum; y++) {
            if (IsAdjacent(Graph, temp, y) == false) { continue; }
            if (!visited[y]) { QuackEnQueue(queue, InitQuackNode(y)); }
        }
        // PrintQuack(queue);
    }
    printf("\n----------\n");
    free(queue);
    free(visited);
}

char *ShortestPath(struct MatrixGraph *Graph, int StartVertex, int EndVertex) {

    printf("\n%d -> %d 最短路径 :\n", StartVertex, EndVertex);
    int vers = Graph->VertexNum;

    int *distance = (int *) malloc(vers * sizeof(int));
    memset(distance, 0x3f, vers * sizeof(int));
    int *previous = (int *) malloc(vers * sizeof(int));
    memset(previous, -1, vers * sizeof(int));
    int *visited = (int *) malloc(vers * sizeof(int));
    memset(visited, 0, vers * sizeof(int));
    int *known = (int *) malloc(vers * sizeof(int));
    memset(known, 0, vers * sizeof(int));

    // printf("\n----------\n");
    // printf(" I   K   P   D --- Initial\n");
    // for (int i = 0; i < vers; i++) { printf("[%d] [%d] [%d] [%d]\n", i, known[i], previous[i], distance[i]); }
    // printf("\n----------\n");

    distance[StartVertex] = 0;
    int index = 0;
    for (int i = 1; i < vers; i++) {

        int min = 0x3f3f3f3f; // 最大值

        // printf("\n----------\n");
        // printf(" I   K   P   D --- %d\n", i);
        // for (int j = 0; j < vers; j++) { printf("[%d] [%d] [%d] [%d]\n",j , known[j], previous[j], distance[j]); }
        // printf("\n----------\n");

        for (int k = 0; k < vers; k++) {
            if (known[k] == 0 && distance[k] < min) {
                min = distance[k];
                index = k; // 最小结点序号
            }
        }

        printf("{min: %d index: %d}", min, index);
        known[index] = 1;

        for (int l = 0; l < vers; l++) { // 相邻结点
            if (IsAdjacent(Graph, index, l) == true) {
                int weight = Graph->Matrix[index][l];
                if (known[l] == 0 && distance[index] + weight < distance[l]) {
                    distance[l] = distance[index] + weight;
                    previous[l] = index;
                }
            }
        }
    }

    printf("\n----------\n");
    printf(" I   K   P   D --- Final\n");
    for (int i = 0; i < vers; i++) { printf("[%d] [%d] [%d] [%d]\n", i, known[i], previous[i], distance[i]); }
    printf("\n----------\n");

    char *Path = (char *) malloc(sizeof(char));
    int prev_end = EndVertex;
    int pos = -1;

    for (int i = 0; i < vers; i++) {
        Path[++pos] = ((char) prev_end) + '0';
        Path = (char *) realloc(Path, (pos + 2) * sizeof(char));
        prev_end = previous[prev_end];
        if (prev_end == -1) {
            Path[++pos] = '\0';
            break;
        }
        //     Path[++pos] = ((char) StartVertex) + '0';
        //     Path[++pos] = '\0'; break;
        // }
    }

    free(known);
    free(visited);
    free(distance);
    free(previous);
    return Path;
}

struct MatrixGraph *CopyGraph(struct MatrixGraph *Graph) {
    struct MatrixGraph *copy = InitMatrixGraph(Graph->VertexNum, Graph->EdgeNum);
    for (int i = 0; i < Graph->VertexNum; i++) {
        for (int j = 0; j < Graph->VertexNum; j++) {
            copy->Matrix[i][j] = Graph->Matrix[i][j];
        }
    }
    PrintMatrixGraph(copy);
    return copy;
}

struct MatrixGraph *TransitiveClosure(struct MatrixGraph *Graph) {
    struct MatrixGraph *reachable = CopyGraph(Graph);
    for (int i = 0; i < Graph->VertexNum; i++) {
        reachable->Matrix[i][i] = 0;
    }

    for (int i = 0; i < Graph->VertexNum; i++) {
        for (int j = 0; j < Graph->VertexNum; j++) {
            for (int k = 0; k < Graph->VertexNum; k++) {
                if ((((bool) reachable->Matrix[j][i]) == true) ^
                    (((bool) reachable->Matrix[i][k]) == true)) {
                    reachable->Matrix[j][k] = 1;
                }
            }
        }
    }
    PrintMatrixGraph(reachable);
    return reachable;
}

int main(int argc, char const *argv[]) {
    struct MatrixGraph *Graph = InitMatrixGraph(11, 0);
    PrintMatrixGraph(Graph);
    BuildGraphManually(Graph);
    PrintMatrixGraph(Graph);
    MatrixGraphDFS(Graph);
    MatrixGraphBFS(Graph);
    // printf("%s\n", ShortestPath(Graph, 0, 10));
    // printf("%s\n", ShortestPath(Graph, 0, 1));
    // printf("%s\n", ShortestPath(Graph, 0, 2));
    // printf("%s\n", ShortestPath(Graph, 0, 3));
    // printf("%s\n", ShortestPath(Graph, 0, 4));
    // printf("%s\n", ShortestPath(Graph, 0, 5));
    char *Path = ShortestPath(Graph, 0, 9);
    printf("%zu, %s\n", strlen(Path), Path);
    for (int i = strlen(Path) - 1; i > -1; i--) {
        if (i == 0) {
            printf("%c\n", Path[i]);
        } else {
            printf("%c -> ", Path[i]);
        }
    }
    printf("%d", (Path[0] == '\0'));
    free(Path);

    // TransitiveClosure(Graph);
    FreeMatrixGraph(Graph);
    return 0;
}
