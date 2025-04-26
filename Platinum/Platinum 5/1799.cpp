#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

#define pii pair<int, int>

vector<vector<int>> v;
int bmx = 0, wmx = 0, b = 0;

// > x | V y
void bt(vector<int>& lf, vector<int>& rg, int x, int y, int n, int d) {
    int p = x - y + n - 1, q = x + y;
    
    if (x >= n) { y++; x = !(x % 2); }
    if (y >= n) { if (b == 0) bmx = max(bmx, d); else wmx = max(wmx, d); return; }
    
    p = x - y + n - 1; q = x + y;
    
    if (v[y][x] == 1 && lf[p] == 0 && rg[q] == 0) {
        lf[p] = 1;
        rg[q] = 1;
        
        bt(lf, rg, x + 2, y, n, d + 1);
        
        lf[p] = 0;
        rg[q] = 0;
    }
    bt(lf, rg, x + 2, y, n, d);
}

int main() {
    int n; cin >> n;
    v = vector<vector<int>>(n, vector<int>(n));
    vector<int> lf(20, 0), rg(20, 0);
    
    for (auto& vx : v) for (auto& x : vx) cin >> x;
    
    bt(lf, rg, 0, 0, n, 0);
    b = 1;
    bt(lf, rg, 1, 0, n, 0);
    
    cout << bmx + wmx;
}