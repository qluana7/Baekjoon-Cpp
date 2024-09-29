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

#define MAX 1000001

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
	vint seg(MAX * 4, 0);

    int n; cin >> n;

    while (n --> 0) {
        int a, b, c; cin >> a;

        if (a == 1) {
            cin >> b;
            int f = find(seg, 1, 0, MAX - 1, b);
            upd(seg, 1, 0, MAX - 1, f, -1);
            cout << f << "\n";
        } else {
            cin >> b >> c;

            upd(seg, 1, 0, MAX - 1, b, c);
        }
    }
	
	return 0;
}