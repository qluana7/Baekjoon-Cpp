#include <iostream>
#include <algorithm>
#include <vector>

#define mn(a, b) ((a)<(b)?(a):(b))
#define min(a, b, c) mn(mn(a, b), c)

using namespace std;

int main() {
    int x, y, z; cin >> x >> y >> z;
    int n = min(x, y, z);
    
    int tot = 0;
    
    vector<int> vx, vy, vz;
    
    for (;x--;) { int t; cin >> t; vx.push_back(t); tot += t; }
    for (;y--;) { int t; cin >> t; vy.push_back(t); tot += t; }
    for (;z--;) { int t; cin >> t; vz.push_back(t); tot += t; }
    sort(vx.begin(), vx.end(), greater<int>());
    sort(vy.begin(), vy.end(), greater<int>());
    sort(vz.begin(), vz.end(), greater<int>());
    
    cout << tot << "\n";
    
    for (int i = 0; i < n; i++)
        tot -= vx[i] / 10 + vy[i] / 10 + vz[i] / 10;
    
    cout << tot;
    
    return 0;
}