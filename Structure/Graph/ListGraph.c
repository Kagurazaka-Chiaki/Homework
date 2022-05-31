#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <cstdlib>

struct ListGraph {
    int EdgeNum;
    int VertexNum;
    struct Vertex *HeadVertex;
    struct Vertex *TailVertex;
};

struct Vertex {
    int VertexIndex;
    char *VertexInfo;
    struct Edge *HeadEdge;
    struct Edge *TailEdge;
    struct Vertex *NextVertex;
    struct Vertex *PrevVertex;
};

struct Edge {
    int Weight;
    struct Vertex *VertexNode;
    struct Edge *NextEdge;
};

struct Quack {
    int Length;
    struct QuackNode *Head;
    struct QuackNode *Tail;
};

struct QuackNode {
    struct Vertex *VertexNode;
    struct QuackNode *Next;
    struct QuackNode *Prev;
};

struct ListGraph *InitListGraph(int VertexAmount, int EdgeAmount) {
    struct ListGraph *NewGraph = (struct ListGraph *) malloc(sizeof(struct ListGraph));
    NewGraph->HeadVertex = NewGraph->TailVertex = NULL;
    NewGraph->VertexNum = VertexAmount;
    NewGraph->EdgeNum = EdgeAmount;
    return NewGraph;
}

struct Vertex *InitVertex(char *VertexString) {
    struct Vertex *NewVertex = (struct Vertex *) malloc(sizeof(struct Vertex));
    NewVertex->NextVertex = NewVertex->PrevVertex = NULL;
    NewVertex->HeadEdge = NewVertex->TailEdge = NULL;
    NewVertex->VertexInfo = VertexString;
    NewVertex->VertexIndex = 0;
    return NewVertex;
}

struct Edge *InitEdge(int EdgeWeight, struct Vertex *TargetVertex) {
    struct Edge *NewEdge = (struct Edge *) malloc(sizeof(struct Edge));
    NewEdge->VertexNode = TargetVertex;
    NewEdge->Weight = EdgeWeight;
    NewEdge->NextEdge = NULL;
    return NewEdge;
}

void AppendVertex(struct ListGraph *Graph, struct Vertex *VertexNode) {
    if (Graph->HeadVertex == NULL || Graph->TailVertex == NULL) {
        Graph->HeadVertex = Graph->TailVertex = VertexNode;
    } else {
        VertexNode->PrevVertex = Graph->TailVertex;
        Graph->TailVertex->NextVertex = VertexNode;
        Graph->TailVertex = VertexNode;
    }
    VertexNode->VertexIndex = (Graph->VertexNum++);
}

struct Vertex *SearchVertex(struct ListGraph *Graph, char *TargetString) {
    struct Vertex *pointer = Graph->HeadVertex;
    while (pointer != NULL) {
        if (strcmp(pointer->VertexInfo, TargetString) == 0) { return pointer; }
        pointer = pointer->NextVertex;
    }
    return NULL;
}

void UndirectedEdge(struct Vertex *OriginalVertex, struct Vertex *TargetVertex, int Weight) {
    struct Edge *NewEdge = InitEdge(Weight, TargetVertex);
    struct Edge *CopyEdge = InitEdge(Weight, OriginalVertex);
    if (OriginalVertex->HeadEdge == NULL && OriginalVertex->TailEdge == NULL) {
        OriginalVertex->HeadEdge = OriginalVertex->TailEdge = NewEdge;
    } else {
        OriginalVertex->TailEdge->NextEdge = NewEdge;
        OriginalVertex->TailEdge = NewEdge;
    }

    if (TargetVertex->HeadEdge == NULL && TargetVertex->TailEdge == NULL) {
        TargetVertex->HeadEdge = TargetVertex->TailEdge = CopyEdge;
    } else {
        TargetVertex->TailEdge->NextEdge = CopyEdge;
        TargetVertex->TailEdge = CopyEdge;
    }
}

void DirectedEdge(struct Vertex *OriginalVertex, struct Vertex *TargetVertex, int Weight) {
    struct Edge *NewEdge = InitEdge(Weight, TargetVertex);
    if (OriginalVertex->HeadEdge == NULL && OriginalVertex->TailEdge == NULL) {
        OriginalVertex->HeadEdge = OriginalVertex->TailEdge = NewEdge;
    } else {
        OriginalVertex->TailEdge->NextEdge = NewEdge;
        OriginalVertex->TailEdge = NewEdge;
    }
}

