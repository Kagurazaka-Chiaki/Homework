
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define OPEN_MAX 10

typedef struct FileDescriptorNode {
    int size;
    int mode;
} fd_node;

typedef struct FileDescriptorTable {
    fd_node *filedescriptor[OPEN_MAX];
} fd_table;

typedef struct OpenFileNode {
    off_t _pos;
    // int _refercount;
    // struct vnode *_vnode;
    // struct lock *_mutex;
} of_node;

typedef struct OpenFileTable {
    int size;
    of_node **node;
} of_table;


fd_table *init_fd_table() {
    fd_table *new_fd_table = malloc(sizeof(fd_table));
    for (int i = 0; i < OPEN_MAX; i++) {
        new_fd_table->filedescriptor[i] = NULL;
    }
    return new_fd_table;
}

fd_node *init_fd_node() {
    fd_node *new_fd_node = malloc(sizeof(fd_node));
    new_fd_node->mode = -1;
    new_fd_node->size = -1;
    return new_fd_node;
}

of_table *init_of_table() {
    of_table *new_of_table = malloc(sizeof(of_table));
    return new_of_table;
}

of_node *init_of_node() {
    of_node *new_of_node = malloc(sizeof(of_node));
    return new_of_node;
}


int main(int argc, char const *argv[]) {
    /* code */

    fd_table *f = init_fd_table();

    for (int i = 0; i < OPEN_MAX; i++) {
        printf("[%p]", f->filedescriptor[i]);
    }
    

    return 0;
}