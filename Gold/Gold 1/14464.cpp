#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;

struct comp {
    bool operator() (const pair<u64, u64>& a, const pair<u64, u64>& b) const {
        if (a.second != b.second) return a.second > b.second;
        else return a.first > b.first;
    }
};

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<u64> v1(n);
    for (auto& x : v1) cin >> x;
    vector<pair<u64, u64>> v2(m);
    for (auto& [a, b] : v2) cin >> a >> b;
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    priority_queue<pair<u64, u64>, vector<pair<u64, u64>>, comp> pq;
    
    int idx = 0, cnt = 0;
    for (auto x : v1) {
        while (idx < v2.size() && v2[idx].first <= x) pq.push(v2[idx]), idx++;
        while (!pq.empty() && pq.top().second < x) pq.pop();
        
        if (!pq.empty()) pq.pop(), cnt++;
    }
    
    cout << cnt;
}