void PrintListGraph(struct ListGraph *Graph) {
    printf("\nPrint Graph :\n");
    printf("%p -> {%d %d %p %p}\n\n", Graph, Graph->VertexNum, Graph->EdgeNum, Graph->HeadVertex, Graph->TailVertex);
    struct Vertex *pointer = Graph->HeadVertex;
    while (pointer != NULL) {
        printf("Print Vertex :\n");
        printf("%p -> {%d %s %p %p %p} \n", pointer, pointer->VertexIndex, pointer->VertexInfo, pointer->HeadEdge, pointer->TailEdge, pointer->NextVertex);
        printf("Print Edge :\n");
        struct Edge *edge_pointer = pointer->HeadEdge;
        while (edge_pointer != NULL) {
            printf("%p -> {%d %d %p} \n", edge_pointer, edge_pointer->Weight, edge_pointer->VertexNode->VertexIndex, edge_pointer->NextEdge);
            edge_pointer = edge_pointer->NextEdge;
        }
        pointer = pointer->NextVertex;
        printf("----------\n");
    }
}

void NormalPrint(struct ListGraph *Graph) {
    struct Vertex *pointer = Graph->HeadVertex;
    while (pointer != NULL) {
        printf("{%d %s} -> {", pointer->VertexIndex, pointer->VertexInfo);
        struct Edge *edge_pointer = pointer->HeadEdge;
        while (edge_pointer != NULL) {
            printf(" %d", edge_pointer->VertexNode->VertexIndex);
            edge_pointer = edge_pointer->NextEdge;
        }
        printf(" }\n");
        pointer = pointer->NextVertex;
    }
    printf("----------\n");
}

void FreeEdge(struct Edge *EdgeNode) {
    struct Edge *edge_pointer = EdgeNode;
    while (edge_pointer != NULL) {
        struct Edge *flag = edge_pointer;
        edge_pointer = edge_pointer->NextEdge;
        free(flag);
    }
}

void FreeVertex(struct Vertex *VertexNode) {
    struct Vertex *pointer = VertexNode;
    while (pointer != NULL) {
        struct Vertex *flag = pointer;
        pointer = pointer->NextVertex;
        FreeEdge(flag->HeadEdge);
        // free(flag->VertexInfo);
        free(flag);
    }
}

void FreeListGraph(struct ListGraph *Graph) {
    FreeVertex(Graph->HeadVertex);
    free(Graph);
}

void Sample1(struct ListGraph *Graph) {
    struct Vertex *node_0 = InitVertex("A");
    AppendVertex(Graph, node_0);
    struct Vertex *node_1 = InitVertex("B");
    AppendVertex(Graph, node_1);
    struct Vertex *node_2 = InitVertex("C");
    AppendVertex(Graph, node_2);
    struct Vertex *node_3 = InitVertex("D");
    AppendVertex(Graph, node_3);
    struct Vertex *node_4 = InitVertex("E");
    AppendVertex(Graph, node_4);
    struct Vertex *node_5 = InitVertex("F");
    AppendVertex(Graph, node_5);
    struct Vertex *node_6 = InitVertex("G");
    AppendVertex(Graph, node_6);

    DirectedEdge(node_0, node_1, 0);
    DirectedEdge(node_1, node_2, 0);
    DirectedEdge(node_1, node_3, 0);
    DirectedEdge(node_2, node_0, 0);
    DirectedEdge(node_3, node_0, 0);
    DirectedEdge(node_3, node_2, 0);

    DirectedEdge(node_4, node_5, 0);
    DirectedEdge(node_4, node_6, 0);
    DirectedEdge(node_5, node_1, 0);
    DirectedEdge(node_6, node_5, 0);
    DirectedEdge(node_6, node_3, 0);
}

void Sample2(struct ListGraph *Graph) {
    struct Vertex *node_0 = InitVertex("V1");
    AppendVertex(Graph, node_0);
    struct Vertex *node_1 = InitVertex("V2");
    AppendVertex(Graph, node_1);
    struct Vertex *node_2 = InitVertex("V3");
    AppendVertex(Graph, node_2);
    struct Vertex *node_3 = InitVertex("V4");
    AppendVertex(Graph, node_3);
    struct Vertex *node_4 = InitVertex("V5");
    AppendVertex(Graph, node_4);
    struct Vertex *node_5 = InitVertex("V6");
    AppendVertex(Graph, node_5);
    struct Vertex *node_6 = InitVertex("V7");
    AppendVertex(Graph, node_6);
    struct Vertex *node_7 = InitVertex("V8");
    AppendVertex(Graph, node_7);

    UndirectedEdge(node_0, node_1, 0);
    UndirectedEdge(node_0, node_2, 0);
    UndirectedEdge(node_1, node_3, 0);
    UndirectedEdge(node_1, node_4, 0);
    UndirectedEdge(node_2, node_5, 0);
    UndirectedEdge(node_2, node_6, 0);
    UndirectedEdge(node_3, node_7, 0);
    UndirectedEdge(node_4, node_7, 0);
}

