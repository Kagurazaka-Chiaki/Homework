/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head);
void Print(struct ListNode *List);
void Append(struct ListNode *List, int AppendData);

int main(void) {

    struct ListNode *List = (struct ListNode *) malloc(sizeof(struct ListNode));
    List->val = 1;
    List->next = NULL;

    Append(List, 1);
    Append(List, 2);

    Print(List);

    deleteDuplicates(List);

    Print(List);

    return 0;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    } else {
        struct ListNode *pointer = head;
        while (pointer->next->next != NULL) {
            int repeatflag = 0;
            if (pointer->val == pointer->next->val) {
                repeatflag = 1;
                struct ListNode *flag = pointer->next;
                pointer->next = pointer->next->next;
                free(flag);
            }
            if (repeatflag == 0) {
                pointer = pointer->next;
            }
        }
        if (pointer->val == pointer->next->val) {
            struct ListNode *flag = pointer->next;
            pointer->next = NULL;
            free(flag);
        }
    }
    return head;
}

void Append(struct ListNode *List, int AppendData) {
    struct ListNode *NewData = (struct ListNode *) malloc(sizeof(struct ListNode));
    NewData->val = AppendData;
    NewData->next = NULL;
    
    struct ListNode *point = List;
    while (point->next != NULL) {
        point = point->next;
    }
    point->next = NewData;
}

void Print(struct ListNode *List) {
    struct ListNode *point = List;
    while (point != NULL) {
        printf("[%d|%d]->", point, point->val);
        point = point->next;
    }
    printf("\n");
}