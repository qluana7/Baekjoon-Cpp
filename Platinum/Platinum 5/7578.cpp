#include <iostream>
#include <vector>

#define llong long long
#define vint vector<llong>

using namespace std;

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
    
    vector<int> chk(1000001);
    
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) { int x; cin >> x; chk[x] = i; }
    for (auto& x : v) { cin >> x; x = chk[x]; }
    
    vint tree(n * 4);

    llong r = 0;
    for (auto x : v) {
        r += getSum(tree, 1, 0, n - 1, x, n - 1);
        upd(tree, 1, 0, n - 1, x, 1);
    }

    cout << r;
}