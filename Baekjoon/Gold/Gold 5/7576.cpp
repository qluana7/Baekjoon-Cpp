#include <iostream>
#include <queue>

#define qint queue<pair<int, int>>

using namespace std;

void BFS(int, int, qint q);

int table[1001][1001];

int main() {
    int x, y; cin >> y >> x;
    qint q;
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> table[i][j];
            
            if (table[i][j] == 1) q.push(make_pair(i, j));
        }
    }
    
    BFS(x, y, q);
    
    int max = 0;
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (table[i][j] == 0) { cout << -1; return 0; }
            if (table[i][j] > max) max = table[i][j];
        }
    }
    
    cout << max - 1;
    
    return 0;
}

void BFS(int x, int y, qint q) {
    while (!q.empty()) {
        auto n = q.front(); q.pop();
        int a = n.first, b = n.second;
        
        if (a + 1 < x && table[a + 1][b] == 0) {
            table[a + 1][b] = table[a][b] + 1;
            q.push(make_pair(a + 1, b));
        } if (a - 1 >= 0 && table[a - 1][b] == 0) {
            table[a - 1][b] = table[a][b] + 1;
            q.push(make_pair(a - 1, b));
        } if (b + 1 < y && table[a][b + 1] == 0) {
            table[a][b + 1] = table[a][b] + 1;
            q.push(make_pair(a, b + 1));
        } if (b - 1 >= 0 && table[a][b - 1] == 0) {
            table[a][b - 1] = table[a][b] + 1;
            q.push(make_pair(a, b - 1));
        }
    }
}