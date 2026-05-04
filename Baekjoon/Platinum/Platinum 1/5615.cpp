#include <iostream>

#define ull unsigned long long

using namespace std;

ull i64a[] = { 2, 7, 61 };

ull modpow(ull n, ull p, ull m) {
    ull r = 1;
    
    while (p) {
        if (p & 1) r = ((r % m) * (n % m)) % m; 
        
        n = ((n % m) * (n % m)) % m;
        
        p >>= 1;
    }
    
    return r;
}

bool miller_rabin(ull n, ull a) {
    if (a % n == 0) return true;
    
    ull d = n - 1;
    
    while (true) {
        ull t = modpow(a, d, n);
        if (t == n - 1) return true;
        if (d % 2 == 1) return t == 1 || t == n - 1;
        d >>= 1;
    }
}

bool isprime(ull n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (auto a : i64a) {
        if (n == a) return true;
        if (!miller_rabin(n, a)) return false;
    }
    
    return true;
}

int main() {
    int n, cnt = 0; cin >> n;
    
    for (int i = 0; i < n; i++) {
        ull x; cin >> x;
        
        if (isprime(2*x + 1)) cnt++;
    }
    
    cout << cnt;
}