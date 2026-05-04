#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
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
    vector<pair<int, int>> pv(n);
    for (auto& [a, b] : pv) cin >> a >> b;
    
    int m; cin >> m;
    vector<string> v(m);
    map<int, vector<string>> mp;
    
    for (auto& s : v) {
        cin >> s;
        mp[s.size()].push_back(s);
    }
    
    vector<set<char>> st(n);
    for (int i = 0; i < n; i++) {
        auto [a, b] = pv[i];
        
        for (const auto& s : mp[a]) st[i].insert(s[b - 1]);
    }
    
    for (const auto& s : v) {
        if (s.size() != n) {
            cout << "No\n"; continue;
        }
        
        bool flag = false;
        for (int i = 0; i < n; i++)
            flag |= !st[i].contains(s[i]);
        
        cout << (flag ? "No" : "Yes") << "\n";
    }
}