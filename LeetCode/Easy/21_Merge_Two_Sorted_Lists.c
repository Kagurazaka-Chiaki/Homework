/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *k = l1;

    if (l1 == NULL) {
        return l2;
    } else {
        while (k->next != NULL) {
            k = k->next;
        }
        k->next = l2;
    }

    struct ListNode *P1 = l1;
    while (P1 != NULL) {
        struct ListNode *P2 = l1;
        while (P2->next != NULL) {
            if (P2->val > P2->next->val) {
                int temp = P2->val;
                P2->val = P2->next->val;
                P2->next->val = temp;
            }
            P2 = P2->next;
        }
        P1 = P1->next;
    }

    return l1;
}