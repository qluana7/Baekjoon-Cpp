#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define u64 unsigned long long

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v(n);
    for (auto& [a, b] : v) cin >> a >> b;
    vector<int> bp(m);
    for (auto& x : bp) cin >> x;

    sort(v.begin(), v.end());
    sort(bp.begin(), bp.end());

    priority_queue<int> pq;

    int p = 0;
    u64 s = 0;

    for (auto x : bp) {
        for (; p < v.size() && v[p].first <= x; p++)
            pq.push(v[p].second);
        
        if (pq.empty()) continue;
        
        s += pq.top(); pq.pop();
    }

    cout << s;
}