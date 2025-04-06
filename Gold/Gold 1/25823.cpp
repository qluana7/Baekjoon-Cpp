#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define u64 unsigned long long

#define MOD 1000000007

u64 addmod(u64 a, u64 b, u64 m)
{ if ((a += b) >= m) a -= m; return a; }

u64 mulmod(u64 a, u64 b, u64 m)
{ return a * b % m; }

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

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int m; cin >> m;
    vector<u64> facts(400001, 0);
    facts[0] = 1;

    for (int i = 1; i < facts.size(); i++)
        facts[i] = facts[i - 1] * i % MOD;

    u64 res = 0;

    for (int i = 3; i <= m; i++) {
        u64 a = facts[2 * i],
            b = facts[i];
    
        res = addmod(res, mulmod(a, invmod(mulmod(b, b, MOD), MOD), MOD), MOD);
    }

    cout << res;
}