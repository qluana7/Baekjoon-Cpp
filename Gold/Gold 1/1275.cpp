#include <iostream>
#include <vector>

#define lint long long int
#define vint vector<lint>

using namespace std;

lint init(vint& src, vint& tree, lint pos, lint st, lint ed) {
    if (st == ed) return tree[pos] = src[st];
    else return
        tree[pos] =
        init(src, tree, pos << 1, st, (st + ed) / 2) +
        init(src, tree, (pos << 1) + 1, (st +ed) / 2 + 1, ed);
}

lint getSum(vint& tree, lint pos, lint st, lint ed, lint lft, lint rgt) {
    if (rgt < st || lft > ed) return 0;
    else if (lft <= st && ed <= rgt) return tree[pos];
    else return
        getSum(tree, pos << 1, st, (st + ed) / 2, lft, rgt) +
        getSum(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, lft, rgt);
}

void upd(vint& tree, lint pos, lint st, lint ed, lint vpos, lint diff) {
    if (st > vpos || vpos > ed) return;
    tree[pos] += diff;
    if (st == ed) return;
    
    upd(tree, pos << 1, st, (st + ed) / 2, vpos, diff);
    upd(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, vpos, diff);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    lint n, m, sz; cin >> n >> m; sz = n;
    vector<lint> v, tree(n * 4);
    
    for (;n--;) {
        int x; cin >> x;
        v.push_back(x);
    }
    
    init(v, tree, 1, 0, sz - 1);
    
    for (;m--;) {
        lint x, y, a, b; cin >> x >> y >> a >> b;
        
        if (x > y) swap(x, y);
        cout << getSum(tree, 1, 0, sz - 1, x - 1, y - 1) << "\n";
        upd(tree, 1, 0, sz - 1, a - 1, b - getSum(tree, 1, 0, sz - 1, a - 1, a - 1));
    }
    
    return 0;
}