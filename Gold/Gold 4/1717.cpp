#include <iostream>
#include <vector>

using namespace std;

int head(vector<int>& v, int idx) {
    if (v[idx] == idx) return idx;
    
    return v[idx] = head(v, v[idx]);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    
    vector<int> v(n + 1);
    for (int i = 0; i < n + 1; i++) v[i] = i;
    
    for (int i = 0; i < m; i++) {
        int c, a, b; cin >> c >> a >> b;
        
        if (c == 0) v[head(v, b)] = head(v, a);
        else cout << (head(v, a) == head(v, b) ? "YES\n" : "NO\n");
    }
    
    return 0;
}