#include <iostream>

using namespace std;

void solve(int(*)[128], int, int, int);
int getNum(int(*)[128], int, int, int);

int ns[2];

int main() {
    int n; cin >> n;
    int table[n][128];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }
    
    solve(table, n, 0, 0);
    
    cout << ns[0] << endl << ns[1];
    
    return 0;
}

void solve(int table[][128], int size, int x, int y) {
    int n = getNum(table, size, x, y);
    
    if (n == -1) {
        int t = size / 2;
        
        solve(table, t, x, y);
        solve(table, t, x + t, y);
        solve(table, t, x, y + t);
        solve(table, t, x + t, y + t);
    }
    else {
        ns[n]++;
    }
}

int getNum(int table[][128], int size, int x, int y) {
    int comp = table[x][y];
    
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (table[i][j] != comp) return -1;
        }
    }
    
    return comp;
}