#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

inline void split(const std::string& src, std::vector<std::string>& dest, char delim)
{ std::stringstream ss(src); for (std::string s; std::getline(ss, s, delim); dest.push_back(s)); }

struct BTreeNode {
    BTreeNode() = default;
    BTreeNode(const string& k) : key(k), children() { }

    string key;
    map<string, BTreeNode*> children;
};

struct BTree {
    BTree() : root(nullptr) { }

    BTreeNode* root;

    void insert(const string& path);
};

void BTree::insert(const string& path) {
    BTreeNode* node = root;

    vector<string> paths; split(path, paths, '\\');

    for (auto& p : paths) {
        if (node->children.find(p) == node->children.end())
            node->children[p] = new BTreeNode(p);

        node = node->children[p];
    }
}

void __print(BTreeNode* node, int depth) {
    for (auto& [k, v] : node->children) {
        cout << string(depth, ' ') << k << "\n";
        __print(v, depth + 1);
    }
}

void print(const BTree& tree) {
    __print(tree.root, 0);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    BTree tree;

    tree.root = new BTreeNode();

    while (n --> 0) {
        string path; cin >> path;
        tree.insert(path);
    }
    
    print(tree);
}