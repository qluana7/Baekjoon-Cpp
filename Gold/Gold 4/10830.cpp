#include <iostream>
#include <vector>

#define ll long long
#define MOD 1000

using namespace std;

struct matrix {
    matrix(int sz) : dat(vector<vector<int>>(sz, vector<int>(sz , 0))), size(sz) {  }
    
    vector<vector<int>> dat;
    int size;
    
    matrix operator* (const matrix& m) const {
        matrix tmp(m.size);
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    tmp.dat[i][j] += ((dat[i][k] % MOD) * (m.dat[k][j] % MOD)) % MOD;
                    tmp.dat[i][j] %= MOD;
                }
            }
        }
        
        return tmp;
    }
};

matrix dnc(const matrix& m, ll div) {
    if (div == 1) return m;
    
    matrix d = dnc(m, div / 2);
    
    if (div % 2 == 0) return d * d;
    else return d * d * m;
}

int main() {
    int s; ll b; cin >> s >> b;
    matrix mat(s);
    
    for (auto& v : mat.dat) for (int& x : v) cin >> x;
    
    matrix mt = dnc(mat, b);
    
    for (const auto& v : mt.dat) {
        for (int x : v) cout << x % MOD << " ";
        cout << "\n";
    }
    
    return 0;
}