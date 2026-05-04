#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct tile {
    int x, y;
};

int main() {
    int n, m, a, b; cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m)), check(n, vector<char>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            board[i][j] = c;
            if (c == 'I') { a = i; b = j; }
        }
    }
    
    int count = 0;
    queue<tile> q;
    q.push({a, b});
    
    while (!q.empty()) {
        tile p = q.front(); q.pop();
        
        if (check[p.x][p.y]) continue;
        check[p.x][p.y] = 1;
        if (board[p.x][p.y] == 'P') count++;
        
        if ((p.x + 1) < n  && check[p.x + 1][p.y] == 0 && board[p.x + 1][p.y] != 'X') q.push({p.x + 1, p.y});
        if ((p.y + 1) < m  && check[p.x][p.y + 1] == 0 && board[p.x][p.y + 1] != 'X') q.push({p.x, p.y + 1});
        if ((p.x - 1) >= 0 && check[p.x - 1][p.y] == 0 && board[p.x - 1][p.y] != 'X') q.push({p.x - 1, p.y});
        if ((p.y - 1) >= 0 && check[p.x][p.y - 1] == 0 && board[p.x][p.y - 1] != 'X') q.push({p.x, p.y - 1});
    }
    
    if (count) cout << count;
    else cout << "TT";
}