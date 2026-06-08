#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <unordered_set>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    
    vector<pair<int, int>> v(n - 1);
    for (auto& [a, b] : v) cin >> a >> b;
    
    vector<int> colors(n);
    for (auto& x : colors) cin >> x;
    
    vector<int> k(n, 0);
    
    int conflict = 0;
    
    for (auto [a, b] : v) {
        if (colors[a - 1] != colors[b - 1]) {
            k[a - 1]++; k[b - 1]++;
            conflict++;
        }
    }
    
    auto mxp = max_element(k.begin(), k.end());
    int mx = distance(k.begin(), mxp);
    
    if (*mxp == conflict) {
        cout << "YES\n" << mx + 1;
    } else cout << "NO";
}