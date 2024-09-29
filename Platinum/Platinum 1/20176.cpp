#include <iostream>
#include <vector>
#include <complex>

using namespace std;

using cpx = complex<double>;
const double pi = 3.14159265358979323846;
const int MAX_SIZE = 60001;
const int BASE = 30000;

void FFT(vector<cpx>& v, bool inv = false) {
    int n = v.size();
    
    for (int i = 1, j = 0; i < n; i++) {
        int b = n >> 1;
        while (!((j ^= b) & b)) b >>= 1;
        if (i < j) swap(v[i], v[j]);
    }
    
    for (int i = 1; i < n; i <<= 1) {
        double x = -pi / i * (inv ? 1 : -1);

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

void multiply(vector<cpx>& v1, vector<cpx>& v2) {
    int len = v1.size() + v2.size() - 1;
    int s = 2;
    while (s < v1.size() + v2.size()) s <<= 1;
    
    v1.resize(s); FFT(v1, false);
    v2.resize(s); FFT(v2, false);
    
    for (int i = 0; i < s; i++)
        v1[i] *= v2[i];
        
    FFT(v1, true);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int mx, n;
    vector<cpx> v1(MAX_SIZE), v2(MAX_SIZE);
    vector<int> v;
    cin >> n; mx = n;
    while (n --> 0) { int x; cin >> x; v1[x + BASE] = 1; }
    cin >> n;
    while (n --> 0) { int x; cin >> x; v.push_back(x + BASE); }
    cin >> n; mx = max(mx, n);
    while (n --> 0) { int x; cin >> x; v2[x + BASE] = 1; }

    multiply(v1, v2);

    int t = 0;
    for (auto x : v) t += (int)round(v1[x * 2].real());

    cout << t;
}