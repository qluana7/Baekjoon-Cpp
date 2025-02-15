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

u64 invmod(u64 a, u64 m) {
    return powmod(a, m - 2, m);
}

inline u64 add(u64 a, u64 b, u64 m)
{ if ((a += b) > m) a -= m; return a; }

inline u64 sub(i64 a, i64 b, u64 m)
{ if ((a -= b) < 0) a += m; return a; }

inline u64 mul(u64 a, u64 b, u64 m)
{ return a * b % m; }

inline u64 div(u64 a, u64 b, u64 m)
{ return mul(a, invmod(b, m), m); }

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    u64 m, s, x1, x2; cin >> m >> s >> x1 >> x2;

    u64 c = div(sub(mul(x1, x1, m), mul(x2, s, m), m), sub(x1, s, m), m);
    
    cout << div(sub(x1, c, m), s, m) << " " << c;

    /*
    X1 = (a * s + c)
    X2 = (a * X1 + c)

    (X1 - c) / s = a
    (X2 - c) / X1 = a

    (X1 - c) / s = (X2 - c) / X1
    => (X1 - c) * X1 = (X2 - c) * s
    => X1^2 - c*X1 = X2*s - c*s
    => c (X1 - s) = X1^2 - X2*s
    => c = (X1^2 - X2*s) / (X1 - s) 

    X1 = a * s + c
    => X1 - c = a * s
    => (X1 - c) / s = a
    */
}