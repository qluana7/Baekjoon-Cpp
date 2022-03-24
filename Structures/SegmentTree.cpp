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

#define ll long long
#define vint vector<ll>

using namespace std;

ll init(vint& src, vint& tree, int pos, int st, int ed) {
    if (st == ed) return tree[pos] = src[st];
    else return
        tree[pos] =
        init(src, tree, pos * 2, st, (st + ed) / 2) +
        init(src, tree, pos * 2 + 1, (st +ed) / 2 + 1, ed);
}

ll get(vint& tree, int pos, int st, int ed, int lft, int rgt) {
    if (rgt < st || lft > ed) return 0;
    else if (lft <= st && ed <= rgt) return tree[pos];
    else return
        get(tree, pos * 2, st, (st + ed) / 2, lft, rgt) +
        get(tree, pos * 2 + 1, (st + ed) / 2 + 1, ed, lft, rgt);
}

void upd(vint& tree, int pos, int st, int ed, int vpos, ll diff) {
    if (st > vpos || vpos > ed) return;
    tree[pos] += diff;
    if (st == ed) return;
    
    upd(tree, pos * 2, st, (st + ed) / 2, vpos, diff);
    upd(tree, pos * 2 + 1, (st + ed) / 2 + 1, ed, vpos, diff);
}