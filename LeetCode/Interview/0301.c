#include <stdbool.h>

typedef struct {
    int *data;
    int size;
    int top[3];
} TripleInOne;


TripleInOne* tripleInOneCreate(int stackSize) {
    TripleInOne *array = (TripleInOne *)malloc(sizeof(TripleInOne));
    array->data = (int *)malloc(sizeof(int) * stackSize * 3);
    array->size = stackSize;
    for (int i = 0; i < 3; i++) { array->top[i] = 0; }
    return array;
}

void tripleInOnePush(TripleInOne* obj, int stackNum, int value) {
    if (obj->top[stackNum] == obj->size) { return; }
    obj->data[stackNum * obj->size + (obj->top[stackNum]++)] = value;
}

bool tripleInOneIsEmpty(TripleInOne* obj, int stackNum) {
    return (bool) (0 == obj->top[stackNum]);
}

int tripleInOnePop(TripleInOne* obj, int stackNum) {
    if (tripleInOneIsEmpty(obj, stackNum)) { return -1; }
    return obj->data[stackNum * obj->size + (--obj->top[stackNum])];

}

int tripleInOnePeek(TripleInOne* obj, int stackNum) {
    if (tripleInOneIsEmpty(obj, stackNum)) { return -1; }
    return obj->data[stackNum * obj->size + (obj->top[stackNum] - 1)];
}


void tripleInOneFree(TripleInOne* obj) {
    free(obj);
}

/**
 * Your TripleInOne struct will be instantiated and called as such:
 * TripleInOne* obj = tripleInOneCreate(stackSize);
 * tripleInOnePush(obj, stackNum, value);
 
 * int param_2 = tripleInOnePop(obj, stackNum);
 
 * int param_3 = tripleInOnePeek(obj, stackNum);
 
 * bool param_4 = tripleInOneIsEmpty(obj, stackNum);
 
 * tripleInOneFree(obj);
*/