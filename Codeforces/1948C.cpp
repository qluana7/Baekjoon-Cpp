#include <iostream>
#include <vector>
#include <string>
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

inline bool bchk(int x, int y, int n) { return !(x & -2) && ((unsigned)y < (unsigned)n); }

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    
    while (t --> 0) {
        int n; cin >> n;
        
        vector<string> grid(2);
        for (auto& s : grid) cin >> s;
        
        vector<vector<bool>> visited(2, vector<bool>(n));
        
        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        
        bool flag = false;
        
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            
            if (x == 1 && y == n - 1) {
                flag = true;
                break;
            }
            
            if (visited[x][y]) continue;
            visited[x][y] = true;
            
            for (auto [x0, y0] : { pair<int, int> { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }) {
                int nx = x + x0, ny = y + y0;
                
                // boundary check
                if (bchk(nx, ny, n))
                    q.push({ nx, ny + ((grid[nx][ny] == '>') * 2 - 1) });
            }
        }
        
        cout << (flag ? "YES" : "NO") << "\n";
    }
}