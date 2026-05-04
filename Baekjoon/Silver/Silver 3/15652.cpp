#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int n, m;

void solve(int st, int dp, vector<int> v) {
    if (dp == m) {
        for (int x : v) cout << x << " ";
        cout << "\n";
        return;
    }
    
    for (int i = st; i <= n; i++) {
        v[dp] = i;
        solve(i, dp + 1, v);
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        vector<int> vec(m); vec[0] = i + 1;
        solve(i + 1, 1, vec);
    }
    
    return 0;
}