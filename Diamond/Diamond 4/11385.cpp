#include <iostream>
#include <vector>

#define _w 5LL
#define mod_p 4603910272195756033LL

using namespace std;

#ifndef ll
#define ll __int128_t
#endif

ll npow(ll a, ll b) {
    ll r = 1;

    while (b) {
        if (b & 1) r = (r * a) % mod_p;
        a = (a * a) % mod_p;
        b = b >> 1;
    }

    return r;
}

void FFT(vector<ll>& v, bool inv = false) {
    int n = v.size();
    
    for (int i = 1, j = 0; i < n; i++) {
        int b = n >> 1;
        while (!((j ^= b) & b)) b >>= 1;
        if (i < j) swap(v[i], v[j]);
    }
    
    ll x = npow(_w, (mod_p - 1) / n);
    if (inv) x = npow(x, mod_p - 2);

    vector<ll> root(n >> 1); root[0] = 1;

    for (int i = 1; i < (n >> 1); i++)
        root[i] = (root[i - 1] * x) % mod_p;
    
    for (int i = 2; i <= n; i <<= 1) {
        ll c = n / i;

        for (int j = 0; j < n; j += i) {
            for (int k = 0, k_len = i >> 1; k < k_len; k++) {
                ll a = v[j | k], b = (v[j | k | k_len] * root[c * k]) % mod_p;

                v[j | k] = (a + b) % mod_p;
                v[j | k | k_len] = (a - b) % mod_p;
                if (v[j | k | k_len] < 0) v[j | k | k_len] += mod_p;
            }
        }
    }

    if (inv) {
        ll t = npow(n, mod_p - 2);

        for (int i = 0; i < n; i++)
            v[i] = (v[i] * t) % mod_p;
    }
}

template<typename T>
void convolution(vector<T>& v1, vector<T>& v2) {
    int s = 2;
    while (s < v1.size() + v2.size()) s <<= 1;
    
    v1.resize(s); FFT(v1, false);
    v2.resize(s); FFT(v2, false);
    
    for (int i = 0; i < s; i++)
        v1[i] = (v1[i] * v2[i]) % mod_p;
        
    FFT(v1, true);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<ll> p1(n + 1), p2(m + 1);

    for (auto& x : p1) { long long _x; cin >> _x; x = _x; }
    for (auto& x : p2) { long long _x; cin >> _x; x = _x; }

    convolution(p1, p2);

    long long t = 0;
    
    for (auto& x : p1) t ^= (long long)x;

    cout << t;
}

/* Undef */
#undef _w
#undef mod_p
/* ----- */

// Another Solution

// Using NTT with 998244353 and 2281701377,
//                 and CRT to restore coefficients
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

#define i64 long long
#define u64 unsigned long long

u64 mulmodu(u64 a, u64 b, u64 m) {
    i64 r = a * b - m * (u64)(1.L / m * a * b);
    return r + m * (r < 0) - m * (r >= (i64)m);
}

i64 mulmod(i64 a, i64 b, i64 m)
{ return a * b % m; }

u64 powmodu(u64 a, u64 b, u64 m) {
    u64 r = 1;

    while (b) {
        if (b & 1) r = mulmodu(r, a, m);
        a = mulmodu(a, a, m);
        b >>= 1;
    }

    return r;
}

i64 powmod(i64 a, i64 b, i64 m) {
    i64 r = 1;

    while (b) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return r;
}

u64 invmodu(u64 a, u64 m) {
    return powmodu(a, m - 2, m);
}

i64 invmod(i64 a, i64 m) {
    return powmod(a, m - 2, m);
}

template<i64 _w = 3LL, i64 mod_p = 998244353LL>
void FFT(vector<i64>& v, bool inv = false) {
    int n = v.size();
    
    for (int i = 1, j = 0; i < n; i++) {
        int b = n >> 1;
        while (!((j ^= b) & b)) b >>= 1;
        if (i < j) swap(v[i], v[j]);
    }
    
    i64 x = powmod(_w, (mod_p - 1) / n, mod_p);
    if (inv) x = invmod(x, mod_p);

    vector<i64> root(n >> 1); root[0] = 1;

    for (int i = 1; i < (n >> 1); i++)
        root[i] = mulmod(root[i - 1], x, mod_p);
    
    for (int i = 2; i <= n; i <<= 1) {
        i64 c = n / i;

        for (int j = 0; j < n; j += i) {
            for (int k = 0, k_len = i >> 1; k < k_len; k++) {
                i64 a = v[j | k], b = mulmod(v[j | k | k_len], root[c * k], mod_p);

                v[j | k] = (a + b) % mod_p;
                v[j | k | k_len] = (a - b) % mod_p;
                if (v[j | k | k_len] < 0) v[j | k | k_len] += mod_p;
            }
        }
    }

    if (inv) {
        i64 t = invmod(n, mod_p);

        for (int i = 0; i < n; i++)
            v[i] = mulmod(v[i], t, mod_p);
    }
}

template<i64 _w = 3LL, i64 mod_p = 998244353LL>
vector<i64> convolution(const vector<i64>& __v1, const vector<i64>& __v2) {
    vector<i64> v1(__v1), v2(__v2);
    int s = 2;
    while (s < v1.size() + v2.size()) s <<= 1;
    
    v1.resize(s); FFT<_w, mod_p>(v1, false);
    v2.resize(s); FFT<_w, mod_p>(v2, false);
    
    for (int i = 0; i < s; i++)
        v1[i] = mulmod(v1[i], v2[i], mod_p);
        
    FFT<_w, mod_p>(v1, true);

    return v1;
}

u64 crt(u64 a1, u64 m1, u64 a2, u64 m2) {
    u64 m = m1 * m2;
    
    return (
        mulmodu(m2, mulmodu(a1, invmodu(m2, m1), m), m) +
        mulmodu(m1, mulmodu(a2, invmodu(m1, m2), m), m)
    ) % m;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<i64> p1(n + 1), p2(m + 1);

    for (auto& x : p1) { i64 _x; cin >> _x; x = _x; }
    for (auto& x : p2) { i64 _x; cin >> _x; x = _x; }

    vector<i64>
        r1 = convolution<3LL, 998244353LL>(p1, p2),
        r2 = convolution<3LL, 2281701377LL>(p1, p2);

    i64 t = 0;
    
    for (int i = 0; i < r1.size(); i++) {
        t ^= crt(r1[i], 998244353LL, r2[i], 2281701377LL);
    }

    cout << t;
}