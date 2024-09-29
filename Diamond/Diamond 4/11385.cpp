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