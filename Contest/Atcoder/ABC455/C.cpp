#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

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
    
    u64 n, m; cin >> n >> m;
    
    u64 sum = 0;
    
    unordered_map<u64, u64> um;
    
    while (n --> 0) {
        u64 k; cin >> k;
        sum += k;
        um[k]++;
    }
    
    vector<pair<u64, u64>> v(um.begin(), um.end());
    
    sort(v.begin(), v.end(), [] (const auto& a, const auto& b) {
        return a.first * a.second > b.first * b.second;
    });
    
    for (u64 i = 0; i < min<u64>(m, v.size()); i++) {
        sum -= v[i].first * v[i].second;
    }
    
    cout << sum;
}