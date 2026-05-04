#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    
    int n; cin >> n;
    for (; n--;) { int x; cin >> x; v.push_back(x); }
    
    if (!next_permutation(v.begin(), v.end())) cout << -1;
    else {
        for (int& n : v) cout << n << " ";
    }
    
    return 0;
}