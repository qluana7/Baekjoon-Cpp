#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

void add(vector<vector<ll>>& tree, ll size, ll ind, ll value) {
    ind += size; tree[ind].push_back(value);
}

void merge_init(vector<vector<ll>>& tree, ll size, const vector<ll>& v, ll n) {
    for (ll i = 1; i <= n; i++) add(tree, size, i, v[i - 1]);

    for (ll i = size - 1; i > 0; i--) {
        tree[i].resize(tree[i*2].size() + tree[i*2+1].size());
        merge(
            tree[i*2].begin(), tree[i*2].end(),
            tree[i*2+1].begin(), tree[i*2+1].end(),
            tree[i].begin()
        );
    }
}

ll merge_query(vector<vector<ll>>& tree, ll size, ll a, ll b, ll k) {
    a += size; b += size;

    ll r = 0;

    while (a <= b) {
        if (a & 1)  { r += tree[a].end() - upper_bound(tree[a].begin(), tree[a].end(), k); a++; }
        if (~b & 1) { r += tree[b].end() - upper_bound(tree[b].begin(), tree[b].end(), k); b--; }

        a >>= 1; b >>= 1;
    }

    return r;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    ll size = 1 << 17;
    vector<vector<ll>> tree(size * 2);

    int n; cin >> n;
    vector<ll> v(n);
    for (auto& x : v) cin >> x;

    merge_init(tree, size, v, n);

    ll last = 0;
    cin >> n;
    while (n --> 0) {
        ll a, b, k; cin >> a >> b >> k;
        a ^= last; b ^= last; k ^= last;
        cout << (last = merge_query(tree, size, a, b, k)) << "\n";
    }
}