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

    for (int i = 0; i < n; i++)
        r.insert(v[i], i + 1);
    
    for (int i = n - 1; i >= 0; i--)
        cout << r[i] << " ";
}