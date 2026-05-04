#include <iostream>
#include <vector>

#define vint vector<int>

using namespace std;

int init(vint& src, vint& tree, int pos, int st, int ed) {
    if (st == ed) return tree[pos] = src[st];
    else return
        tree[pos] =
        init(src, tree, pos << 1, st, (st + ed) / 2) *
        init(src, tree, (pos << 1) + 1, (st +ed) / 2 + 1, ed);
}

int get(vint& tree, int pos, int st, int ed, int lft, int rgt) {
    if (rgt < st || lft > ed) return 1;
    else if (lft <= st && ed <= rgt) return tree[pos];
    else return
        get(tree, pos << 1, st, (st + ed) / 2, lft, rgt) *
        get(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, lft, rgt);
}

void upd(vint& tree, int pos, int st, int ed, int vpos, int diff) {
    if (st > vpos || vpos > ed) return;
    if (st == ed) { tree[pos] = diff; return; }
    
    upd(tree, pos << 1, st, (st + ed) / 2, vpos, diff);
    upd(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, vpos, diff);
    
    tree[pos] = tree[pos << 1] * tree[(pos << 1) + 1];
}

#define conv(x) ((x) < 0 ? -1 : (x) > 0 ? 1 : 0)
#define outp(x) ((x) < 0 ? '-' : (x) > 0 ? '+' : '0')

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m;
    
    while (cin >> n >> m) {
        vint v, tree(n * 4); int sz = n;
        for (;n--;) {
            int x; cin >> x;
            v.push_back(conv(x));
        }
        
        init(v, tree, 1, 0, sz - 1);
        
        for (;m--;) {
            char c; int a, b;
            cin >> c >> a >> b;
            
            if (c == 'C') upd(tree, 1, 0, sz - 1, a - 1, conv(b));
            else {
                int q = get(tree, 1, 0, sz - 1, a - 1, b - 1);
                cout << outp(q);
            }
        }
        
        cout << "\n";
    }
    
    return 0;
}