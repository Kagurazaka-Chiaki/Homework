#include <iostream>
#include <stack>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x)
        : val(x), next(NULL) {}
};

std::vector<int> reversePrint(ListNode *head) {
    std::stack<int> stack;
    ListNode *pointer = head;
    while (pointer != NULL) {
        std::cout << pointer->val << std::endl;
        stack.push(pointer->val);
        pointer = pointer->next;
    }
    std::vector<int> result;
    while (!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }
    return result;
}

int main(int argc, char const *argv[]) {
    /* code */
    std::cout << "hello, 06" << std::endl;
    return 0;
}
