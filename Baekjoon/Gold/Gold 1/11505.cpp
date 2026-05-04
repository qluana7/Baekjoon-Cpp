#include <iostream>
#include <string>
#include <vector>

#define ll unsigned long long
#define vint vector<ll>
#define mod 1000000007

using namespace std;

ll init(vint& src, vint& tree, int pos, int st, int ed) {
    if (st == ed) return tree[pos] = src[st];
    else return
        tree[pos] =
        (init(src, tree, pos * 2, st, (st + ed) / 2) *
        init(src, tree, pos * 2 + 1, (st +ed) / 2 + 1, ed)) % mod;
}

ll get(vint& tree, int pos, int st, int ed, int lft, int rgt) {
    if (rgt < st || lft > ed) return 1;
    else if (lft <= st && ed <= rgt) return tree[pos];
    else
        return (get(tree, pos * 2, st, (st + ed) / 2, lft, rgt) * get(tree, pos * 2 + 1, (st + ed) / 2 + 1, ed, lft, rgt)) % mod;
}

void upd(vint& tree, int pos, int st, int ed, int vpos, ll value) {
    if (st > vpos || vpos > ed) return;
    if (st == ed) { tree[pos] = value; return; }
    
    upd(tree, pos * 2, st, (st + ed) / 2, vpos, value);
    upd(tree, pos * 2 + 1, (st + ed) / 2 + 1, ed, vpos, value);
    
    tree[pos] = (tree[pos << 1] * tree[(pos << 1) + 1]) % mod;
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
	int n, px, py, sz; cin >> n >> px >> py; sz = n;
    vint vec, tree(n * 4);
	for (;n--;) {
	    ll tmp; cin >> tmp;
	    vec.push_back(tmp);
	}
    
    init(vec, tree, 1, 0, sz - 1);
    
    for (px+=py;px--;) {
        int c, a, b; cin >> c >> a >> b;
        
        if (c == 1) upd(tree, 1, 0, sz - 1, a - 1, b);
        else cout << get(tree, 1, 0, sz - 1, a - 1, b - 1) << "\n";
    }
	
	return 0;
}