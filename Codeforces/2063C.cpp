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

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    
    while (t --> 0) {
        int n; cin >> n;
        vector<unordered_set<int>> edges(n);
        vector<pair<int, int>> tb(n);
        vector<map<int, int, greater<int>>> tb2(n);
        
        for (int i = 0; i < n; i++)
            tb[i] = { i, 0 };
        
        for (int i = n; i --> 1;) {
            int a, b; cin >> a >> b;
            edges[a - 1].insert(b - 1);
            edges[b - 1].insert(a - 1);
            
            tb[a - 1].second++;
            tb[b - 1].second++;
        }
        
        for (int i = 0; i < n; i++) {
            for (auto x : edges[i])
                tb2[i][tb[x].second]++;
        }
         
        ranges::sort(tb, [&tb2] (const auto& p1, const auto& p2) {
            if (p1.second == p2.second) {
                auto p1b = tb2[p1.first].begin(), p1e = tb2[p1.first].end();
                auto p2b = tb2[p2.first].begin(), p2e = tb2[p2.first].end();
                
                while (true) {
                    if (p1b == p1e || p2b == p2e) {
                        if (p1b == p1e && p2b == p2e)
                            return false;
                        else return p1b == p1e;
                    }
                    
                    if (p1b->first != p2b->first)
                        return p1b->first > p2b->first;
                    
                    if (p1b->second != p2b->second)
                        return p1b->second < p2b->second;
                    
                    p1b++; p2b++;
                }
            } else return p1.second > p2.second;
        });
        
        auto [idx, k] = tb.front();
        
        ranges::sort(tb, [] (const auto& p1, const auto& p2) {
            return p1.first < p2.first;
        });
        
        for (auto x : edges[idx]) {
            tb[x].second--;
        }
        
        ranges::sort(tb, [] (const auto& p1, const auto& p2) {
            return p1.second > p2.second;
        });
        
        cout << k + tb[1].second - 1 << "\n";
    }
}