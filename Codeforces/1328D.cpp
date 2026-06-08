#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <queue>
#include <bit>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

int dfs(vector<int>& ret, const vector<int>& vt, int cur, int v, int mx) {
    if (cur == vt.size()) {
        if (v == 1) return 1;
        else return 0;
    }
    
    for (int i = 1; i <= mx; i++) {
        if (i == v && vt[cur] != vt[(cur + 1) % vt.size()]) continue;
        
        int r;
        if ((r = dfs(ret, vt, cur + 1, i, mx))) {
            ret[cur] = v;
            return max(r, v);
        }
    }
    
    return 0;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    
    while (t --> 0) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& x : v) cin >> x;
        
        vector<int> ret(n);
        
        int i = 1;
        while (dfs(ret, v, 0, 1, i) == 0) i++;
        
        cout << i << "\n";
        
        for (auto x : ret) cout << x << " ";
        cout << "\n";
    }
}