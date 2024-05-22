
#include <stdio.h>
#include <stdlib.h>
// #include <pthread.h>
#include <stdbool.h>

#define MAX 1

struct Detail {
        int value;
};

struct Heap {
        int size;
        struct Detail **array;
};

struct Detail *init_node(int data) {
    struct Detail *new_node = (struct Detail *) malloc(sizeof(struct Detail));
    new_node->value = data;
    return new_node;
}

struct Heap *init_heap(int heap_size) {
    struct Heap *new_heap = (struct Heap *) malloc(sizeof(struct Heap));
    new_heap->array = (struct Detail **) malloc(heap_size * sizeof(struct Detail *));
    for (int i = 0; i < heap_size; i++) {
        new_heap->array[i] = init_node(i);
    }
    new_heap->size = heap_size;
    return new_heap;
}

void swap_node(struct Detail **A, struct Detail **B) {
    // swap_node(struct Detail *A, struct Detail *B);
    // struct Detail temp = *A;  *A = *B; *B = temp;
    struct Detail *temp = *A;
    *A = *B;
    *B = temp;
}

struct Detail *pop_heap(struct Heap *heap) {
    return NULL;
}

void push_heap(struct Heap *heap, struct Detail *node) {
    swap_node(&(heap->array[2]), &(heap->array[3]));
    heap->array[heap->size - 1] = node;
    // heapfiy();
    // shift()
}

struct Heap *resize_heap(struct Heap *heap) {
    return NULL;
}

void print_heap(struct Heap *heap) {
    printf("heap: %p, array: %p, size: %d\n", heap, heap->array, heap->size);
    for (int i = 0; i < heap->size; i++) {
        printf("[%d|%p|%d]\n", i, heap->array[i], heap->array[i]->value);
    }
    printf("\n");
}

void free_heap(struct Heap *heap) {
    for (int i = 0; i < heap->size; i++) {
        free(heap->array[i]);
    }
    free(heap->array);
    free(heap);
}

int main(int argc, char const *argv[]) {
    /* code */

    struct Heap *h = init_heap(5);
    print_heap(h);
    push_heap(h, init_node(42));
    print_heap(h);
    free_heap(h);

    return 0;
}