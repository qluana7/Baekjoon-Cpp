#include <iostream>

using namespace std;

int main() {
    int x, y, z; cin >> x >> y >> z;
    if (y > x && y > z) swap(x, y);
    if (z > x && z > y) swap(x, z);
    if (y < z) swap(y, z);
    
    y += z;
    if (y <= x) cout << 2*y-1;
    else cout << y+x;
    
    return 0;
}