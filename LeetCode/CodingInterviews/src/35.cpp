#include <iostream>

#include <stack>
#include <vector>

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *deep_copy_node(Node *node, Node *next_node, Node *random_node) {
    Node *result = new Node(node->val);
    // result->val = node->val;
    result->next = next_node;
    result->random = random_node;
    return result;
}

Node *connect_order_node(Node *original_list) {
    std::cout << "connect_order_node" << std::endl;
    Node *loop_pointer = original_list;
    while (loop_pointer != nullptr) {
        Node *temp = deep_copy_node(loop_pointer, nullptr, nullptr);
        temp->next = loop_pointer->next;
        loop_pointer->next = temp;
        loop_pointer = loop_pointer->next->next;
    }
    return original_list;
}

void connect_random_node(Node *original_list) {
    std::cout << "connect_random_node" << std::endl;
    Node *loop_pointer = original_list;
    while (loop_pointer != nullptr) {
        Node *deep_copied = loop_pointer->next;
        if (loop_pointer->random != nullptr) {
            deep_copied->random = loop_pointer->random->next;
        }
        loop_pointer = deep_copied->next;
    }
}

Node *split_node(Node *compound_list) {
    Node *result = nullptr;
    Node *loop_pointer = compound_list;
    Node *head = result;
    int odd_even = 0;
    while (loop_pointer != nullptr) {
        // std::cout << loop_pointer->val << std::endl;
        if (++odd_even % 2 == 0) {
            if (result == nullptr) {
                result = loop_pointer;
                head = result;
            } else {
                head->next = loop_pointer;
                head = head->next;
            }
            loop_pointer = loop_pointer->next;
        } else {
            Node *temp = loop_pointer;
            loop_pointer = loop_pointer->next;
            temp->next = temp->next->next;
        }

    }
    return result;
}

Node *copyRandomList(Node *head) {
    Node *compound_list = connect_order_node(head);
    Node *result = split_node(compound_list);
    return result;
}

Node *build_list(std::vector<int> data) {
    std::cout << "Build List size: " << data.size() << std::endl;
    Node *result = nullptr;
    Node *loop_pointer = result;
    for (int i = 0; i < data.size(); i++) {
        if (result == nullptr) {
            result = new Node(data[i]);
            loop_pointer = result;
        } else {
            loop_pointer->next = new Node(data[i]);
            loop_pointer = loop_pointer->next;
        }
    }
    return result;
}

void print_list(Node *head) {
    std::cout << "Print List" << std::endl;
    Node *loop_pointer = head;
    while (loop_pointer != nullptr) {
        printf("%p -> [%d %p %p]\n", loop_pointer, loop_pointer->val, loop_pointer->next, loop_pointer->random);
        loop_pointer = loop_pointer->next;
    }
}

Node *nth_node(Node *head, int n) {
    Node *loop_pointer = head;
    while (n--) {
        loop_pointer = loop_pointer->next;
    }
    return loop_pointer;
}

void ath_point_bth_node(Node *head, int a, int b) {
    Node *ath_pointer = nth_node(head, a);
    Node *bth_pointer = nth_node(head, b);
    ath_pointer->random = bth_pointer;
}

void handle_list(Node *head) {
    ath_point_bth_node(head, 0, 2);
    ath_point_bth_node(head, 1, 4);
    ath_point_bth_node(head, 3, 1);
}

int main(int argc, char const *argv[]) {
    /* code */
    std::cout << "hello, 35" << std::endl;

    std::vector<int> data = {
        1, 2, 3, 4, 5
    };

    Node *sample = build_list(data);

    print_list(sample);

    handle_list(sample);

    print_list(sample);

    Node *compound_list = connect_order_node(sample);

    print_list(compound_list);

    connect_random_node(compound_list);

    print_list(compound_list);

    Node *result = split_node(compound_list);

    print_list(result);

    print_list(compound_list);

    return 0;
}

// // solution 2
// // head
// // head2
// // ret_head
// // pre_head
// Node *copyRandomList(Node *head) {
//     if (head == nullptr) { return nullptr; }
//     Node *ret_head = new Node(head->val);
//     Node *head2 = ret_head;
//     Node *pre_head = head->next;
//     while (pre_head) {
//         ret_head->next = new Node(pre_head->val);
//         pre_head = pre_head->next;
//         ret_head = ret_head->next;
//     }

//     pre_head = head, ret_head = head2;
//     while (pre_head) {
//         Node *target = pre_head->random;
//         Node *go = head;
//         int cnt = 0;
//         while (go != target) {
//             go = go->next;
//             ++cnt;
//         }
//         go = head2;
//         while (cnt) {
//             go = go->next;
//             --cnt;
//         }
//         ret_head->random = go;
//         pre_head = pre_head->next;
//         ret_head = ret_head->next;
//     }
//     return head2;
// }