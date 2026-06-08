#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

constexpr int INF = 1 << 29;


int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    while (t --> 0) {
        string a, b, k; cin >> a >> b >> k;
        vector<vector<int>> table(a.size() + 1, vector<int>(b.size() + 1));
        
        for (int i = 0; i < b.size(); i++)
            table[0][i + 1] = table[0][i] + (b[i] != k[i]);
        
        for (int i = 0; i < a.size(); i++)
            table[i + 1][0] = table[i][0] + (a[i] != k[i]);
        
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                char c = k[i + j + 1];
                
                table[i + 1][j + 1] = min(
                    table[i][j + 1] + (a[i] != c),
                    table[i + 1][j] + (b[j] != c)
                );
            }
        }
        
        cout << table.back().back() << "\n";
    }
}