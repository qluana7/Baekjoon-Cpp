#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <cmath>

#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("avx,avx2")

#define ll long long

using namespace std;

random_device rd;
mt19937 engine(rd());
uniform_int_distribution<int> rnd(1, 9);

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
        if (!miller_rabin(n, a)) return false;
    }
    
    return true;
}

inline ll g(__int128_t x, __int128_t n, __int128_t r) { return (((x % n) * (x % n)) % n + r) % n; }

ll pollard_rho(ll n) {
    if (isprime(n)) return n;
    if (n == 1) return 1;
    if (n % 2 == 0) return 2;
    
    ll x = rnd(engine), y = x, d = 1, r = rnd(engine);
    
    while (d == 1) {
        x = g(x, n, r);
        y = g(g(y, n, r), n, r);
        d = gcd(abs(x - y), n);
        
        if (d == n) return pollard_rho(n);
    }
    
    return pollard_rho(d);
}

bool is3(ll x) {
    while (x % 4 == 0) x /= 4;
    if (x % 8 == 7) return false;

    return true;
}

bool is2(ll n) {
    vector<ll> v;

    if (isprime(n) && n % 4 == 1) return true;
    
    while (n > 1) {
        ll t = pollard_rho(n);
        
        v.push_back(t);
        n /= t;
    }

    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++) {
        int c = 0, t = -1;
        if (v[i] % 4 == 3) {
            t = v[i]; c++;
            while (i + 1 < v.size() && v[i + 1] == t) i++, c++;

            if (c % 2 == 1) return false;
        }
    }

    return true;
}

bool is1(ll n) {
    ll x = sqrt(n);

    return x * x == n;
}

int main() {
    ll x; cin >> x;

    cout << (is1(x) ? '1' : is2(x) ? '2' : is3(x) ? '3' : '4');
}