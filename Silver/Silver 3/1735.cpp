#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    
    x1 *= y2; x2 *= y1; y1 *= y2; x1 += x2;
    y2 = gcd(y1, x1);
    
    cout << x1 / y2 << " " << y1 / y2;
    
    return 0;
}