#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("avx,avx2")

#define ll long long

using namespace std;

ll i64a[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

ll modpow(ll n, ll p, ll m) {
    __int128_t _n = n, _m = m, r = 1;
    
    while (p) {
        if (p & 1) r = ((r % _m) * (_n % _m)) % _m; 
        
        _n = ((_n % _m) * (_n % _m)) % _m;
        
        p >>= 1;
    }
    
    return r;
}

bool miller_rabin(ll n, ll a) {
    if (a % n == 0) return true;
    
    ll d = n - 1;
    
    while (true) {
        ll t = modpow(a, d, n);
        if (t == n - 1) return true;
        if (d % 2 == 1) return t == 1 || t == n - 1;
        d >>= 1;
    }
}

bool isprime(ll n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (auto a : i64a) {
        if (n == a) return true;
        if (n % a == 0) return false;
        if (!miller_rabin(n, a)) return false;
    }
    
    return true;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    ll a, b; cin >> a >> b;
    if (a % 2 == 0) a++;

    for (ll i = a; i <= b; i += 2) {
        if (i == 9 || isprime(i)) cout << i << " ";
    }
}