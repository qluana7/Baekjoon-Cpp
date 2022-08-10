#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> vp;

int bfs(vector<vector<int>>& v, int a, int b, int z) {
    int c = 0;
    
    queue<pair<int, int>> q;
    q.push({a, b});
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        
        if (v[x][y] != 0) continue;
        
        vp.emplace_back(x, y);
        v[x][y] = z;
        
        if (x + 1 < n  && v[x + 1][y] == 0) q.push({x + 1, y});
        if (y + 1 < m  && v[x][y + 1] == 0) q.push({x, y + 1});
        if (x - 1 >= 0 && v[x - 1][y] == 0) q.push({x - 1, y});
        if (y - 1 >= 0 && v[x][y - 1] == 0) q.push({x, y - 1});
        
        c++;
    }
    
    return c;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    
    for (auto& vx : v) {
        getchar();
        for (auto& x : vx) x = getchar() - 48;
    }
    
    int z = 2;
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != 0) continue;
            
            idx.push_back(bfs(v, i, j, z));
            z++;
        }
    }
    
    cout << "\n";
    for (auto& vx : v) { for (auto x : vx) cout << x; cout << "\n"; }
    cout << "\n";
    for (auto x : idx) cout << x << " ";
    cout << "\n\n";
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 1) {
                unordered_set<int> s;
                
                int t = 0;
                if (i + 1 < n  && v[i + 1][j] != 1 && !s.count(v[i + 1][j])) { t += idx[v[i + 1][j] - 2]; s.insert(v[i + 1][j]); }
                if (i - 1 >= 0 && v[i - 1][j] != 1 && !s.count(v[i - 1][j])) { t += idx[v[i - 1][j] - 2]; s.insert(v[i - 1][j]); }
                if (j + 1 < m  && v[i][j + 1] != 1 && !s.count(v[i][j + 1])) { t += idx[v[i][j + 1] - 2]; s.insert(v[i][j + 1]); }
                if (j - 1 >= 0 && v[i][j - 1] != 1 && !s.count(v[i][j - 1])) { t += idx[v[i][j - 1] - 2]; }
                
                cout << (t + 1) % 10;
            } else cout << 0;
        }
        cout << "\n";
    }
    
    sort(vp.begin(), vp.end(), [](const auto& a, const auto& b) { if (a.first == b.first) return a.second < b.second; return a.first < b.first; });
    
    for (auto& xp : vp) cout << xp.first << " " << xp.second << "\n";
    
    return 0;
}