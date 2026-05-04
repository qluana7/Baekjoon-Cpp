#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<pair<int, int>> vp;

bool check(int x, int y, int n) {
    for (int i = 0; i < 9; i++) {
        if (v[i][y] == n) return false;
        if (v[x][i] == n) return false;
    }
    
    for (int i = 0, m1 = x / 3 * 3; i < 3; i++)
        for (int j = 0, m2 = y / 3 * 3; j < 3; j++)
            if (v[i+m1][j+m2] == n) return false;
    
    return true;
}

bool solve(int x, int y, int n, int id) {
    if (!check(x, y, n)) return false;
    
    v[x][y] = n;
    
    if (id == vp.size()) return true;
    
    for (int i = 1; i <= 9; i++) {
        if (solve(vp[id].first, vp[id].second, i, id + 1)) return true;
    }
    
    v[x][y] = 0;
    return false;
}

int main() {
    v = vector<vector<int>>(9, vector<int>(9));
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> v[i][j];
            
            if (v[i][j] == 0) vp.emplace_back(i, j);
        }
    }
    
    for (int i = 1; i <= 9; i++) if (solve(vp[0].first, vp[0].second, i, 1)) break;
    
    for (auto& vx : v) { for(auto x : vx) cout << x << " "; cout << "\n"; }
    
    return 0;
}