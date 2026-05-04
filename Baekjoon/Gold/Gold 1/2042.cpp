#include <iostream>
#include <string>
#include <vector>

#define ll long long
#define vint vector<ll>

using namespace std;

struct command {
    bool cmd;
    ll p1, p2;
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
	int n, px, py; cin >> n >> px >> py;
	vint vec; vector<command> cmd;
	for (;n--;) {
	    ll tmp; cin >> tmp;
	    vec.push_back(tmp);
	}
	for (int x = px + py; x--;) {
	    ll t1, t2, t3; cin >> t1 >> t2 >> t3;
	    cmd.push_back({t1 == 1, t2, t3});
	}
	
	int sz = vec.size();
	int vnd = sz - 1;
	
	vint seg(sz * 4);
	
	init(vec, seg, 1, 0, vnd);
	
	for (const auto& c : cmd) {
	    if (c.cmd) {
	         upd(seg, 1, 0, vnd, c.p1 - 1, c.p2 - vec[c.p1 - 1]);
	         vec[c.p1 - 1] = c.p2;
	    }
	    else cout << get(seg, 1, 0, vnd, c.p1 - 1, c.p2 - 1) << "\n";
	}
	
	return 0;
}