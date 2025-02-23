#include <iostream>
#include <tuple>
#include <numeric>

using namespace std;

#define u64 unsigned long long
#define i64 long long

tuple<i64, i64, i64> egcd(i64 a, i64 b) {
    pair<i64, i64>
        r { a, b },
        z { 1, 0 },
        t { 0, 1 };
    
    auto& [r0, r1] = r;
    auto& [z0, z1] = z;
    auto& [t0, t1] = t;

    while (r1 > 0) {
        i64 q = r0 / r1;
        r = { r1, r0 - q * r1 };
        z = { z1, z0 - q * z1 };
        t = { t1, t0 - q * t1 };
    }

    return { r0, z0, t0 };
}

i64 inv(i64 a, i64 m) {
    if (gcd(a, m) != 1) return -1;

    return (get<1>(egcd(a, m)) + m) % m;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    i64 n, m; cin >> n >> m;

    cout << n - m << " " << inv(m, n);
}