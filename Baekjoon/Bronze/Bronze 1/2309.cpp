#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v(9); int t = 0;
    
    for (int& x : v) { cin >> x; t += x; }
    sort(v.begin(), v.end());
    
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (t - v[i] - v[j] == 100) {
                for (int p : v) {
                    if (p == v[i] || p == v[j]) continue;
                    cout << p << "\n";
                }
                
                return 0;
            }
        }
    }
    
    return 0;
}