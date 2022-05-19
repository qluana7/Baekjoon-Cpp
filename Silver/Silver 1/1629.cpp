#include <iostream>

#define ll long long

using namespace std;

ll a, b, c;

ll dnc(ll div) {
    if (div == 1) return a;
    
    ll d = dnc(div / 2) % c;
    
    if (div % 2 == 0) return d * d % c;
    else return (d * d % c) * a % c;
}

int main() {
    cin >> a >> b >> c; a %= c;
    
    cout << dnc(b);
    
    return 0;
}