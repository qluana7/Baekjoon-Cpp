#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")

#include <iostream>
#include <unordered_map>

#define i64 long long

using namespace std;

unordered_map<i64, i64> cache;
i64 p, q, x, y;

i64 get(i64 k) {
    if (k <= 0) return 1;
    if (cache.count(k)) return cache[k];

    i64 a = k / p - x > 0 ? get(k / p - x) : 1,
        b = k / q - y > 0 ? get(k / q - y) : 1;
    return (cache[k] = a + b);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    i64 n; cin >> n >> p >> q >> x >> y;

    cout << get(n);
}