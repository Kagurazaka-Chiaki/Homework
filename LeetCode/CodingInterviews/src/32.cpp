/**
 *
**/


#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>


int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    std::vector<int> level_order(TreeNode *root) {

    }

    std::vector<std::vector<int>> levelOrder(TreeNode *root) {

    }

    std::vector<std::vector<int>> levelReOrder(TreeNode *root) {

    }
};

int Height(TreeNode *root) {
    if (root == NULL) { return 0; }
    // int left = Height(root->left);
    // int Right = Height(root->Right);
    // printf("[%d]", abs(left - Right));
    // PrintTreeNode(root);
    // return 1 + ((left > Right) ? left : Right);
    return max(Height(root->left), Height(root->right)) + 1;
}


TreeNode *RotateLeft(TreeNode *root) {
    if (root == NULL) { return NULL; }
    if (root->right == NULL) { return root; }

    TreeNode *Pivot = root->right;
    root->right = Pivot->left;
    Pivot->left = root;
    // root->Height = max(Height(root->left), Height(root->right)) + 1;
    // Pivot->Height = max(Height(Pivot->right), Height(root)) + 1;
    root = Pivot;
    return root;
}


TreeNode *RotateRight(TreeNode *root) {
    if (root == NULL) { return NULL; }
    if (root->left == NULL) { return root; }

    TreeNode *Piovt = root->left;
    root->left = Piovt->right;
    Piovt->right = root;
    // root->Height = max(Height(root->left), Height(root->right)) + 1;
    // Piovt->Height = max(Height(Piovt->left), Height(root)) + 1;
    root = Piovt;
    return root;
}

TreeNode *insert_tree_node(TreeNode *root, int value) {
    if (root == nullptr) { return new TreeNode(value); }
    if (root->left == nullptr) {
        root->left = insert_tree_node(root->left, value);
    } else if (root->right == nullptr) {
        root->right = insert_tree_node(root->right, value);
    }
    return root;
}

TreeNode *AVLInsertBiTNode(TreeNode *root, int value) {
    if (root == NULL) { return new TreeNode(value); }
    if (root->val < value) {
        root->right = insert_tree_node(root->right, value);
    } else if (root->val > value) {
        root->left = insert_tree_node(root->left, value);
    } else {
        return root;
    }

    // root->Height = 1 + max(Height(root->left), Height(root->right));

    if (Height(root->left) - Height(root->right) > 1) {
        printf("1\n");
        if (value > root->left->val) {
            root->left = RotateLeft(root->left);
            root = RotateRight(root);
        } else {
            root = RotateRight(root);
        }
    } else if (Height(root->right) - Height(root->left) > 1) {
        printf("2");
        if (value < root->right->val) {
            root->right = RotateRight(root->right);
            root = RotateLeft(root);
        } else {
            root = RotateLeft(root);
        }
    }

    return root;
}

void Deserialize(TreeNode *root, std::vector<std::string> data) {
    if (data.empty()) {
        return;
    }
    std::string top = data.at(0);
    std::cout << top << std::endl;
}

TreeNode *build_tree() {
    TreeNode *result = nullptr;

    auto data = std::vector<std::string>{
        "3", "9", "20","null", "null", "15","7"
    };

    for (auto i : data) {
        if (i == "null") {
            continue;
        } else {
            int v = atoi(i.c_str());
            printf("insert [%d]\n", v);
            if (result == nullptr) {
                result = new TreeNode(v);
            } else {
                result = insert_tree_node(result, v);
            }
        }
    }

    return result;
}

/**
 * Dot
**/
void DotPrint(TreeNode *root) {
    if (root != NULL) {
        printf("%d -> {", root->val);
        if (root->left != NULL) {
            printf(" %d", root->left->val);
        }
        printf(" ");
        if (root->right != NULL) {
            printf("%d ", root->right->val);
        }
    }
    printf("}\n");
}

void print_tree_node(TreeNode *node) {
    printf("%p -> {%p|%d|%p} --> ", node, node->left, node->val, node->right);
    printf("\n");
}

void DFS(TreeNode *root) {
    if (root == NULL) { return; }
    // PrintTreeNode(root);
    DFS(root->left);
    print_tree_node(root);
    // DotPrint(root);
    DFS(root->right);
    // PrintTreeNode(root);
}


int main(int argc, char const *argv[]) {
    /* code */
    (void) argc; (void) argv;

    auto s = new Solution();

    auto t = build_tree();

    DFS(t);

    return 0;
}