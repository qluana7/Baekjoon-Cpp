#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m; cin >> n; m = round(n * 0.15);
    
    if (n == 0) {
        cout << 0;
        return 0;
    }
    
    vector<int> v(n);
    for (int& x : v) cin >> x;
    
    sort(v.begin(), v.end());
    
    int tot = 0;
    for (int i = m; i < (n - m); i++) {
        tot += v[i];
    }
    
    cout << round(tot / (double)(n - 2 * m));
}