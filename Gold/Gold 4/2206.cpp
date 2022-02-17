#include <iostream>
#include <queue>
#include <tuple>

#define mp make_tuple

using namespace std;

void BFS(int, int);

int table[1001][1001][2];

int main() {
    int x, y; cin >> x >> y;
    
    for (int i = 0; i < x; i++) {
        getchar();
        for (int j = 0; j < y; j++) {
            table[i][j][0] = getchar() == '0';
            table[i][j][1] = table[i][j][0];
        }
    }
    
    BFS(x, y);
    
    int t1 = table[x - 1][y - 1][0], t2 = table[x - 1][y - 1][1];
            
    cout << (t1 != 1 && t2 != 1 ? min(t1, t2) : t1 != 1 ? t1 : t2 != 1 ? t2 : 0) - 1 << "\n";
    
    return 0;
}

void BFS(int x, int y) {
    queue<tuple<int, int, bool>> q;
    
    table[0][0][1]++;
    table[0][0][0]++;
    q.push(mp(0, 0, true));
    
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int a = get<0>(p), b = get<1>(p);
        bool c = get<2>(p);
        
        if (!c) {
            if (b + 1 < y && table[a][b + 1][c] == 1) {
                table[a][b + 1][c] = table[a][b][c] + 1;
                q.push(mp(a, b + 1, c));
            } if (a + 1 < x && table[a + 1][b][c] == 1) {
                table[a + 1][b][c] = table[a][b][c] + 1;
                q.push(mp(a + 1, b, c));
            } if (b - 1 >= 0 && table[a][b - 1][c] == 1) {
                table[a][b - 1][c] = table[a][b][c] + 1;
                q.push(mp(a, b - 1, c));
            } if (a - 1 >= 0 && table[a - 1][b][c] == 1) {
                table[a - 1][b][c] = table[a][b][c] + 1;
                q.push(mp(a - 1, b, c));
            }
        } else {
            if (b + 1 < y) {
                if (table[a][b + 1][c] == 1) {
                    int n = table[a][b][c] + 1;
                    table[a][b + 1][c] = n;
                    if (table[a][b + 1][!c] == 1)
                        table[a][b + 1][!c] = n;
                    q.push(mp(a, b + 1, c));
                } else if (table[a][b + 1][!c] < 2) {
                    table[a][b + 1][!c] = table[a][b][c] + 1;
                    q.push(mp(a, b + 1, !c));
                }
            } if (a + 1 < x) {
                if (table[a + 1][b][c] == 1) {
                    int n = table[a][b][c] + 1;
                    table[a + 1][b][c] = n;
                    if (table[a + 1][b][!c] == 1)
                        table[a + 1][b][!c] = n;
                    q.push(mp(a + 1, b, c));
                } else if (table[a + 1][b][!c] < 2) {
                    table[a + 1][b][!c] = table[a][b][c] + 1;
                    q.push(mp(a + 1, b, !c));
                }
            } if (b - 1 >= 0) {
                if (table[a][b - 1][c] == 1) {
                    int n = table[a][b][c] + 1;
                    table[a][b - 1][c] = n;
                    if (table[a][b - 1][!c] == 1)
                        table[a][b - 1][!c] = n;
                    q.push(mp(a, b - 1, c));
                } else if (table[a][b - 1][!c] < 2) {
                    table[a][b - 1][!c] = table[a][b][c] + 1;
                    q.push(mp(a, b - 1, !c));
                }
            } if (a - 1 >= 0) {
                if (table[a - 1][b][c] == 1) {
                    int n = table[a][b][c] + 1;
                    table[a - 1][b][c] = n;
                    if (table[a - 1][b][!c] == 1)
                        table[a - 1][b][!c] = n;
                    q.push(mp(a - 1, b, c));
                } else if (table[a - 1][b][!c] < 2) {
                    table[a - 1][b][!c] = table[a][b][c] + 1;
                    q.push(mp(a - 1, b, !c));
                }
            }
        }
    }
}