void Sample3(struct ListGraph *Graph) {
    struct Vertex *node_0 = InitVertex("A");
    AppendVertex(Graph, node_0);
    struct Vertex *node_1 = InitVertex("B");
    AppendVertex(Graph, node_1);
    struct Vertex *node_2 = InitVertex("C");
    AppendVertex(Graph, node_2);
    struct Vertex *node_3 = InitVertex("D");
    AppendVertex(Graph, node_3);
    struct Vertex *node_4 = InitVertex("E");
    AppendVertex(Graph, node_4);
    UndirectedEdge(node_0, node_1, 0);
    UndirectedEdge(node_0, node_2, 0);
    UndirectedEdge(node_1, node_4, 0);
    UndirectedEdge(node_1, node_3, 0);
    UndirectedEdge(node_2, node_4, 0);
    UndirectedEdge(node_3, node_4, 0);
    DirectedEdge(node_0, node_1, 0);
    DirectedEdge(node_0, node_2, 0);
    DirectedEdge(node_2, node_3, 0);
    DirectedEdge(node_3, node_0, 0);
}

void Sample4(struct ListGraph *Graph) {
    struct Vertex *node_0 = InitVertex("V0");
    AppendVertex(Graph, node_0);
    struct Vertex *node_1 = InitVertex("V1");
    AppendVertex(Graph, node_1);
    struct Vertex *node_2 = InitVertex("V2");
    AppendVertex(Graph, node_2);
    struct Vertex *node_3 = InitVertex("V3");
    AppendVertex(Graph, node_3);
    struct Vertex *node_4 = InitVertex("V4");
    AppendVertex(Graph, node_4);
    struct Vertex *node_5 = InitVertex("V5");
    AppendVertex(Graph, node_5);
    struct Vertex *node_6 = InitVertex("V6");
    AppendVertex(Graph, node_6);
    struct Vertex *node_7 = InitVertex("V7");
    AppendVertex(Graph, node_7);

    UndirectedEdge(node_0, node_1, 0);
    UndirectedEdge(node_0, node_2, 0);
    UndirectedEdge(node_0, node_5, 0);
    UndirectedEdge(node_0, node_6, 0);
    UndirectedEdge(node_0, node_7, 0);
    UndirectedEdge(node_1, node_7, 0);
    UndirectedEdge(node_3, node_4, 0);
    UndirectedEdge(node_3, node_5, 0);
    UndirectedEdge(node_4, node_5, 0);
    UndirectedEdge(node_4, node_6, 0);
    UndirectedEdge(node_4, node_7, 0);
    UndirectedEdge(node_6, node_7, 0);
}

void SampleFinal(struct ListGraph *Graph) {
    struct Vertex *node_0 = InitVertex("A");
    AppendVertex(Graph, node_0);
    struct Vertex *node_1 = InitVertex("B");
    AppendVertex(Graph, node_1);
    struct Vertex *node_2 = InitVertex("C");
    AppendVertex(Graph, node_2);
    struct Vertex *node_3 = InitVertex("D");
    AppendVertex(Graph, node_3);
    struct Vertex *node_4 = InitVertex("E");
    AppendVertex(Graph, node_4);
    struct Vertex *node_5 = InitVertex("F");
    AppendVertex(Graph, node_5);
    struct Vertex *node_6 = InitVertex("G");
    AppendVertex(Graph, node_6);
    struct Vertex *node_7 = InitVertex("H");
    AppendVertex(Graph, node_7);

    DirectedEdge(node_0, node_2, 0);
    DirectedEdge(node_0, node_4, 0);
    DirectedEdge(node_1, node_0, 0);
    DirectedEdge(node_1, node_2, 0);
    DirectedEdge(node_1, node_6, 0);
    DirectedEdge(node_2, node_5, 0);
    DirectedEdge(node_2, node_6, 0);
    DirectedEdge(node_3, node_1, 0);
    DirectedEdge(node_3, node_5, 0);
    DirectedEdge(node_5, node_7, 0);
    DirectedEdge(node_6, node_4, 0);
    DirectedEdge(node_7, node_6, 0);
}

void BuildGraphManually(struct ListGraph *Graph) {
    SampleFinal(Graph);
    // Sample4(Graph);
}

struct Quack *InitQuack(void) {
    struct Quack *NewQuack = (struct Quack *) malloc(sizeof(struct Quack));
    NewQuack->Head = NewQuack->Tail = NULL;
    NewQuack->Length = 0;
    return NewQuack;
}

struct QuackNode *InitQuackNode(struct Vertex *TargetVertex) {
    struct QuackNode *NewQuackNode = (struct QuackNode *) malloc(sizeof(struct QuackNode));
    NewQuackNode->Next = NewQuackNode->Prev = NULL;
    NewQuackNode->VertexNode = TargetVertex;
    return NewQuackNode;
}

