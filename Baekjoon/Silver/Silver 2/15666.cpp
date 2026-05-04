#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
set<vector<int>> outp;

void solve(int st, int dp, vector<int> v) {
    v[dp - 1] = arr[st];
    if (dp == m) {
        if (outp.find(v) == outp.end()) outp.insert(v);
        return;
    }
    
    for (int i = st; i < n; i++) {
        solve(i, dp + 1, v);
    }
}
int main() {
    cin >> n >> m;
    
    for (int t = n;t--;) {
        int x; cin >> x;
        arr.push_back(x);
    } sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n; i++) {
        vector<int> vec(m);
        solve(i, 1, vec);
    }
    
    for (const auto& vt : outp) {
        copy(vt.begin(), vt.end(), ostream_iterator<int>(cout, " "));
        cout << "\n";
    }
    
    return 0;
}