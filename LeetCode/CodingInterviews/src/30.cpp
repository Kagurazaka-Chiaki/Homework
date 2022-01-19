#include <iostream>

#include <stack>

class MinStack {
private:
    std::stack<int> stack1, stack2;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stack1.push(x);

        if (stack2.empty()) {
            stack2.push(x);
        } else {
            int current_top = stack2.top();
            if (x < current_top) {
                stack2.push(x);
            } else {
                stack2.push(current_top);
            }
        }
    }

    void pop() {
        stack1.pop();
        stack2.pop();
    }

    int top() {
        return stack1.top();
    }

    int min() {
        return stack2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main(int argc, char const *argv[]) {

    std::cout << "Hello, 30" << std::endl;

    return 0;
}