struct Vertex *QuackPop(struct Quack *Stack) {
    struct QuackNode *flag = Stack->Head;
    struct Vertex *pop_node = Stack->Head->VertexNode;
    Stack->Head = Stack->Head->Next;
    if (Stack->Head == NULL) { Stack->Tail = NULL; }
    free(flag);
    Stack->Length--;
    return pop_node;
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

struct Vertex *QuackDeQueue(struct Quack *Queue) {
    struct QuackNode *flag = Queue->Head;
    struct Vertex *leave_node = Queue->Head->VertexNode;
    Queue->Head = Queue->Head->Next;
    if (Queue->Head == NULL) { Queue->Tail = NULL; }
    free(flag);
    Queue->Length--;
    return leave_node;
}

void ApplyQuackNode(struct Vertex *AppliedNode) {
    printf("%s ", AppliedNode->VertexInfo);
}

void PrintQuack(struct Quack *Q) {
    printf("%p -> {Head %p %d Tail %p} :\n", Q, Q->Head, Q->Length, Q->Tail);
    struct QuackNode *pointer = Q->Head;
    while (pointer != NULL) {
        printf("%p -> {%p %p %p}\n", pointer, pointer->Prev, pointer->VertexNode, pointer->Next);
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

bool IsAdjacent(int VertexIndex, struct Edge *EdgeSet) {
    struct Edge *pointer = EdgeSet;
    while (pointer != NULL) {
        if (pointer->VertexNode->VertexIndex == VertexIndex) { return true; }
        pointer = pointer->NextEdge;
    }
    return false;
}

void ListGraphDFS(struct ListGraph *Graph) {
    printf("深度优先遍历\n");
    int length = Graph->VertexNum;
    bool *visited = (bool *) malloc(length * sizeof(bool));
    for (int i = 0; i < length; i++) { visited[i] = false; printf("[%d]", visited[i]); }
    printf("\n\n");
    struct Quack *stack = InitQuack();
    QuackPush(stack, InitQuackNode(Graph->HeadVertex->NextVertex->NextVertex->NextVertex));
    // PrintQuack(stack);
    while (stack->Length != 0) {
        struct Vertex *temp = QuackPop(stack);
        if (visited[temp->VertexIndex] == true) { continue; }
        ApplyQuackNode(temp);
        visited[temp->VertexIndex] = true;
        for (int i = 0; i < length; i++) { printf("[%d]", visited[i]); }
        printf("\n");
        PrintQuack(stack);
        printf("\n");
        struct Vertex *pointer = Graph->TailVertex; // 从后往前 ？？？
        while (pointer != NULL) {
            if ((visited[pointer->VertexIndex] == false) && // 下一个未访问结点集序号是否在出栈边集里面？
                (IsAdjacent(pointer->VertexIndex, temp->HeadEdge) == true)) {
                QuackPush(stack, InitQuackNode(pointer));
            }
            pointer = pointer->PrevVertex;
        }
    }
    printf("\n----------\n");
    free(stack);
    free(visited);
}

void ListGraphBFS(struct ListGraph *Graph) {
    printf("广度优先遍历\n");
    int length = Graph->VertexNum;
    bool *visited = (bool *) malloc(length * sizeof(bool));
    for (int i = 0; i < length; i++) { visited[i] = false; printf("[%d]", visited[i]); }
    printf("\n\n");
    struct Quack *queue = InitQuack();
    QuackEnQueue(queue, InitQuackNode(Graph->HeadVertex));
    // PrintQuack(queue);
    while (queue->Length != 0) {
        struct Vertex *temp = QuackDeQueue(queue);
        if (visited[temp->VertexIndex] == true) { continue; }
        ApplyQuackNode(temp);
        visited[temp->VertexIndex] = true;
        for (int i = 0; i < length; i++) { printf("[%d]", visited[i]); }
        printf("\n");
        struct Vertex *pointer = Graph->HeadVertex; // 从前往后 ？？？
        while (pointer != NULL) {
            if ((visited[pointer->VertexIndex] == false) && // 下一个未访问结点集序号是否在出队边集里面？
                (IsAdjacent(pointer->VertexIndex, temp->HeadEdge) == true)) {
                QuackEnQueue(queue, InitQuackNode(pointer));
            }
            pointer = pointer->NextVertex;
        }
    }
    printf("\n----------\n");
    free(queue);
    free(visited);
}

int main(int argc, char const *argv[]) {
    struct ListGraph *Graph = InitListGraph(0, 0);
    BuildGraphManually(Graph);
    PrintListGraph(Graph);
    NormalPrint(Graph);
    ListGraphDFS(Graph);
    ListGraphBFS(Graph);
    FreeListGraph(Graph);
    return 0;
}
