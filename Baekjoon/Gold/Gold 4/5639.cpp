#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) { }

    int value;
    TreeNode* left, *right;
};

struct BinaryTree {
    BinaryTree() : root(nullptr) { }

    TreeNode* root;

    void insert(int x);
};

void BinaryTree::insert(int x) {
    if (root == nullptr) {
        root = new TreeNode(x);
        return;
    }

    TreeNode* c = root;

    while (true) {
        if (c->value > x) {
            if (c->left == nullptr) {
                c->left = new TreeNode(x);
                break;
            } else c = c->left;
        } else {
            if (c->right == nullptr) {
                c->right = new TreeNode(x);
                break;
            } else c = c->right;
        }
    }
}

void postorder(TreeNode* node) {
    if (node == nullptr) return;

    postorder(node->left);

    postorder(node->right);

    cout << node->value << "\n";
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; BinaryTree tree;
    while (cin >> n) tree.insert(n);

    postorder(tree.root);
}