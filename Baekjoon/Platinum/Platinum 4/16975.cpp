#include <vector>
#include <iostream>
#include <cmath>

#define llong long long
#define vint vector<llong>

using namespace std;

vint lazyArr;

void updLazy(vint& tree, int pos, int st, int ed) {
    if (lazyArr[pos] != 0) {
        tree[pos] += (llong)(ed - st + 1) * lazyArr[pos];
        
        if (st != ed) {
            lazyArr[pos * 2] += lazyArr[pos];
            lazyArr[pos * 2 + 1] += lazyArr[pos];
        }
        
        lazyArr[pos] = 0;
    }
}

llong init(vint& src, vint& tree, int pos, int st, int ed) {
    if (st == ed) return tree[pos] = src[st];
    else return
        tree[pos] =
        init(src, tree, pos * 2, st, (st + ed) / 2) +
        init(src, tree, pos * 2 + 1, (st +ed) / 2 + 1, ed);
}

llong getSum(vint& tree, int pos, int st, int ed, int lft, int rgt) {
    updLazy(tree, pos, st, ed);
    if (rgt < st || lft > ed) return 0;
    else if (lft <= st && ed <= rgt) return tree[pos];
    else return
        getSum(tree, pos * 2, st, (st + ed) / 2, lft, rgt) +
        getSum(tree, pos * 2 + 1, (st + ed) / 2 + 1, ed, lft, rgt);
}

void updRng(vint& tree, int pos, int st, int ed, int lft, int rgt, llong diff) {
    updLazy(tree, pos, st, ed);
    
    if (rgt < st || lft > ed) return;
    
    if (lft <= st && ed <= rgt) {
        tree[pos] += (llong)(ed - st + 1) * diff;
        if (st != ed) {
            lazyArr[pos * 2] += diff;
            lazyArr[pos * 2 + 1] += diff;
        }
        
        return;
    }
    
    updRng(tree, pos * 2, st, (st + ed) / 2, lft, rgt, diff);
    updRng(tree, pos * 2 + 1, (st + ed) / 2 + 1, ed, lft, rgt, diff);
    tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int k; cin >> k;
    vint tree(1 << (int)log2(k) + 2, 0);
    lazyArr = vint(tree.size(), 0);
    
    vint v;
    
    for (;k--;) {
        llong t; cin >> t;
        v.push_back(t);
    } int ed = v.size() - 1;
    
    init(v, tree, 1, 0, ed);
    
    int n; cin >> n;
    
    for (;n--;) {
        int t; cin >> t;
        
        if (t == 1) {
            int a, b; llong c; cin >> a >> b >> c;
            updRng(tree, 1, 0, ed, a - 1, b - 1, c);
        } else {
            int a, b; cin >> a;
            cout << getSum(tree, 1, 0, ed, a - 1, a - 1) << "\n";
        }
    }
    
    return 0;
}