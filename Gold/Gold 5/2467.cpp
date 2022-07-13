#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    
    for (int& x : v) cin >> x;
    
    sort(v.begin(), v.end());
    
    int mn = INT32_MAX, n1 = 0, n2 = 0, x = 0, y = v.size() - 1;
    
    while (x < y) {
        int p = v[x] + v[y];
        
        if (mn > abs(p)) {
            mn = abs(p); n1 = v[x]; n2 = v[y];
        }
        
        if (p < 0) x++;
        else y--;
    }
    
    cout << n1 << " " << n2;
    
    return 0;
}