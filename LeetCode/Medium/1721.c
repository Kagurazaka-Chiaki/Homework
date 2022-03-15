/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapNodes(struct ListNode* head, int k){
    int a[100005];
    int asize = 0;
    struct ListNode *ret = head;
    while (head) {
        a[asize++] = head->val;
        head = head->next;
    }

    int tmp = a[k - 1];
    a[k - 1] = a[asize - k];
    a[asize - k] = tmp;

    head = ret;
    asize = 0;
    while (head) {
        head->val = a[asize++];
        head = head->next;
    }
    return ret;
}