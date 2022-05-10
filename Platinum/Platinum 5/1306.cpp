#include <iostream>
#include <vector>
#include <string>

#define vint vector<int>

using namespace std;

int init(vint& src, vint& tree, int pos, int st, int ed) {
    if (st == ed) return tree[pos] = src[st];
    else return
        tree[pos] = max(
        init(src, tree, pos << 1, st, (st + ed) / 2),
        init(src, tree, (pos << 1) + 1, (st +ed) / 2 + 1, ed));
}

int get(vint& tree, int pos, int st, int ed, int lft, int rgt) {
    if (rgt < st || lft > ed) return 0;
    else if (lft <= st && ed <= rgt) return tree[pos];
    else return max(
        get(tree, pos << 1, st, (st + ed) / 2, lft, rgt),
        get(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, lft, rgt));
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vint mv;
    
    for (;n--;) {
        int x; cin >> x;
        mv.push_back(x);
    }
    
    int sz = mv.size();
    vint tree(sz * 4);
    
    init(mv, tree, 1, 0, sz - 1);
    
    for (int i = m - 1; i < sz - (m - 1); i++) cout << get(tree, 1, 0, sz - 1, i - (m - 1), i + (m - 1)) << " ";
    
    return 0;
}