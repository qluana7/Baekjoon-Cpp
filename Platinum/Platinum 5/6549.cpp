#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<ll> v;

ll exp(int st, int ed) {
    int m = (st + ed) / 2, a = m, b = m;
    ll w = 1, h = v[m];
    ll res = w * h;
    
    while (ed - st > b - a) {
        ll
            h1 = a > st ? min(h, v[a - 1]) : -1,
            h2 = b < ed ? min(h, v[b + 1]) : -1;
        
        if (h1 < h2) {
            h = h2; b++;
        } else {
            h = h1; a--;
        }
        
        w++;
        res = max(res, w * h);
    }
    
    return res;
}

ll gmax(int st, int ed) {
    if (st == ed) return v[st];
    
    int m = (st + ed) / 2;
    ll a = gmax(st, m), b = gmax(m + 1, ed);
    
    ll e = exp(st, ed);
    
    return max(max(a, b), e);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    for (;;) {
        int n; cin >> n;
        
        if (n == 0) break;
        
        v = vector<ll>(n);
        
        for (ll& x : v) cin >> x;
        
        cout << gmax(0, n - 1) << "\n";
    }
    
    return 0;
}