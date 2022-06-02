#include <iostream>
#include <vector>
#include <numeric>

#define ll long long
#define MOD 1'000'000'007

using namespace std;

struct matrix2x2 {
    ll dat[2][2] = { 0, };
    
    matrix2x2 operator* (const matrix2x2& m) const {
        return { {
            {
                ((dat[0][0] * m.dat[0][0]) % MOD + (dat[0][1] * m.dat[1][0]) % MOD) % MOD,
                ((dat[0][0] * m.dat[1][0]) % MOD + (dat[0][1] * m.dat[1][1]) % MOD) % MOD
            },
            {
                ((dat[1][0] * m.dat[0][0]) % MOD + (dat[1][1] * m.dat[1][0]) % MOD) % MOD,
                ((dat[1][0] * m.dat[1][0]) % MOD + (dat[1][1] * m.dat[1][1]) % MOD) % MOD
            }
        } };
    }
};

matrix2x2 dnc(const matrix2x2& m, ll div) {
    if (div == 0) return { { { 0, 0 }, { 0, 0 } } };
    if (div == 1) return m;
    
    matrix2x2 d = dnc(m, div / 2);
    
    if (div % 2 == 0) return d * d;
    else return d * d * m;
}

int main() {
    ll dv; cin >> dv;
    
    matrix2x2 mat { { { 1, 1 }, { 1, 0 } } };
    
    matrix2x2 mt = dnc(mat, (dv - dv % 2) + 1);
            
    cout << mt.dat[0][1] - 1;
    
    return 0;
}