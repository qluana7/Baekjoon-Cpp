#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    
    vector<pair<int, int>> v(n);
    for (auto& x : v) cin >> x.first >> x.second;
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= m; w++) {
            a[i][w] = (v[i - 1].first > w) ?
                a[i - 1][w] :
                max(v[i - 1].second + a[i - 1][w - v[i - 1].first], a[i - 1][w]);
        }
    }
    
    cout << a[n][m];
    
    return 0;
}