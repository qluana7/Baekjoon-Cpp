#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
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

vector<bool> visited;
vector<bool> found;

void dfs(const vector<vector<int>>& edges, int st) {
    found[st] = true;
    
    visited[st] = true;
    
    for (auto x : edges[st]) {
        if (visited[x]) continue;
        
        dfs(edges, x);
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    
    vector<vector<int>> edges(n);
    visited = vector<bool>(n, false);
    found = vector<bool>(n, false);
    
    while (m --> 0) {
        int a, b; cin >> a >> b;
        
        edges[a - 1].push_back(b - 1);
    }
    
    set<int> k;
    dfs(edges, 0);
    
    int cnt = 0;
    for (auto b : found)
        cnt += b;
        
    cout << cnt;
}