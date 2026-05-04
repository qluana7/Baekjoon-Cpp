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
    cout << "gmax(" << st << ", " << ed << ") : [" << a << ", " << b << "]\n";
    
    ll e = exp(st, ed);
    cout << "exp(" << st << ", " << ed << ") : " << e << "\n";
    
    return max(max(a, b), e);
}

int main() {
    int n; cin >> n;
    v = vector<ll>(n);
    
    for (ll& x : v) cin >> x;
    
    cout << gmax(0, n - 1);
    
    return 0;
}