/**
 *
**/


#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
**/

struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    unordered_map<ListNode *,int> hash;
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        hash.clear();
        while (headA) {
            hash[headA] = 1;
            headA = headA->next;
        }
        while (headB) {
            if (hash.find(headB) != hash.end()) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};


int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    return 0;
}