#include <iostream>

using namespace std;

void DFS(int(*)[101], int, int, int);

int count1, count2;
int _size;

int table1[101][101];
int table2[101][101];

int main() {
    cin >> _size;
    
    for (int i = 0; i < _size; i++) {
        getchar();
        for (int j = 0; j < _size; j++) {
            char x = getchar();
            table1[i][j] = x == 'R' ? 1 : x == 'G' ? 2 : 3;
            table2[i][j] = x == 'R' || x == 'G' ? 1 : 2;
        }
    }
    
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (table1[i][j] != 0) { DFS(table1, i, j, table1[i][j]); count1++; }
            if (table2[i][j] != 0) { DFS(table2, i, j, table2[i][j]); count2++; }
        }
    }
    
    cout << count1 << " " << count2;
    
    return 0;
}

void DFS(int table[][101], int x, int y, int v) {
    table[x][y] = 0;
    
    if (x - 1 >= 0     && table[x - 1][y] == v) DFS(table, x - 1, y, v);
    if (y + 1 <  _size && table[x][y + 1] == v) DFS(table, x, y + 1, v);
    if (x + 1 <  _size && table[x + 1][y] == v) DFS(table, x + 1, y, v);
    if (y - 1 >= 0     && table[x][y - 1] == v) DFS(table, x, y - 1, v);
}