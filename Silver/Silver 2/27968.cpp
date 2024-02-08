#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, m; cin >> m >> n;
    vector<long long> v(n); cin >> v[0];
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    
    for (int i = 0; i < m; i++) {
        long long x; cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x);
        
        cout << (it == v.end() ? "Go away!" : to_string(distance(v.begin(), it) + 1)) << "\n";
    }
}