#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

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

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    vector<u64> facts(4000001, 0);
    facts[0] = 1;

    for (int i = 1; i < facts.size(); i++)
        facts[i] = facts[i - 1] * i % MOD;

    while (t --> 0) {
        int n, k; cin >> n >> k;
        
        u64 a = facts[n],
            b = facts[k],
            c = facts[n - k];
    
        cout << a * invmod(b * c % MOD, MOD) % MOD << "\n";
    }
}