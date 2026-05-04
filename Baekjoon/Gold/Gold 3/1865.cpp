#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

constexpr i64 inf = numeric_limits<i64>::max();

vector<i64> bellman_ford(u64 vertex, const vector<vector<pair<i64, i64>>>& edge, u64 start) {
    vector<i64> table(vertex, -1);
    table[start] = 0;
    
    for (int i = 0; i < vertex - 1; i++) {
        for (int j = 0; j < vertex; j++) {
            for (auto [a, b] : edge[j]) {
                table[a] = min(table[a], table[j] + b);
            }
        }
    }
    
    for (int i = 0; i < vertex; i++) {
        for (auto [a, b] : edge[i])
            if (table[a] > table[i] + b)
                return {};
    }
    
    return table;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    
    while (t --> 0) {
        int n, m, k; cin >> n >> m >> k;
        
        vector<vector<pair<i64, i64>>> edge(n);
        
        while (m --> 0) {
            int a, b, c; cin >> a >> b >> c;
            edge[a - 1].push_back({ b - 1, c });
            edge[b - 1].push_back({ a - 1, c });
        }
        
        while (k --> 0) {
            int a, b, c; cin >> a >> b >> c;
            edge[a - 1].push_back({ b - 1, -c });
        }
        
        cout << (bellman_ford(n, edge, 0).empty() ? "YES" : "NO") << "\n";
    }
}