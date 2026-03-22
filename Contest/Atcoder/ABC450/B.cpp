#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <atcoder/all>

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
    vector<vector<u64>> v(n - 1, vector<u64>(n));
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cin >> v[i][j + i + 1];
        }
    }
    
    n = v.size() + 1;
    
    for (int a = 0; a < n - 2; a++) {
        for (int b = a + 1; b < n - 1; b++) {
            for (int c = b + 1; c < n; c++) {
                if (v[a][b] + v[b][c] < v[a][c])
                    return !(cout << "Yes");
            }
        }
    }
    
    cout << "No";
}