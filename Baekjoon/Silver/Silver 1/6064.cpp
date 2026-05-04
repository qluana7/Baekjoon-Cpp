#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int c; cin >> c;
    
    for (;c--;) {
        int a, b, x, y; cin >> a >> b >> x >> y;
        int n = x; int m = lcm(a, b);
        
        while ((n % b ? n % b : b) != y) {
            n += a;
            if (n > m) break;
        }
        
        
        cout << (n > m ? -1 : n) << "\n";
    }
    
    return 0;
}