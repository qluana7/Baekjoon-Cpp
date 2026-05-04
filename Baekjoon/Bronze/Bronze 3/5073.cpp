#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int x, y, z;
    
    while (cin >> x >> y >> z, x) {
        if (y > x && y > z) swap(x, y);
        if (z > x && z > y) swap(x, z);
        if (y < z) swap(y, z);
        
        if (y + z <= x) cout << "Invalid\n";
        else {
            if (x == y && y == z) cout << "Equilateral\n";
            else if (x == y || y == z || x == z) cout << "Isosceles\n";
            else cout << "Scalene\n";
        }
    }
    
    return 0;
}