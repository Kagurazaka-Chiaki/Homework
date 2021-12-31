//

#include <iostream>

#include <deque>

// #include "stack"

#include <stack>

// template<class T, class Sequence = std::deque<T> >
// class Stack {
//     typedef typename Sequence::value_type value_type;
//     typedef typename Sequence::size_type size_type;
//     typedef typename Sequence::reference reference;
//     typedef typename Sequence::const_reference const_reference;
// private:
//     /* data */
// protected:
//     Sequence c;
// public:
//     // stack(/* args */);
//     // ~stack();

//     bool empty() const {
//         return c.empty();
//     }

//     size_type size() const {
//         return c.size();
//     }

//     reference top() {
//         return c.back();
//     }

//     const_reference top() const {
//         return c.back();
//     }

//     void push(const value_type &x) {
//         c.push_back(x);
//     }

//     void pop() {
//         c.pop_back();
//     }
// };


// Stack<int> show_stack(Stack<int> s) {
//     Stack<int> new_stack;
//     while (!s.empty()) {
//         std::cout << s.top() << std::endl;
//         new_stack.push(s.top());
//         s.pop();
//     }
//     return new_stack;
// }


class CQueue {

private:

    std::stack<int> stack1;
    std::stack<int> stack2;

public:
    CQueue() {

    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack2.size() <= 0) {
            while (stack1.size() > 0) {
                int data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }

        if (stack2.size() == 0) {
            return -1;
        }

        int head = stack2.top();
        stack2.pop();

        return head;
    }

};

int main(int argc, char const *argv[]) {

    std::cout << "Hello, 09" << std::endl;

    return 0;
}
