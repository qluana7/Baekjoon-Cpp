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
 */

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