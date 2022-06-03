#include <iostream>
#include <cstring>

#define ll long long

using namespace std;

int main() {
    ll a, b; cin >> a >> b;
    bool flag[b - a + 1]; memset(flag, 0, sizeof(flag));
    
    for (ll i = 2; i * i <= b; i++) {
        for (ll x = a / (i * i) + !!(a % (i * i)); x * i * i <= b; x++)
            flag[x * i * i - a] = true;
    }
    
    ll t = 0;
    
    for (bool b : flag) t += !b;
    
    cout << t;
    
    return 0;
}