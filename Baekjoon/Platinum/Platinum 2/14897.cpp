#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Query {
    int index, l, r;
};

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m, k, mx = 0; cin >> n; k = sqrt(n);
    vector<int> v(n), t(n);
    for (int i = 0; i < n; i++) { cin >> v[i]; t[i] = v[i]; }
    
    sort(t.begin(), t.end());
    auto iter = unique(t.begin(), t.end());
    t.erase(iter, t.end());
    mx = t.size();
    for (int i = 0; i < n; i++) { v[i] = distance(t.begin(), lower_bound(t.begin(), t.end(), v[i])) + 1; }
    
    cin >> m;
    vector<Query> query(m);
    for (int i = 0; i < m; i++) { cin >> query[i].l >> query[i].r; query[i].index = i; }
    
    sort(query.begin(), query.end(), [k](const Query& a, const Query& b) {
        int l1 = a.l / k, l2 = b.l / k;
        if (l1 != l2) return l1 < l2;
        else return a.r < b.r;
    });
    
    vector<int> output(m);
    int l = query[0].l, r = query[0].r;
    vector<int> b(mx);
    int sum = 0;
    for (int i = l; i <= r; i++) {
        auto x = v[i - 1] - 1;
        sum += !b[x];
        b[x]++;
    }
    output[query[0].index] = sum;
    
    for (int i = 1; i < query.size(); i++) {
        auto _l = query[i].l, _r = query[i].r;
        
        while (_l < l) { l--; auto x = v[l - 1] - 1; sum += b[x] == 0; b[x]++; }
        while (_r > r) { r++; auto x = v[r - 1] - 1; sum += b[x] == 0; b[x]++; }
        while (_l > l) { auto x = v[l - 1] - 1; b[x]--; sum -= b[x] == 0; l++; }
        while (_r < r) { auto x = v[r - 1] - 1; b[x]--; sum -= b[x] == 0; r--; }
        
        output[query[i].index] = sum;
    }
    
    for (auto x : output) cout << x << "\n";
}