#include <iostream>

using namespace std;

void DFS(int table[][50], int x, int y, int a, int b);

int main() {
    int rep; cin >> rep;
    for (; rep--;) {
        int x, y, count; cin >> y >> x >> count;
        auto table = new int [x][50] {};
        
        for (int i = 0; i < count; i++) {
            int a, b; cin >> b >> a;
            
            table[a][b] = 1;
        }
        
        int result = 0;
        
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (table[i][j] == 0) continue;
                
                DFS(table, x, y, i, j);
                result++;
            }
        }
        
        cout << result << endl;
        
        delete[] table;
    }
    
    return 0;
}

void DFS(int table[][50], int x, int y, int a, int b) {
    table[a][b] = 0;
    
    if (a - 1 >= 0 && table[a - 1][b] == 1) DFS(table, x, y, a - 1, b);
    if (b + 1 <  y && table[a][b + 1] == 1) DFS(table, x, y, a, b + 1);
    if (a + 1 <  x && table[a + 1][b] == 1) DFS(table, x, y, a + 1, b);
    if (b - 1 >= 0 && table[a][b - 1] == 1) DFS(table, x, y, a, b - 1);
}