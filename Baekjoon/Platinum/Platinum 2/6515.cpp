#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Query {
    int index, l, r;
};

void solve(int n) {
    int m, k, mx = 0; cin >> m; k = sqrt(n);
    vector<int> v(n);
    for (auto& x : v) { cin >> x; x += 100000; mx = max(mx, x); }
    
    vector<Query> query(m);
    for (int i = 0; i < m; i++) { cin >> query[i].l >> query[i].r; query[i].index = i; }
    
    sort(query.begin(), query.end(), [k](const Query& a, const Query& b) {
        int l1 = a.l / k, l2 = b.l / k;
        if (l1 != l2) return l1 < l2;
        else return a.r < b.r;
    });
    
    vector<int> output(m);
    int l = query[0].l, r = query[0].r;
    vector<int> b(mx, 0);
    vector<int> bp(n, 0);
    int bmx = 0;
    for (int i = l; i <= r; i++) {
        auto x = v[i - 1] - 1;
        b[x]++;
        bp[b[x] - 1]--; bp[b[x]]++;
        
        if (b[x] > bmx) bmx++;
    }
    output[query[0].index] = bmx;
    
    for (int i = 1; i < query.size(); i++) {
        auto _l = query[i].l, _r = query[i].r;
        
        while (_l < l) { l--; auto x = v[l - 1] - 1; b[x]++; bp[b[x] - 1]--; bp[b[x]]++; if (b[x] > bmx) bmx++; }
        while (_r > r) { r++; auto x = v[r - 1] - 1; b[x]++; bp[b[x] - 1]--; bp[b[x]]++; if (b[x] > bmx) bmx++; }
        while (_l > l) { auto x = v[l - 1] - 1; b[x]--; l++; bp[b[x] + 1]--; bp[b[x]]++; if (b[x] + 1 == bmx && bp[b[x] + 1] == 0) bmx--; }
        while (_r < r) { auto x = v[r - 1] - 1; b[x]--; r--; bp[b[x] + 1]--; bp[b[x]]++; if (b[x] + 1 == bmx && bp[b[x] + 1] == 0) bmx--; }
        
        output[query[i].index] = bmx;
    }
    
    for (auto x : output) cout << x << "\n";
}

int main() {
    for (int n; cin >> n, n; solve(n));
}