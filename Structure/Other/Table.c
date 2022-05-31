
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// #define OPEN_MAX 10

// typedef struct FileDescriptorNode {
//     int size;
//     int mode;
// } fd_node;

// typedef struct FileDescriptorTable {
//     fd_node *filedescriptor[OPEN_MAX];
// } fd_table;

// typedef struct OpenFileNode {
//     off_t _pos;
//     // int _refercount;
//     // struct vnode *_vnode;
//     // struct lock *_mutex;
// } of_node;

// typedef struct OpenFileTable {
//     int size;
//     of_node **node;
// } of_table;


// fd_table *init_fd_table() {
//     fd_table *new_fd_table = malloc(sizeof(fd_table));
//     for (int i = 0; i < OPEN_MAX; i++) {
//         new_fd_table->filedescriptor[i] = NULL;
//     }
//     return new_fd_table;
// }

// fd_node *init_fd_node() {
//     fd_node *new_fd_node = malloc(sizeof(fd_node));
//     new_fd_node->mode = -1;
//     new_fd_node->size = -1;
//     return new_fd_node;
// }

// of_table *init_of_table() {
//     of_table *new_of_table = malloc(sizeof(of_table));
//     return new_of_table;
// }

// of_node *init_of_node() {
//     of_node *new_of_node = malloc(sizeof(of_node));
//     return new_of_node;
// }


#define LEVEL_1 10
#define LEVEL_2 5

// typedef struct Table {
//     int val;
// } table;

typedef int table;

typedef struct Space {
    table **t;
} space;


space *table_create(void) {
    space *s = malloc(sizeof(space));
    if (s->t == NULL) {
        s->t = malloc(LEVEL_1 * sizeof(table *));
    }
    for (int i = 0; i < LEVEL_1; i++) {
        s->t[i] = NULL;
    }
    return s;
}

int table_insert(space *s, int i, int j, int val) {
    if (s->t[i] == NULL) {
        s->t[i] = malloc(LEVEL_2 * sizeof(table));
        for (int k = 0; k < LEVEL_2; k++) {
            s->t[i][k] = 0;
        }
    }
    s->t[i][j] = val;
    return 0;
}

int table_lookup(space *s, int i, int j) {
    if (s == NULL) { return -1; }
    if (s->t[i] == NULL) { return -1; }
    if (s->t[i][j] == 0) { return -1; }
    return 0;
}

int table_copy(table **old, table **new) {
    for (int i = 0; i < LEVEL_1; i++) {
        // printf("[i = %d]", i);
        if (old[i] == NULL) {
            new[i] = NULL;
            continue;
        }
        new[i] = malloc(LEVEL_2 * sizeof(table));
        for (int j = 0; j < LEVEL_2; j++) {
            // printf("[j = %d]", j);
            if (old[i][j] == 0) {
                new[i][j] = 0;
                continue;
            }
            new[i][j] = old[i][j];
        }
    }
    return 0;
}

int table_delete(space *s, int i, int j) {
    s->t[i][j] = 0;
    return 0;
}

int table_destory(space *s) {
    for (int i = 0; i < LEVEL_1; i++) {
        if (s->t[i] == NULL) { continue; }
        for (int j = 0; j < LEVEL_2; j++) {
            if (s->t[i][j] == 0) { continue; }
            table_delete(s, i, j);
        }
        free(s->t[i]);
    }
    free(s->t);
    return 0;
}

int table_print(space *s) {
    if (s == NULL) { printf("null\n"); return 0; }
    for (int i = 0; i < LEVEL_1; i++) {
        if (s->t[i] == NULL) {
            printf("%p:->\n", s->t[i]);
            continue;
        }
        printf("%p[%d]:->", s->t[i], i);
        for (int j = 0; j < LEVEL_2; j++) {
            printf("[%p[%d] -> %d]", s->t[i][j], j, s->t[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------------------\n");
    return 0;
}

int main(int argc, char const *argv[]) {
    /* code */

    space *s;
    table_print(s);
    s = table_create();
    table_print(s);
    table_insert(s, 2, 0, 233);
    table_print(s);
    table_insert(s, 2, 0, 234);
    table_print(s);
    int r = table_lookup(s, 2, 0);
    printf("%d", r);
    space *k = table_create();
    table_copy(s->t, k->t);
    table_print(k);
    table_delete(k, 2, 0);
    table_print(k);
    table_destory(s);
    table_destory(k);
    free(s);
    free(k);
    return 0;
}