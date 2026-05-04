#include <iostream>
#include <queue>

#define mp make_pair

using namespace std;

int BFS(int, int);

int table[101][101];

int main() {
    int x, y; cin >> x >> y;
    
    for (int i = 0; i < x; i++) {
        getchar();
        for (int j = 0; j < y; j++) {
            table[i][j] = getchar() - 48;
        }
    }
    
    cout << BFS(x, y) - 1;
    
    return 0;
}

int BFS(int x, int y) {
    queue<pair<int, int>> q;
    
    table[0][0]++;
    q.push(mp(0, 0));
    
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int a = p.first, b = p.second;
        
        if (a == x - 1 && b == y - 1) return table[a][b];
        
        if (a + 1 < x && table[a + 1][b] == 1) {
            table[a + 1][b] = table[a][b] + 1;
            q.push(mp(a + 1, b));
        } if (b + 1 < y && table[a][b + 1] == 1) {
            table[a][b + 1] = table[a][b] + 1;
            q.push(mp(a, b + 1));
        } if (a - 1 >= 0 && table[a - 1][b] == 1) {
            table[a - 1][b] = table[a][b] + 1;
            q.push(mp(a - 1, b));
        } if (b - 1 >= 0 && table[a][b - 1] == 1) {
            table[a][b - 1] = table[a][b] + 1;
            q.push(mp(a, b - 1));
        }
    }
}