#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m = 0; cin >> n;
    vector<int> inp(n);
    for (auto& x : inp) {
        cin >> x;
        m = max(m, x);
    }
    vector<int> primes(m + 1);
    
    for (int i = 2; i < primes.size(); i++) {
        for (int k = i * 2; k < primes.size(); k += i) {
            if (primes[k] == 1) continue;
            else if (k % i == 0) primes[k] = 1;
        }
    }
    
    for (auto x : inp) {
        int c = 0;
        
        for (int i = 2; i * 2 <= x; i++) {
            if (primes[i] == 1) continue;
            if (primes[x - i] == 1) continue;
            
            c++;
        }
        
        cout << c << "\n";
    }
    
    return 0;
}