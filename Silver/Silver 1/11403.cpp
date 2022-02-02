#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int table[100][100];
int visit[100];
int _size;

bool DFS(int, int);

int main() {
    cin >> _size;
    
    for (int i = 0; i < _size; i++) { 
        for (int j = 0; j < _size; j++) {
            char x; cin >> x;
            table[i][j] = x == '1';
        }
    }
    
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            memset(visit, 0, sizeof(visit));
            
            if (i == j) {
                bool b = false;
                for (int k = 0; k < _size; k++) {
                    if (!table[i][k]) continue;
                    
                    memset(visit, 0, sizeof(visit));
                    visit[k] = 1;
                    b = DFS(k, i);
                    
                    if (b) { cout << "1 "; break; }
                }
                
                if (!b) cout << "0 ";
                continue;
            }
            
            cout << (DFS(i, j) ? 1 : 0) << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}

bool DFS(int st, int en) {
    if (st == en) return true;
    visit[st] = 1;
    
    for (int i = 0; i < _size; i++) {
        if (visit[i] || !table[st][i]) continue;
        
        bool b = DFS(i, en);
        if (b) return true;
    }
    
    return false;
}