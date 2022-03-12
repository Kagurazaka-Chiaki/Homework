
#include <stdio.h>
#include <stdlib.h>
// #include <pthread.h>
#include <stdbool.h>

#define MAX 1


struct Detail {
    int Value;
};

struct Node {
    // pthread_mutex_t *mutex;
    struct Detail *Data;
    struct Node *Prev;
    struct Node *Next;
};

struct Queue {
    int Length;
    struct Node *Head;
    struct Node *Tail;
};