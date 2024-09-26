/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

    ListNode *target_node_prev(ListNode *list, int a) {
        if (list == nullptr) { return nullptr; }
        ListNode *pointer = list;
        for (int i = 0; i < a - 1; i++) {
            pointer = pointer->next;
        }
        return pointer;
    }

    ListNode *target_list_last(ListNode *list) {
        if (list == nullptr) { return nullptr; }
        ListNode *pointer = list;
        while (pointer != nullptr) {
            pointer = pointer->next;
        }
        return pointer;
    }

  public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        // ListNode *a_prev = target_node_prev(list1, a);
        // ListNode *b_prev = target_node_prev(list1, b);
        // ListNode *last_l2 = target_list_last(list2);

        ListNode *ret = list1;
        ListNode *alist1 = list1;
        ListNode *blist1 = list1;
        ListNode *nowlist2 = list2;


        b++;
        while (b--) {
            blist1 = blist1->next;
        }

        while (nowlist2->next) {
            nowlist2 = nowlist2->next;
        }

        nowlist2->next = blist1;

        a--;
        while (a--) {
            alist1 = alist1->next;
        }

        alist1->next = list2;

        return ret;
    }
};