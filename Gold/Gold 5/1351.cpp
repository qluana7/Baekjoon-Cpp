#include <iostream>
#include <unordered_map>

#define u64 unsigned long long

using namespace std;

unordered_map<u64, u64> cache;
u64 p, q;

u64 get(u64 x) {
    if (x == 0) return 1;
    if (cache.count(x)) return cache[x];

    return (cache[x] = get(x / p) + get(x / q));
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    u64 n; cin >> n >> p >> q;

    cout << get(n);
}