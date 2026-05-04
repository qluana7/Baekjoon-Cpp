#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

struct Query {
    int index, l, r;
};

int main() {
    int n, m, k, mx; cin >> n; k = sqrt(n);
    vector<int> v(n);
    for (auto& x : v) { cin >> x; mx = max(mx, x); }
    
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