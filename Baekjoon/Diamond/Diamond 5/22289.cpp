#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

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

int main() {
    string s1, s2; cin >> s1 >> s2;
    vector<cpx> v1(s1.size(), 0), v2(s2.size(), 0);

    for (int i = 0; i < v1.size(); i++) v1[i] = s1[i] - 48;
    for (int i = 0; i < v2.size(); i++) v2[i] = s2[i] - 48;

    int len = v1.size() + v2.size() - 1;
    int s = 2;
    while (s < v1.size() + v2.size()) s <<= 1;

    v1.resize(s); FFT(v1, false);
    v2.resize(s); FFT(v2, false);

    for (int i = 0; i < s; i++)
        v1[i] *= v2[i];

    FFT(v1, true);

    vector<int> result;
    for (const auto& p : v1) result.push_back((int)round(p.real()));
    result.resize(len);

    int r = 0;
    for (int i = len - 1; i > 0; i--) {
        result[i - 1] += result[i] / 10;
        result[i] %= 10;
    }
    
    for (auto i : result) cout << i;

    return 0;
}