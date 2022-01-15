#include <iostream>

#define uint unsigned int

using namespace std;

int a, b, r = 0;

void z(int x, int y, int size) {
    if (x == a && y == b) { cout << r; return; }
    
    if (a < x + size && a >= x && b < y + size && b >= y) {
        z(x, y, size / 2);
        z(x, y + size / 2, size / 2);
        z(x + size / 2, y, size / 2);
        z(x + size / 2, y + size / 2, size / 2);
    } else r += size * size;
}

int main() {
    uint size; cin >> size >> a >> b;
    
    z(0, 0, 1 << size);
    
    return 0;
}