#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
set<int> s;

void solve(int st, int dp, set<int> s, vector<int> v) {
    v.push_back(st);
    s.erase(st);
    
    if (dp == m) {
        for (int x : v) cout << x << " ";
        cout << "\n";
        return;
    }
    
    for (int x : s) {
        solve(x, dp + 1, s, v);
    }
}

int main() {
    cin >> n >> m;
    
    for (int t = n;t--;) {
        int x; cin >> x;
        s.insert(x);
    }
    
    for (int x : s) {
        vector<int> vec;
        solve(x, 1, s, vec);
    }
    
    return 0;
}