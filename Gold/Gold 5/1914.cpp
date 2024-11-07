#include <iostream>
#include <cstdint>

using namespace std;

__uint128_t pow128(__uint128_t n, __uint128_t p) {
    __uint128_t r = 1;
    
    while (p) {
        if (p & 1) r = n * r;
        
        n = n * n;
        
        p >>= 1;
    }
    
    return r;
}

template<typename _CharT, typename _Traits>
basic_ostream<_CharT, _Traits>& operator<<(basic_ostream<_CharT, _Traits>& os, __uint128_t x) {
    if (x < UINT64_MAX) { os << (unsigned long long)x; return os; }
    else os << x / 10;

    os.put(x % 10 + '0');

    return os;
}

void rec(int k, int s, int m, int e) {
    if (k == 1) { cout << s << " " << e << "\n"; return; }
    
    rec(k - 1, s, e, m);

    cout << s << " " << e << "\n";

    rec(k - 1, m, s, e);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n; cin >> n;
    cout << pow128(2, n) - 1 << "\n";

    if (n <= 20) rec(n, 1, 2, 3);
}