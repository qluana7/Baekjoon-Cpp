#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <queue>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

std::array<i64, (int)3e5+1> found;

void solve(const vector<i64>& v, int n) {
    found.fill(-1);
    
    queue<pair<i64, i64>> q;
    
    q.push({ 1, 0 });
    
    while (!q.empty()) {
        auto [top, dep] = q.front(); q.pop();
        
        if (found[top] != -1) continue;
        
        found[top] = dep;
        
        for (auto x : v) {
            i64 p = top * x;
            
            if (p > n) break;
            
            if (found[p] == -1)
                q.push({ p, dep + 1 });
        }
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    
    while (t --> 0) {
        int n; cin >> n;
        
        bool flag = false;
        vector<i64> v; v.reserve(n);
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            
            if (k == 1) flag = true;
            else v.push_back(k);
        }
        
        ranges::sort(v);
        auto [b, e] = ranges::unique(v);
        v.erase(b, e);
        
        solve(v, n);
        
        found[1] = flag ? 1 : -1;
        
        for (auto x : found | views::drop(1) | views::take(n))
            cout << x << " ";
        cout << "\n";
    }
}