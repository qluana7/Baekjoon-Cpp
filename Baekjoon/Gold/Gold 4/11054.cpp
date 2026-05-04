#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

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
    
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    
    // { 증가, 감소 }
    array<vector<int>, 2> table = { vector<int>(n), vector<int>(n) };
    
    for (int i = 0; i < n; i++) {
        table[0][i] = table[1][i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[i] == v[j]) continue;
            else if (v[i] < v[j]) {
                table[1][i] = max({ table[1][i], table[1][j] + 1, table[0][i], table[0][j] + 1 });
            } else {
                table[0][i] = max(table[0][i], table[0][j] + 1);
            }
        }
    }
    
    int mx = 0;
    for (const auto& vx : table)
        for (auto x : vx) mx = max(mx, x);
    
    cout << mx;
}