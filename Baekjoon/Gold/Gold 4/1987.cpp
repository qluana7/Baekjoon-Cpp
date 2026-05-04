#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, mx = 0;
vector<vector<char>> v;

void dfs(vector<vector<bool>>& node, int x, int y, int f, int l) {
    
    node[x][y] = true;
    // cout << x << " " << y << "\n";
    
    if (x + 1 < n  && !node[x + 1][y] && !(f & (1 << (v[x + 1][y] - 65)))) {
        dfs(node, x + 1, y, f | (1 << (v[x + 1][y] - 65)), l + 1);
    }
    if (y + 1 < m  && !node[x][y + 1] && !(f & (1 << (v[x][y + 1] - 65)))) {
        dfs(node, x, y + 1, f | (1 << (v[x][y + 1] - 65)), l + 1);
    }
    if (x - 1 >= 0 && !node[x - 1][y] && !(f & (1 << (v[x - 1][y] - 65)))) {
        dfs(node, x - 1, y, f | (1 << (v[x - 1][y] - 65)), l + 1);
    }
    if (y - 1 >= 0 && !node[x][y - 1] && !(f & (1 << (v[x][y - 1] - 65)))) {
        dfs(node, x, y - 1, f | (1 << (v[x][y - 1] - 65)), l + 1);
    }
    
    node[x][y] = false;
    
    mx = max(mx, l);
}

int main() {
    int t = 0; cin >> n >> m;
    v = vector<vector<char>>(n, vector<char>(m));
    vector<vector<bool>> node(n, vector<bool>(m, 0));
    
    for (auto& p : v) for (char& c : p) cin >> c;
    
    dfs(node, 0, 0, 1 << v[0][0] - 65, 0);
    
    cout << mx + 1;
    
    return 0;
}