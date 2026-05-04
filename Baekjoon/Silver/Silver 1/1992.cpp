#include <iostream>

using namespace std;

int _size;
int table[64][64];

void dnc(int, int, int);

int main() {
    cin >> _size;
    
    for (int i = 0; i < _size; i++) {
        getchar();
        for (int j = 0; j < _size; j++) {
            char c = getchar();
            table[i][j] = c == '1';
        }
    }
    
    dnc(0, 0, _size);
    
    return 0;
}

void dnc(int x, int y, int sz) {
    int tmp = table[x][y]; bool t = true;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (table[x + i][y + j] != tmp) { t = false; break; }
        }
        
        if (!t) break;
    }
    
    if (t) { cout << tmp; return; }
    
    cout << "(";
    
    int dz = sz / 2;
    dnc(x, y, dz);
    dnc(x, y + dz, dz);
    dnc(x + dz, y, dz);
    dnc(x + dz, y + dz, dz);
    
    cout << ")";
}