#include <iostream>
#include <vector>

using namespace std;

struct pos { int x, y; };

int main() {
    int n, m; cin >> n >> m;
    
    vector<vector<int>> v(n + 4, vector<int>(m + 4));
    vector<vector<pos>> move {
        { { -1,  1 }, { -1,  2 }, { 0, 3 }, { 1, 2 }, { 1, 1 }, { 1, 0 } },
        { {  1,  2 }, {  2,  1 } },
        { {  1, -1 }, { -1,  1 }, { 1, 1 } },
        { {  2,  1 }, {  1,  2 } },
        { {  1, -1 }, {  2, -1 }, { 3, 0 }, { 2, 1 }, { 1, 1 }, { 0, 1 } }
    };
    vector<vector<pos>> imove {
        { { 0, 1 }, { 0, 2 } },
        { { 0, 1 }, { 1, 1 } },
        { { 0, 1 }, { 1, 0 } },
        { { 1, 0 }, { 1, 1 } },
        { { 1, 0 }, { 2, 0 } }
    };
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];
    
    int mx = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int p = 0, len = imove.size(); p < len; p++) {
                int t = v[i][j] + v[i + imove[p][0].x][j + imove[p][0].y] + v[i + imove[p][1].x][j + imove[p][1].y];
                for (pos q : move[p]) { mx = max(mx, t + v[i + q.x][j + q.y]); }
            }
        }
    }
    
    cout << mx;
    
    return 0;
}