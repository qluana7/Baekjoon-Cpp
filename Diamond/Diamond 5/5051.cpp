#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("avx,avx2")

#include <iostream>
#include <vector>

using namespace std;

#ifndef ll
#define ll long long
#endif

ll npow(ll a, ll b, ll mod_p) {
    ll r = 1;

    while (b) {
        if (b & 1) r = (r * a) % mod_p;
        a = (a * a) % mod_p;
        b = b >> 1;
    }

    return r;
}

template<ll _w = 3LL, ll mod_p = 998244353LL>
void FFT(vector<ll>& v, bool inv = false) {
    int n = v.size();
    
    for (int i = 1, j = 0; i < n; i++) {
        int b = n >> 1;
        while (!((j ^= b) & b)) b >>= 1;
        if (i < j) swap(v[i], v[j]);
    }
    
    ll x = npow(_w, (mod_p - 1) / n, mod_p);
    if (inv) x = npow(x, mod_p - 2, mod_p);

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
        ll t = npow(n, mod_p - 2, mod_p);

        for (int i = 0; i < n; i++)
            v[i] = (v[i] * t) % mod_p;
    }
}

template<ll _w = 3LL, ll mod_p = 998244353LL>
void convolution(vector<ll>& v1, vector<ll>& v2) {
    int s = 2;
    while (s < v1.size() + v2.size()) s <<= 1;
    
    v1.resize(s); FFT<_w, mod_p>(v1, false);
    v2.resize(s); FFT<_w, mod_p>(v2, false);
    
    for (int i = 0; i < s; i++)
        v1[i] = (v1[i] * v2[i]) % mod_p;
        
    FFT<_w, mod_p>(v1, true);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    ll n; cin >> n;
    vector<ll> p1(n), p2(n);

    for (ll i = 1; i < n; i++) { p1[i * i % n]++; p2[2 * i * i % n]++; }
    vector<ll> z1(p1.begin(), p1.end());

    convolution(z1, p1);

    ll t = 0;
    for (ll i = 1; i < n; i++) {
        ll x = i * i % n;
        t += (z1[x] + z1[n + x] - p2[x]) / 2 + p2[x];
    }

    cout << t;
}