#include <iostream>

#define ull unsigned long long

using namespace std;

int main() {
    ull a, b, c, t1, t2;
    cin >> a >> b >> c;
    
    cout << ((t1 = a * b / c) > (t2 = ((double)a / b) * c) ? t1 : t2);
    
    return 0;
}