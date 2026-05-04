#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n, cnt = 0; cin >> n;
    vector<int> v(n), primes;
    iota(v.begin(), v.end(), 2);
    
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) continue;
        
        primes.push_back(primes.empty() ? v[i] : primes.back() + v[i]);
        if (primes.back() == n) cnt++;
        
        for (int j = i + v[i]; j < n; j += v[i])
            v[j] = 0;
    }
    
    for (int st = 0, en = 0; en < primes.size(); ) {
        if (en == primes.size() - 1) {
            for (; st != en; st++)
                cnt += (primes[en] - primes[st] == n);
            break;
        }
        
        if (primes[en] - primes[st] < n) en++;
        else if (primes[en] - primes[st] > n) st++;
        else { cnt++; en++; }
    }
    
    cout << cnt;
    
    return 0;
}