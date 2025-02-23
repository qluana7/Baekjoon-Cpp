#include <iostream>

using namespace std;

#define u64 unsigned long long
#define i64 long long

i64 i64a[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

u64 mulmod(u64 a, u64 b, u64 m) {
    i64 r = a * b - m * (u64)(1.L / m * a * b);
    return r + m * (r < 0) - m * (r >= (i64)m);
}

u64 modpow(u64 a, u64 b, u64 m) {
    u64 r = 1;

    while (b) {
        if (b & 1) r = mulmod(r, a, m);
        a = mulmod(a, a, m);
        b >>= 1;
    }

    return r;
}

bool miller_rabin(i64 n, i64 a) {
    if (a % n == 0) return true;
    
    i64 d = n - 1;
    
    while (true) {
        i64 t = modpow(a, d, n);
        if (t == n - 1) return true;
        if (d % 2 == 1) return t == 1 || t == n - 1;
        d >>= 1;
    }
}

bool isprime(i64 n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (auto a : i64a) {
        if (n == a) return true;
        if (!miller_rabin(n, a)) return false;
    }
    
    return true;
}

bool islie(u64 a, u64 p) {
    if (isprime(p)) return false;

    return modpow(a, p, p) == a;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m;
    while (cin >> n >> m, n) {
        cout << (islie(m, n) ? "yes" : "no") << "\n";
    }
}