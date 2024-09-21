/*
 * Algorithm Name : Fast Fourier Transform
 *
 * Description
 *    - 빠른 푸리에 변환 구현
 *    - FFT에 들어가는 배열의 크기는 항상 2^n 이여야 함
 * 
 * Reference
 *    - https://restudycafe.tistory.com/563
 *    - https://tistory.joonhyung.xyz/6
 * 
 *      NTT Implementation Reference
 *    - https://blog.naver.com/yyhjin12/223044578555
 *    - https://algoshitpo.github.io/2020/05/20/fft-ntt/
 */

#include <vector>
#include <complex>
#include <cmath>

using namespace std;

using cpx = complex<double>;
const double pi = 3.14159265358979323846;

void FFT(vector<cpx>& v, bool inv = false) {
    int n = v.size();
    
    for (int i = 1, j = 0; i < n; i++) {
        int b = n >> 1;
        while (!((j ^= b) & b)) b >>= 1;
        if (i < j) swap(v[i], v[j]);
    }
    
    for (int i = 1; i < n; i <<= 1) {
        double x = pi / i * (inv ? 1 : -1);

        cpx w = cpx(cos(x), sin(x));

        for (int j = 0; j < n; j += i << 1) {
            cpx t = cpx(1, 0);

            for (int k = 0; k < i; k++) {
                cpx tp = v[i + j + k] * t;
                v[i + j + k] = v[j + k] - tp;
                v[j + k] += tp;
                t *= w;
            }
        }
    }

    if (inv) for (int i = 0; i < n; i++) v[i] /= n;
}

/* Implementation of NTT */

#include <vector>

#define _w 3LL
#define mod_p 998244353LL

using namespace std;

using ll = long long int;

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
        int t = npow(n, mod_p - 2);

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