#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bsearch(const vector<int>& v, int t) {
    int l = 0, m, r = v.size();
    
    while (l < r) {
        m = l + r >> 1;
        
        if (v[m] < t) l = m + 1;
        else r = m;
    }
    
    return r;
}

int main() {
    int n; cin >> n;
    vector<int> v(n), res(n), lis(1);
    
    for (int& x : v) cin >> x;
    
    lis[0] = v[0];
    res[0] = 0;
    
    for (int i = 1; i < v.size(); i++) {
        if (lis.back() < v[i]) {
            res[i] = lis.size();
            lis.push_back(v[i]);
            continue;
        }
        
        int d = bsearch(lis, v[i]);
        lis[d] = v[i];
        res[i] = d;
    }
    
    cout << lis.size() << "\n";
    
    int pos = lis.size() - 1;
    for (int i = res.size() - 1; i >= 0; i--) {
        if (res[i] == pos) {
            lis[pos] = v[i];
            pos--;
        }
    }
    
    for (int x : lis) cout << x << " ";
    
    return 0;
}