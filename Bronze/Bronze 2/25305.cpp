#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> v(n);
    
    for(auto& x : v) cin >> x;
    
    sort(v.begin(), v.end(), greater{});
    
    cout << v[m - 1];
    
    return 0;
}