#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

struct node {
    int key;
    node* parent = nullptr, *child = nullptr;
};

int node_count(node* nd) {
    int cnt = 0;
    
    for (; nd != nullptr; cnt++)
        nd = nd->child;
        
    return cnt;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    
    vector<node*> nds(n, nullptr);
    for (int i = 0; i < nds.size(); i++)
        nds[i] = new node{i};
        
    while (m --> 0) {
        int a, b; cin >> a >> b;
        
        auto* cur = nds[a - 1], *nxt = nds[b - 1];
        
        if (cur->parent != nullptr)
            cur->parent->child = nullptr;
        cur->parent = nxt;
        nxt->child = cur;
    }
    
    for (int i = 0; i < nds.size(); i++) {
        if (nds[i]->parent != nullptr) cout << 0 << " ";
        else cout << node_count(nds[i]) << " ";
    }
}