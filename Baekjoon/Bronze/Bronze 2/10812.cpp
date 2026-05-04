#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    
    for (int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> z >> y;
        vector<int> t(y - x);
        copy(v.begin() + (x - 1), v.begin() + (y - 1), t.begin());
        int j = x - 1;
        for (int k = y - 1; k < z; j++, k++) swap(v[j], v[k]);
        for (int k = 0; k < t.size(); k++, j++) v[j] = t[k];
    }
    
    for (int x : v) cout << x << " ";
    
    return 0;
}