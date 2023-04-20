#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n, t = 0; cin >> n;
    vector<int> v(n);
    cin >> v[0] >> v[1]; t = v[1] - v[0];
    for (int i = 2; i < n; i++) {
        cin >> v[i];
        
        t = gcd(t, v[i] - v[0]);
    }
    
    int c = 0;
    for (int i = 0, x = v[0]; i < n; x += t) {
        if (v[i] == x) i++;
        else c++;
    }
    
    cout << c;
    
    return 0;
}