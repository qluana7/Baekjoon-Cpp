/*
 * Algorithm Name : Segment Tree
 *
 * Description
 *    - 세그먼트 트리 구현
 * 
 * Reference
 *    - https://www.acmicpc.net/blog/view/9
 */

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
    updLazy(tree, pos, st, ed);
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

void updLazy(vint& tree, int pos, int st, int ed) {
    if (lazyArr[pos] != 0) {
        tree[pos] += (ed - st + 1) * lazyArr[pos];
        
        if (st != ed) {
            lazyArr[pos << 1] += lazyArr[pos];
            lazyArr[(pos << 1) + 1] += lazyArr[pos];
        }
        
        lazyArr[pos] = 0;
    }
}

void updRng(vint& tree, int pos, int st, int ed, int lft, int rgt, int diff) {
    updLazy(tree, pos, st, ed);
    
    vint v(tree.size(), 0);
    
    if (rgt < st || lft > ed) return;
    
    if (lft <= st && ed <= rgt) {
        tree[pos] += (ed - st + 1) * diff;
        if (st != ed) {
            lazyArr[pos << 1] += diff;
            lazyArr[(pos << 1) + 1] += diff;
        }
    } else {
        updRng(tree, pos << 1, st, (st + ed) / 2, lft, rgt, diff);
        updRng(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, lft, rgt, diff);
        tree[pos] = tree[pos << 1] + tree[(pos << 1) + 1];
    }
}