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
    
    vector<vector<char>> v(n, vector<char>(m));
    vector<pair<int, int>> pts;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            
            if (v[i][j] == '.')
                pts.push_back({ i, j });
        }
    }
    
    int cnt = 0;
    for (const auto& pt : pts) {
        if (v[pt.first][pt.second] == '#') continue;
        
        bool wall = false;
        queue<pair<int, int>> q;
        q.push(pt);
        
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (v[x][y] == '#') continue;
            
            v[x][y] = '#';
            
            if (x + 1 == n || x == 0 || y + 1 == m || y == 0) wall = true;
            
            if (x + 1 != n && v[x + 1][y] != '#') q.push({ x + 1, y });
            if (y + 1 != m && v[x][y + 1] != '#') q.push({ x, y + 1 });
            if (x != 0 && v[x - 1][y] != '#') q.push({ x - 1, y });
            if (y != 0 && v[x][y - 1] != '#') q.push({ x, y - 1 });
        }
        
        cnt += !wall;
    }
    
    cout << cnt;
}