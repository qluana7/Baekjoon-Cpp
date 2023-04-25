#include <iostream>

#define int long long
using namespace std;

bool prime(int n) {
    if (n == 2) return true;
    if (n <= 1 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    
    return true;
}

int32_t main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    
    while (n --> 0) {
        int x; cin >> x;
        for (int i = x; ; i++) {
            if (prime(i)) { cout << i << "\n"; break; }
        }
    }
    
    return 0;
}