
#include <iostream>

// #include <vector>
// #include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *new_node = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return new_node;
}

int main(int argc, char const *argv[]) {
    /* code */

    (void) argc; (void) argv;

    std::cout << "hello, 06" << std::endl;
    return 0;
}