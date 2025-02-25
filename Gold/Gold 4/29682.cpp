#include <iostream>

#define u64 unsigned long long

using namespace std;

u64 powmod(u64 a, u64 b, u64 m) {
    u64 r = 1;

    while (b) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return r;
}

u64 invmod(u64 a, u64 m) {
    return powmod(a, m - 2, m);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    u64 a, m; cin >> a >> m;
    
    cout << invmod(a, m);
}