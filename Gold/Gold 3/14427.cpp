#include <iostream>
#include <vector>

#define vint vector<ind>

using namespace std;

struct ind {
    int ind, val;
};

inline ind min(ind a, ind b) {
    int x, y;
    if (a.val == b.val) { x = a.ind; y = b.ind; }
    else { x = a.val; y = b.val; }
    
    return x < y ? a : b;
}

ind init(vint& src, vint& tree, int pos, int st, int ed) {
    if (st == ed) return tree[pos] = src[st];
    else return
        tree[pos] = min(
        init(src, tree, pos << 1, st, (st + ed) / 2),
        init(src, tree, (pos << 1) + 1, (st +ed) / 2 + 1, ed));
}

void upd(vint& tree, int pos, int st, int ed, int vpos, int value) {
    if (st > vpos || vpos > ed) return;
    if (st == ed) { tree[pos].val = value; return; }
    
    upd(tree, pos << 1, st, (st + ed) / 2, vpos, value);
    upd(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, vpos, value);
    
    tree[pos] = min(tree[pos << 1], tree[(pos << 1) + 1]);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vint v;
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back({i + 1, x});
    }
    
    int sz = v.size();
    vint tree(sz * 4);
    
    init(v, tree, 1, 0, sz - 1);
    
    int m; cin >> m;
    for (;m--;) {
        int c; cin >> c;
        
        if (c == 1) {
            int x, y; cin >> x >> y;
            upd(tree, 1, 0, sz - 1, x - 1, y);
        }
        else cout << tree[1].ind << "\n";
    }
    
    return 0;
}