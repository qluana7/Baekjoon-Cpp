#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct pos {
    int x, y;
};

vector<pos> mvpos { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };

int table[301][301];

int main() {
    int n; cin >> n;
    
    for (; n--; ) {
        int sz, stx, sty, enx, eny;
        queue<pos> q;
        cin >> sz >> stx >> sty >> enx >> eny;
        
        q.push({stx, sty});
        table[stx][sty]++;
        
        memset(table, 0, sizeof table);
        
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            if (p.x == enx && p.y == eny) break;
            
            for (const pos& ps : mvpos) {
                int a = ps.x + p.x, b = ps.y + p.y;
                if ((a < 0 || sz <= a) || (b < 0 || sz <= b)) continue;
                if (table[a][b] == 0) {
                    table[a][b] = table[p.x][p.y] + 1;
                    q.push({a, b});
                }
            }
        }
        
        cout << table[enx][eny] << "\n";
    }
    
    return 0;
}