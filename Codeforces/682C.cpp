#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

int dfs(const vector<vector<pair<int, i64>>>& edges, vector<bool>& visited, vector<pair<i64, int>>& table, int v, i64 cost) {
    visited[v] = true;
    table[v].first = max(table[v].first, cost);
    
    int size = 1;
    
    for (auto [x, c] : edges[v]) {
        if (visited[x]) continue;
        
        size += dfs(edges, visited, table, x, max<i64>(cost + c, 0));
    }
    
    table[v].second = size;
    return size;
}

int dfs(const vector<vector<pair<int, i64>>>& edges, vector<bool>& visited, const vector<pair<i64, int>>& table, const vector<i64>& vertex, int v) {
    auto [cost, subsize] = table[v];
    
    visited[v] = true;
    
    // if sad
    if (cost > vertex[v]) return subsize;
    
    int size = 0;
    
    for (auto [x, _] : edges[v]) {
        if (visited[x]) continue;
        
        size += dfs(edges, visited, table, vertex, x);
    }
    
    return size;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<i64> vertex(n);
    for (auto& x : vertex) cin >> x;
    
    vector<vector<pair<int, i64>>> cost_edge(n);
    
    for (int i = 1; i < n; i++) {
        int b; i64 k; cin >> b >> k;
        
        cost_edge[i].push_back({ b - 1, k });
        cost_edge[b - 1].push_back({ i, k });
    }
    
    // { cost, subtree size }[];
    vector<pair<i64, int>> table(n);
    vector<bool> visited(n);
    
    dfs(cost_edge, visited, table, 0, 0);
    
    visited = vector<bool>(n);
    cout << dfs(cost_edge, visited, table, vertex, 0);
}