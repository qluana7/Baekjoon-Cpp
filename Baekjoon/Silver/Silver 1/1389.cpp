#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int table[101][101];
int visit[101];
int _sz;

int BFS(int);

int main() {
    int n; cin >> _sz >> n;
    
    for (; n--; ) {
        int x, y; cin >> x >> y;
        
        table[x][y] = 1;
        table[y][x] = 1;
    }
    
    int p = 1, m = BFS(1);
    
    for (int i = 2; i <= _sz; i++) {
        memset(visit, 0, sizeof(visit));
        int tmp = BFS(i);
        if (tmp < m) {
            m = tmp;
            p = i;
        }
    }
    
    cout << p;
    
    return 0;
}

int BFS(int n) {
    queue<pair<int, int>> q;
    int sum = 0;
    
    visit[n] = 1;
    q.push({n, 0});
    
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        sum += x.second;
        
        for (int i = 1; i <= _sz; i++) {
            if (visit[i] || !table[x.first][i]) continue;
            
            q.push({i, x.second + 1});
            visit[i] = 1;
        }
    }
    
    return sum;
}