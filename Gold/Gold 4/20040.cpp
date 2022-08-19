#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int head(vector<int>& v, int idx) {
    if (v[idx] == idx) return idx;
    
    return v[idx] = head(v, v[idx]);
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> v(n); iota(v.begin(), v.end(), 0);
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        
        if (head(v, a) == head(v, b)) { cout << i + 1; exit(0); }
        v[head(v, a)] = head(v, b);
    }
    
    cout << 0;
    
    return 0;
}