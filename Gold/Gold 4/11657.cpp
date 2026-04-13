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
    
    vector<i64> table(vertex, inf);
    table[start] = 0;
    
    for (int i = 0; i < vertex - 1; i++) {
        for (int j = 0; j < vertex; j++) {
            if (table[j] == inf) continue;
            
            for (auto [a, b] : edge[j]) {
                table[a] = min(table[a], table[j] + b);
            }
        }
    }
    
    for (int i = 0; i < vertex; i++) {
        if (table[i] == inf) continue;
        
        for (auto [a, b] : edge[i])
            if (table[a] > table[i] + b)
                return {};
    }
    
    return table;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    
    vector<vector<pair<i64, i64>>> edge(n);
    
    while (m --> 0) {
        int a, b, c; cin >> a >> b >> c;
        
        edge[a - 1].push_back({ b - 1, c });
    }
    
    vector<i64> tb = bellman_ford(n, edge, 0);
    
    if (tb.empty())
        cout << -1;
    else {
        for (int i = 1; i < tb.size(); i++)
            cout << (tb[i] == inf ? -1 : tb[i]) << "\n";
    }
}