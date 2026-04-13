#include <iostream>
#include <vector>
#include <array>
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

vector<pair<i64, i64>> table;
vector<vector<u64>> vertex;
vector<char> visit;

u64 dfs(u64 cur, bool early) {
    visit[cur] = 1;
    i64 tmp;
    if ((tmp = (early ? table[cur].first : table[cur].second)) != -1)
        return tmp;
    
    u64 sum = 0;
    
    for (auto nd : vertex[cur]) {
        if (visit[nd]) continue;
        
        if (early)
            sum += min(dfs(nd, true), dfs(nd, false));
        else
            sum += dfs(nd, true);
    }
    
    auto& [cta, ctb] = table[cur];
    
    visit[cur] = 0;
    return (early ? cta : ctb) = sum + early;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    
    table = vector<pair<i64, i64>>(n, { -1, -1 });
    vertex = vector<vector<u64>>(n);
    
    while (n --> 1) {
        int a, b; cin >> a >> b;
        
        vertex[a - 1].push_back(b - 1);
        vertex[b - 1].push_back(a - 1);
    }
    
    for (auto& vx : vertex) sort(vx.begin(), vx.end());
    
    visit = vector<char>(vertex.size(), 0);
    u64 k1 = dfs(0, true);
    visit = vector<char>(vertex.size(), 0);
    u64 k2 = dfs(0, false);
    
    cout << min(k1, k2);
}