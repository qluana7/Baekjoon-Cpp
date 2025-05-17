#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>

#define i64 long long
#define i128 __int128_t

using namespace std;

i128 gcd(i128 a, i128 b) {
    if (b == 0) return a;

    return gcd(b, a % b);
}

i128 lcm(i128 a, i128 b) {
    return a / gcd(a, b) * b;
}

tuple<i128, i128, i128> egcd(i128 a, i128 b) {
    pair<i128, i128>
        r { a, b },
        z { 1, 0 },
        t { 0, 1 };
    
    auto& [r0, r1] = r;
    auto& [z0, z1] = z;
    auto& [t0, t1] = t;

    while (r1 > 0) {
        i128 q = r0 / r1;
        r = { r1, r0 - q * r1 };
        z = { z1, z0 - q * z1 };
        t = { t1, t0 - q * t1 };
    }

    return { r0, z0, t0 };
}

i128 crt(i128 a1, i128 m1, i128 a2, i128 m2) {
    auto [r, a, _] = egcd(m1, m2);

    if ((a2 - a1) % r) return -1;

    i128
        p = (a2 - a1) / r * a,
        x = a1 + m1 * p,
        m = lcm(m1, m2);

    return ((x % m) + m) % m;
}

i128 crtx(const vector<pair<i128, i128>>& ps) {
    if (ps.size() == 1) return -1;

    auto [prev_p, prev_mod] = ps[0];

    for (int i = 1; i < ps.size(); i++) {
        auto [p, mod] = ps[i];
        prev_p = crt(prev_p, prev_mod, p, mod);
        prev_mod = lcm(prev_mod, mod);

        if (prev_p == -1) return -1;
    }

    return prev_p;
}

istream& operator>>(istream& __is, __int128_t& t) {
    i64 _; __is >> _; t = _; return __is;
}

ostream& operator<<(ostream& __os, __int128_t t)
{ return __os << (i64)t; }

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;

    while (n --> 0) {
        vector<pair<i128, i128>> ps(3);

        for (auto& [_, m] : ps) cin >> m;
        for (auto& [a, _] : ps) cin >> a;

        cout << crtx(ps) << "\n";
    }
}