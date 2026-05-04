#include <iostream>
#include <queue>
#include <tuple>

#define qint queue<tuple<int, int, int>>
#define mt make_tuple

using namespace std;

void BFS(int, int, int, qint);

int table[101][101][101];

int main() {
    int x, y, z; cin >> y >> x >> z;
    qint q;
    
    for (int k = 0; k < z; k++) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                cin >> table[k][i][j];
                
                if (table[k][i][j] == 1) q.push(mt(i, j, k));
            }
        }
    }
    
    BFS(x, y, z, q);
    
    int max = 0;
    
    for (int k = 0; k < z; k++) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                //cout << table[k][i][j] << " ";
                if (table[k][i][j] == 0) { cout << -1; return 0; }
                if (table[k][i][j] > max) max = table[k][i][j];
            }
            
            //cout << "\n";
        }
    }
    
    cout << max - 1;
    
    return 0;
}

void BFS(int x, int y, int z, qint q) {
    while (!q.empty()) {
        auto n = q.front(); q.pop();
        int a = get<0>(n), b = get<1>(n), c = get<2>(n);
        
        if (a + 1 < x && table[c][a + 1][b] == 0) {
            table[c][a + 1][b] = table[c][a][b] + 1;
            q.push(mt(a + 1, b, c));
        } if (a - 1 >= 0 && table[c][a - 1][b] == 0) {
            table[c][a - 1][b] = table[c][a][b] + 1;
            q.push(mt(a - 1, b, c));
        } if (b + 1 < y && table[c][a][b + 1] == 0) {
            table[c][a][b + 1] = table[c][a][b] + 1;
            q.push(mt(a, b + 1, c));
        } if (b - 1 >= 0 && table[c][a][b - 1] == 0) {
            table[c][a][b - 1] = table[c][a][b] + 1;
            q.push(mt(a, b - 1, c));
        } if (c + 1 < z && table[c + 1][a][b] == 0) {
            table[c + 1][a][b] = table[c][a][b] + 1;
            q.push(mt(a, b, c + 1));
        } if (c - 1 >= 0 && table[c - 1][a][b] == 0) {
            table[c - 1][a][b] = table[c][a][b] + 1;
            q.push(mt(a, b, c - 1));
        }
    }
}