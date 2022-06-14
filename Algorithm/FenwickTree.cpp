/*
 * Algorithm Name : Fenwick Tree
 *
 * Description
 *    - 펜윅트리 트리 구현
 * 
 * Reference
 *    - https://www.acmicpc.net/blog/view/21
 */

#include <vector>

#define llong long long
#define vll vector<llong>

using namespace std;

vll init(vll);
llong getSum(vll&, llong);
void update(vll&, llong, llong);

vll init(vll arr) {
    vll tree(arr.size() + 1, 0);
    
    int len = arr.size();
    for (int i = 0; i < len; i++) update(tree, i + 1, arr[i]);
    
    return tree;
}

llong getSum(vll& tree, llong val) {
    llong out = 0;
    
    while (val > 0) {
        out += tree[val];
        val -= val & -val;
    }
    
    return out;
}

void update(vll& tree, llong ind, llong val) {
    while (ind < tree.size()) {
        tree[ind] += val;
        ind += ind & -ind;
    }
}