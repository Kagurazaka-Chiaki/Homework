/**
 *
**/

#include <bits/stdc++.h>

using namespace std;


// class TrieNode {
// private:
//     /* data */
//     /* 记录节点类型, 1 完整字串, 0 某个前缀 */
//     bool end;
//     /* 记录节点类型, 1 完整字串, 0 某个前缀 */
//     TrieNode *next[26];
// public:
//     TrieNode(/* args */) {
//         end = false;
//         memset(next, 0, sizeof(next));
//     }
//     ~TrieNode();
// };
// TrieNode::TrieNode(/* args */) {
// }
// TrieNode::~TrieNode() {
// }


// class Trie {
// private:
//     /* data */
//     TrieNode *root;
// public:
//     Trie(/* args */) {
//         root = new TrieNode();
//     };
//     ~Trie();
//     void insert(string word) {
//         TrieNode *now = root;
//         for (int i = 0; i < word.size(); i++) {
//             int child = word[i] - 'a';
//             if (nullptr == now->next[child]) {
//                 now = ..
//             }
//         }
//     }
//     bool search(string word) {
//         TrieNode *now = root;
//         for (int i = 0; i < word.size(); i++) {
//             int child = word[i] - 'a';
//             if (nullptr == now->next[child]) {
//                 return false;
//             }
//         }
//         return now->end;
//     }
//     bool start_with(string prefix) {
//         TrieNode *now = root;
//         for (int i = 0; i < prefix.size(); i++) {
//             if () {
//                 return false;
//             }
//             now = now->~TrieNode
//         }
//         return true;
//     }
// };
// Trie::Trie(/* args */) {
// }
// Trie::~Trie() {
// }


class TrieNode {
public:
    bool end;             // 1 表示从根结点到它是一个完整字典中的串
                          // 0 表示它是某个字符串的前缀
    TrieNode *next[26];   // 指向所有的子结点

    TrieNode() {
        end = false;
        memset(next, 0, sizeof(next));
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *now = root;
        for(int i = 0; i < word.size(); ++i) {
            int child = word[i] - 'a';
            if( nullptr == now->next[child] ) {
                now->next[child] = new TrieNode();
            }
            now = now->next[child];
        }
        now->end = true;
    }
    
    bool search(string word) {
        TrieNode *now = root;
        for(int i = 0; i < word.size(); ++i) {
            int child = word[i] - 'a';
            if( nullptr == now->next[child]) {
                return false;
            }
            now = now->next[child];
        }
        return now->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode *now = root;
        for(int i = 0; i < prefix.size(); ++i) {
            int child = prefix[i] - 'a';
            if( nullptr == now->next[child]) {
                return false;
            }
            now = now->next[child];
        }
        return true;
    }
};


int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    return 0;
}