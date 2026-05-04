#include <iostream>
#include <queue>

using namespace std;

int BFS();

int table[101];

int main() {
    int n, m; cin >> n >> m;
    
    for (int i = 0; i < n + m; i++) {
        int x, y; cin >> x >> y;
        table[x] = y;
    }
    
    cout << BFS();
}

int BFS() {
    queue<pair<int, int>> q;
    table[1] = -1;
    q.push({1, 0});
    
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        
        if (x.first == 100) return x.second;
        
        for (int i = 1; i <= 6; i++) {
            int tmp = table[x.first + i];
            if (tmp == -1 || x.first + i > 100) continue;
            
            q.push({tmp ? tmp : x.first + i, x.second + 1});
            table[x.first + i] = -1;
        }
    }
}