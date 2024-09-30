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

#define MAX 2097152

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

	vint seg(MAX * 4, 0);

    int n; cin >> n;

    while (n --> 0) {
        int a, b; cin >> a >> b;

        if (a == 1) upd(seg, 1, 0, MAX - 1, b, 1);

        else {
            int t = find(seg, 1, 0, MAX - 1, b);
            upd(seg, 1, 0, MAX - 1, t, -1);
            cout << t << "\n";
        }
    }
	
	return 0;
}