#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> v(n);
    
    for (int& x : v) cin >> x;
    
    int x = 0, y = 0, t = v[0], mn = n + 1;
    
    while (true) {
        if (y >= v.size()) break;
        if (t < m) {
            y++; t += v[y];
        } else {
            while (t - v[x] >= m) t -= v[x++];
            
            mn = min(mn, y - x + 1);
            y++; t += v[y];
        }
    }
    
    cout << (mn == n + 1 ? 0 : mn);
    
    return 0;
}