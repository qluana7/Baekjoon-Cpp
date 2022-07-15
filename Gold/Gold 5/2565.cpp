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

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first < p2.first;
}

int main() {
    int n; cin >> n;
    vector<pair<int, int>> tmp(n);
    
    for (auto& x : tmp) {
        cin >> x.first >> x.second;
    }
    
    sort(tmp.begin(), tmp.end(), cmp);
    
    vector<int> v(n), res(n), lis(1);
    
    for (int i = 0; i < n; i++) v[i] = tmp[i].second;
    
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
    
    cout << n - lis.size();
    
    return 0;
}