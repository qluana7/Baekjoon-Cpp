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

#define i64 long long
#define vi64 vector<i64>

using namespace std;

vi64 init(vi64);
i64 getSum(vi64&, i64);
void update(vi64&, i64, i64);

vi64 init(vi64 arr) {
    vi64 tree(arr.size() + 1, 0);
    
    int len = arr.size();
    for (int i = 0; i < len; i++) update(tree, i + 1, arr[i]);
    
    return tree;
}

i64 getSum(vi64& tree, i64 val) {
    i64 out = 0;
    
    while (val > 0) {
        out += tree[val];
        val -= val & -val;
    }
    
    return out;
}

void update(vi64& tree, i64 ind, i64 val) {
    while (ind < tree.size()) {
        tree[ind] += val;
        ind += ind & -ind;
    }
}