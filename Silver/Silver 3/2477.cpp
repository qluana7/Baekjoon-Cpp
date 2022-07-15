#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int main() {
    int n; cin >> n;
    vector<pii> v(6);
    
    for (auto& x : v) cin >> x.first >> x.second;
    
    for (int i = 0; i < 6; i++) {
        auto a = v[i], b = v[(i + 1) % 6],
             c = v[(i + 2) % 6], d = v[(i + 3) % 6];
        
        if (a.first == c.first && b.first == d.first) {
            int t1 = a.second + c.second,
                t2 = b.second + d.second,
                t3 = b.second * c.second;
            
            cout << (t1 * t2 - t3) * n;
            
            return 0;
        }
    }
    
    return 0;
}