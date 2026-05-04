#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long
#define vint vector<ll>

using namespace std;

struct SetQuery {
    int i, v;
};

struct GetQuery {
    int k, i, j, ind;
};

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
    else
        return get(tree, pos * 2, st, (st + ed) / 2, lft, rgt) + get(tree, pos * 2 + 1, (st + ed) / 2 + 1, ed, lft, rgt);
}

void upd(vint& tree, int pos, int st, int ed, int vpos, ll diff) {
    if (st > vpos || vpos > ed) return;
    tree[pos] += diff;
    if (st == ed) return;
    upd(tree, pos * 2, st, (st + ed) / 2, vpos, diff);
    upd(tree, pos * 2 + 1, (st + ed) / 2 + 1, ed, vpos, diff);
}

int main()
{
	int n, m, ind = 0; cin >> n;
	vint v(n); vector<SetQuery> vsq; vector<GetQuery> vgq;
	for (auto& x : v) cin >> x;

    cin >> m;
    while (m --> 0) {
        int x; cin >> x;

        if (x == 1) {
            int a, b; cin >> a >> b;
            vsq.push_back({a, b});
        } else {
            int a, b, c; cin >> a >> b >> c;
            vgq.push_back({a, b, c, ind});
            ind++;
        }
    }

    sort(vgq.begin(), vgq.end(), [](const GetQuery& q1, const GetQuery& q2) {
        return q1.k < q2.k;
    });
	
	int sz = v.size();
	int vnd = sz - 1;
	
	vint seg(sz * 4);
	
	init(v, seg, 1, 0, vnd);
    
    vector<pair<int, ll>> result;

    int cq = 0;
	for (const auto& gq : vgq) {
        for (; cq < gq.k; cq++) {
            const auto& sq = vsq[cq];
	         upd(seg, 1, 0, vnd, sq.i - 1, sq.v - v[sq.i - 1]);
	         v[sq.i - 1] = sq.v;
	    }
	    result.push_back({ gq.ind, get(seg, 1, 0, vnd, gq.i - 1, gq.j - 1)});
	}

    sort(result.begin(), result.end(), [](const auto& p1, const auto& p2) {
        return p1.first < p2.first;
    });

    for (auto [_, r] : result) cout << r << "\n";
}