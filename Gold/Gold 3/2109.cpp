#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;

    if (n == 0) return !(cout << 0);

    vector<pair<int, int>> v(n);
    for (auto& [a, b] : v) cin >> b >> a;

    sort(v.begin(), v.end(), greater<pair<int, int>>{});

    int k = v[0].first, i = 0, s = 0;
    priority_queue<int> pq;

    for (; k > 0; k--) {
        for (; i < v.size() && v[i].first == k; i++)
            pq.push(v[i].second);
        
        if (pq.empty()) continue;

        s += pq.top(); pq.pop();
    }

    cout << s;
}