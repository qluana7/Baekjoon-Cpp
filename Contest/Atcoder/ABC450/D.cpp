#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <atcoder/all>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    
    vector<int> v(n);
    for (auto& x : v) cin >> x, x %= m;
    
    sort(v.begin(), v.end());
    
    int mn = 2e9;
    for (int i = 0; i < n; i++) {
        int p = (i == 0 ? v.back() : v[i - 1]);
        
        mn = min(mn, p - v[i]);
        v[i] += m;
    }
    
    cout << mn;
}