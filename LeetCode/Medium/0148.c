/**
 * @brief 148. 排序链表
 * 
 * 归并排序
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *MergeList(struct ListNode *List1, struct ListNode *List2) {
    if (List1 == NULL) { return List2; }
    if (List2 == NULL) { return List1; }
    if (List1->val - List2->val < 0) {
        List1->next = MergeList(List1->next, List2);
        return List1;
    } else {
        List2->next = MergeList(List1, List2->next);
        return List2;
    }
}

struct ListNode *MergeSort(struct ListNode *Original) {
    if (Original == NULL || Original->next == NULL) { return Original; }
    struct ListNode *fast = Original;
    struct ListNode *slow = Original;
    struct ListNode *break_point = Original;
    while (fast != NULL && fast->next != NULL) {
        break_point = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    break_point->next = NULL;

    struct ListNode *right = MergeSort(slow);
    struct ListNode *left = MergeSort(Original);
    return MergeList(left, right);
}

struct ListNode *sortList(struct ListNode *head) {
    return head = NULL ? NULL : MergeSort(head);
}

