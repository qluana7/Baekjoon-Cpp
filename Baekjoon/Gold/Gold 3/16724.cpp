#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

int head(vector<int>& v, int idx) {
    if (v[idx] == idx) return idx;
    
    return v[idx] = head(v, v[idx]);
}

int main() {
    // 2d array -> 1d array
    // think direction in 1d array
    
    int n, m; cin >> n >> m;
    vector<int> v(n * m); iota(v.begin(), v.end(), 0);
    
    for (int i = 0; i < n * m; i++) {
        char c; cin >> c;
        
        switch (c) {
            case 'U': v[head(v, i)] = head(v, i - m); break;
            case 'D': v[head(v, i)] = head(v, i + m); break;
            case 'L': v[head(v, i)] = head(v, i - 1); break;
            case 'R': v[head(v, i)] = head(v, i + 1); break;
        }
    }
    
    unordered_map<int, int> mp;
    for (auto x : v) mp[head(v, x)]++;
    
    cout << mp.size();
    
    return 0;
}