#include <iostream>
#include <vector>
#include <complex>

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
    
    vector<cpx> zb; zb.resize(200001);
    vector<int> np; np.resize(200001);
    int c = 0;
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        
        zb[t] = 1; np[t] = 1;
    }
    
    vector<cpx> zb2(zb);
    multiply(zb, zb2);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        
        if (np[t] > 0 || (int)round(zb[t].real()) > 0) c++;
    }
    
    cout << c;
    
    return 0;
}