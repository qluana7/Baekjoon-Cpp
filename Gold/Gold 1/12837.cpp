#include <iostream>
#include <vector>

#define ll long long
#define vint vector<ll>

using namespace std;

ll init(vint& src, vint& tree, int pos, int st, int ed) {
    if (st == ed) return tree[pos] = src[st];
    else return
        tree[pos] =
        init(src, tree, pos << 1, st, (st + ed) / 2) +
        init(src, tree, (pos << 1) + 1, (st +ed) / 2 + 1, ed);
}

ll get(vint& tree, int pos, int st, int ed, int lft, int rgt) {
    if (rgt < st || lft > ed) return 0;
    else if (lft <= st && ed <= rgt) return tree[pos];
    else return
        get(tree, pos << 1, st, (st + ed) / 2, lft, rgt) +
        get(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, lft, rgt);
}

void upd(vint& tree, int pos, int st, int ed, int vpos, ll diff) {
    if (st > vpos || vpos > ed) return;
    tree[pos] += diff;
    if (st == ed) return;
    
    upd(tree, pos << 1, st, (st + ed) / 2, vpos, diff);
    upd(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, vpos, diff);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vint v(n), tree(n * 4);
    
    init(v, tree, 1, 0, n - 1);
    
    for (;m--;) {
        int c, a; ll b;
        cin >> c >> a >> b;
        
        if (c == 1) upd(tree, 1, 0, n - 1, a - 1, b);
        else cout << get(tree, 1, 0, n - 1, a - 1, b - 1) << "\n";
    }
    
    return 0;
}