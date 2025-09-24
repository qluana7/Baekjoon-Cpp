#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v(1);
    int n, x; cin >> n;
    
    for (cin >> v[0]; --n;) {
        cin >> x;
        
        if (v.back() < x) {
            v.push_back(x);
            continue;
        }
        
        *lower_bound(v.begin(), v.end(), x) = x;
    }
    
    cout << v.size();
    
    return 0;
}