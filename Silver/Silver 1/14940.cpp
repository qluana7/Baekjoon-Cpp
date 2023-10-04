#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct tile {
    int x, y, index;
};

int main() {
    int n, m, a, b; cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m)), check(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            
            if (x == 0) board[i][j] = -1;
            else board[i][j] = 0;
            
            if (x == 2) { a = i; b = j; }
        }
    }
    
    queue<tile> q;
    q.push({a, b, 0});
    
    while (!q.empty()) {
        tile p = q.front(); q.pop();
        
        if (check[p.x][p.y]) continue;
        check[p.x][p.y] = 1;
        
        board[p.x][p.y] = p.index;
        
        if ((p.x + 1) < n  && check[p.x + 1][p.y] == 0 && board[p.x + 1][p.y] != -1) q.push({p.x + 1, p.y, p.index + 1});
        if ((p.y + 1) < m  && check[p.x][p.y + 1] == 0 && board[p.x][p.y + 1] != -1) q.push({p.x, p.y + 1, p.index + 1});
        if ((p.x - 1) >= 0 && check[p.x - 1][p.y] == 0 && board[p.x - 1][p.y] != -1) q.push({p.x - 1, p.y, p.index + 1});
        if ((p.y - 1) >= 0 && check[p.x][p.y - 1] == 0 && board[p.x][p.y - 1] != -1) q.push({p.x, p.y - 1, p.index + 1});
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            const int& x = board[i][j];
            
            if (i == a && j == b) cout << 0;
            else if (x == 0) cout << -1;
            else if (x == -1) cout << 0;
            else cout << x;
            
            cout << " ";
        }
        
        cout << "\n";
    }
}