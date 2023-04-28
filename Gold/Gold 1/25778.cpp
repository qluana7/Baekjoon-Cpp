#include <iostream>
#include <vector>

#define llong long long
#define vint vector<llong>

using namespace std;

vint lazyArr;

llong init(vint& src, vint& tree, int pos, int st, int ed) {
    if (st == ed) return tree[pos] = src[st];
    else return
        tree[pos] =
        init(src, tree, pos << 1, st, (st + ed) / 2) +
        init(src, tree, (pos << 1) + 1, (st +ed) / 2 + 1, ed);
}

llong getSum(vint& tree, int pos, int st, int ed, int lft, int rgt) {
    if (rgt < st || lft > ed) return 0;
    else if (lft <= st && ed <= rgt) return tree[pos];
    else return
        getSum(tree, pos << 1, st, (st + ed) / 2, lft, rgt) +
        getSum(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, lft, rgt);
}

void upd(vint& tree, int pos, int st, int ed, int vpos, llong diff) {
    if (st > vpos || vpos > ed) return;
    tree[pos] += diff;
    if (st == ed) return;
    
    upd(tree, pos << 1, st, (st + ed) / 2, vpos, diff);
    upd(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, vpos, diff);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vint v(n);
    for (auto& x : v) cin >> x;
    
    int vnd = v.size() - 1;
    vint tree(v.size() * 4);
    init(v, tree, 1, 0, vnd);
    
    cin >> n;
    while (n --> 0) {
        char ch; int a, b;
        cin >> ch >> a >> b;
        
        if (ch == 'U') upd(tree, 1, 0, vnd, a - 1, b);
        else cout << getSum(tree, 1, 0, vnd, a - 1, b - 1) << "\n";
    }
    
    return 0;
}