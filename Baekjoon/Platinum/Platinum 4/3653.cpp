// #include "Algorithm/all"

#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll seg_init(ll v, vector<ll>& tree, ll pos, ll st, ll ed) {
    if (st == ed) return tree[pos] = v;
    else return
        tree[pos] =
            seg_init(v, tree, pos << 1, st, (st + ed) / 2) +
            seg_init(v, tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed);
}

ll seg_sum(vector<ll>& tree, ll pos, ll st, ll ed, ll lft, ll rgt) {
    if (rgt < st || lft > ed) return 0;
    else if (lft <= st && ed <= rgt) return tree[pos];
    else return
        seg_sum(tree, pos << 1, st, (st + ed) / 2, lft, rgt) +
        seg_sum(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, lft, rgt);
}

void seg_update(vector<ll>& tree, ll pos, ll st, ll ed, ll vpos, ll diff) {
    if (st > vpos || vpos > ed) return;
    tree[pos] += diff;
    if (st == ed) return;
    
    seg_update(tree, pos << 1, st, (st + ed) / 2, vpos, diff);
    seg_update(tree, (pos << 1) + 1, (st + ed) / 2 + 1, ed, vpos, diff);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t --> 0) {
        int n, m; cin >> n >> m;
        vector<ll> a(n + 1), tree((n + m + 1) * 4);

        for (int i = 1; i <= n; i++) {
            seg_update(tree, 1, 0, n + m, i, 1);
            a[i] = n - i + 1;
        }

        int ed = n, k = m;
        while (k --> 0) {
            int x; cin >> x;
            cout << seg_sum(tree, 1, 0, n + m, a[x] + 1, ed) << " ";
            seg_update(tree, 1, 0, n + m, a[x], -1); ed++;
            seg_update(tree, 1, 0, n + m, ed, 1);
            a[x] = ed;
        }

        cout << "\n";
    }
}