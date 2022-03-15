/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct {
    int asize;
    int a[10010];
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    Solution *obj = (Solution *)malloc(sizeof(Solution));
    obj->asize = 0;
    while (head) {
        obj->a[obj->asize++] = head->val;
        head = head->next;
    }
    return obj;
}

int solutionGetRandom(Solution* obj) {
    return obj->a[ rand() % obj->asize ];
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/