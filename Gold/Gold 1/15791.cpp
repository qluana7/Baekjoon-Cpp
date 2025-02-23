#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define i64 long long
#define u64 unsigned long long

#define MOD 1000000007

u64 powmod(u64 a, u64 b, u64 m) {
    u64 r = 1;

    while (b) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return r;
}

u64 invmod(u64 a, u64 m)
{ return powmod(a, m - 2, m); }

tuple<u64, u64, u64> fac(u64 n, u64 k) {
    u64 rn = 1, rk = 1, rnk = 1;

    for (u64 i = 1; i <= n; i++) {
        rn = rn * i % MOD;

        if (i == k) rk = rn;
        if (i == n - k) rnk = rn;
    }

    return { rn, rk, rnk };
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, k; cin >> n >> k;

   auto [a, b, c] = fac(n, k);
   
   cout << a * invmod(b * c % MOD, MOD) % MOD;
}