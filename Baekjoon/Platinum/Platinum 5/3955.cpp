#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

#include <iostream>
#include <tuple>

#define u64 unsigned long long
#define i64 long long

using namespace std;

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

i64 addmod(i64 a, i64 b, i64 m)
{ if ((a += b) >= m) a -= m; return a; }

i64 inv(i64 a, i64 m) {
    auto [r, x, _] = egcd(a, m);

    if (r != 1) return -1;

    return addmod(x, m, m);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n; cin >> n;
    
    while (n --> 0) {
        i64 a, b; cin >> a >> b;
        
        if (b == 1) {
            if (a >= 1e9) cout << "IMPOSSIBLE\n";
            else cout << a + 1 << "\n";
            continue;
        }
        
        if (a == 1) {
            cout << "1\n";
            continue;
        }

        i64 k = inv(b, a);

        if (k == -1 || k > 1e9) cout << "IMPOSSIBLE\n";
        else cout << k << "\n";
    }
}