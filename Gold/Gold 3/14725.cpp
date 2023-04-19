#include <iostream>
#include <map>

using namespace std;

struct Node {
    Node* parent;
    string value;
    map<string, Node*> children;
};

void dfs(Node* cnode, int depth) {
    cout << string(depth * 2, '-') << cnode->value << "\n";
    for (const auto& node : cnode->children) dfs(node.second, depth + 1);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    Node* root = new Node { nullptr, "", map<string, Node*>{} };
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        
        Node* cnode = root;
        for (int j = 0; j < m; j++) {
            string str; cin >> str;
            
            if (!cnode->children.count(str)) {
                cnode->children[str] = new Node { cnode, str, map<string, Node*>{} };
            }
            cnode = cnode->children[str];
        }
    }
    
    for (const auto& p : root->children) dfs(p.second, 0);
    
    return 0;
}