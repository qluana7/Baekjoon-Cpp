#include <iostream>
#include <vector>

#define maxt(a, b, c) max(max((a), (b)), (c))
#define mint(a, b, c) min(min((a), (b)), (c))

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> mxv(3, 0);
    vector<int> mnv(3, 0);
    
    for (;n--;) {
        int a, b, c; cin >> a >> b >> c;
        
        int
            txa = max(mxv[0] + a, mxv[1] + a),
            txb = maxt(mxv[0] + b, mxv[1] + b, mxv[2] + b),
            txc = max(mxv[1] + c, mxv[2] + c),
            tna = min(mnv[0] + a, mnv[1] + a),
            tnb = mint(mnv[0] + b, mnv[1] + b, mnv[2] + b),
            tnc = min(mnv[1] + c, mnv[2] + c);
        
        mxv[0] = txa; mxv[1] = txb; mxv[2] = txc;
        mnv[0] = tna; mnv[1] = tnb; mnv[2] = tnc;
    }
    
    cout << maxt(mxv[0], mxv[1], mxv[2]) << " " << mint(mnv[0], mnv[1], mnv[2]);
    
    return 0;
}