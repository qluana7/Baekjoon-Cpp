#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <queue>

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
    
    int n, m, k; cin >> n >> m >> k;
    
    vector<int> vertex(n);
    for (auto& x : vertex) cin >> x;
    vector<vector<int>> edges(n);
    vector<int> dep(k);
    
    while (m --> 0) {
        int a, b; cin >> a >> b;
        
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }
    
    queue<pair<int, int>> q;
    vector<bool> visited(n);
    
    q.push({ 0, 0 });
    
    while (!q.empty()) {
        auto [k, d] = q.front(); q.pop();
        
        if (visited[k]) continue;
        
        visited[k] = true;
        dep[vertex[k] - 1] = d;
        
        for (auto x : edges[k]) {
            if (visited[x]) continue;
            q.push({ x, d + 1 });
        }
    }
    
    for (auto x : dep)
        cout << x << " ";
}