#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
multiset<int> s;
set<vector<int>> outp;

void ms_erase(multiset<int>& ms, int v) {
    auto iter = ms.find(v);
    if (iter != ms.end()) ms.erase(iter);
}

void solve(int st, int dp, multiset<int> s, vector<int> v) {
    v.push_back(st);
    ms_erase(s, st);
    
    if (dp == m) {
        if (outp.find(v) == outp.end()) outp.insert(v);
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
    
    for (const auto& vt : outp) {
        copy(vt.begin(), vt.end(), ostream_iterator<int>(cout, " "));
        cout << "\n";
    }
    
    return 0;
}