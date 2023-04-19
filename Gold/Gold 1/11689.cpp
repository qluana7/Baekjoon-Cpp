#include <iostream>

using namespace std;

int main() {
    long long n, s; cin >> n; s = n;
    
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            s = s / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    
    if (n > 1) s = s / n * (n - 1);
    
    cout << s;
    
    return 0;
}