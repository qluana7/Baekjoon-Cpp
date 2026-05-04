#include <iostream>
#include <string>
#include <vector>

#define ll long long
#define vint vector<ll>

using namespace std;

ll find(vint& tree, int pos, int st, int ed, int k) {
    if (st == ed) return st;

    if (tree[pos * 2] >= k) return find(tree, pos * 2, st, (st + ed) / 2, k);
    else return find(tree, pos * 2 + 1, (st + ed) / 2 + 1, ed, k - tree[pos * 2]);
}

void upd(vint& tree, int pos, int st, int ed, int vpos, ll diff) {
    if (st > vpos || vpos > ed) return;
    tree[pos] += diff;
    if (st == ed) return;
    upd(tree, pos * 2, st, (st + ed) / 2, vpos, diff);
    upd(tree, pos * 2 + 1, (st + ed) / 2 + 1, ed, vpos, diff);
}

#define MAX 65536

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

	vint seg(MAX * 4, 0);

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    int e = 0; ll t = 0;
    for (; e < k; e++) upd(seg, 1, 0, MAX - 1, v[e], 1);
    t += find(seg, 1, 0, MAX - 1, (k + 1) / 2);

    for (; e < n; e++) {
        upd(seg, 1, 0, MAX - 1, v[e - k], -1);
        upd(seg, 1, 0, MAX - 1, v[e], 1);

        t += find(seg, 1, 0, MAX - 1, (k + 1) / 2);
    }

    cout << t;
	
	return 0;
}