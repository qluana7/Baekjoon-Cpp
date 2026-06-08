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

constexpr u64 INF = ~(u64)0;

vector<vector<u64>> table;

u64 g(const vector<int>& v, int b, int e) {
    if (table[b][e] != INF) return table[b][e];
    
    u64 mn = INF;
    
    if (b > 0) mn = min(mn, g(v, b - 1, e));
    if (e < v.size() - 1) mn = min(mn, g(v, b, e + 1));
    
    if (mn == INF) mn = 0;
    
    return table[b][e] = (v[e] - v[b]) + mn;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    
    ranges::sort(v);
    
    u64 mn = INF;
    
    table = vector<vector<u64>>(n, vector<u64>(n, INF));
    
    for (int i = 0; i < v.size(); i++)
        mn = min(mn, g(v, i, i));
    
    cout << mn;
}