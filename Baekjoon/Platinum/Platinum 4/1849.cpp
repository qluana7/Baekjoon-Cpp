#include <iostream>
#include <vector>
#include <ext/rope>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    __gnu_cxx::rope<int> r;

    for (int i = v.size() - 1; i >= 0; i--)
        r.insert(v[i], i + 1);
    
    for (auto x : r) cout << x << "\n";
}