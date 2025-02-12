/*
 * Algorithm Name : Chinese Remainder Theorem
 *
 * Description
 *    - 중국인의 나머지 정리 구현
 *    - ┌ x ≡ a (mod m1)
 *      └ x ≡ b (mod m2)
 *      
 *         x ≡ A + B (mod m1 * m2)
 *      -> x ≡ m2 * a0 + m1 * b0 (mod m1 * m2)
 *      -> ┌ m2 * a0 ≡ a (mod m1)
 *         └ m1 * b0 ≡ b (mod m2)
 *      -> ┌ a0 ≡ a / m2 (mod m1)
 *         └ b0 ≡ b / m1 (mod m2)
 * 
 *      How to get a / m2, b / m1 in modular arithmetic?
 * 
 *      We need to use Modular Inverse with the Extended Euclidean Algorithm.
 *      * Fermat's Little Theorem can be used when m1 * m2 is a prime number.
 *        But, since there are cases where the numbers are not prime, 
 *        generally use EGCD for implementation.
 *      
 *      a0 = a * m2^-1 (mod m1)
 *      b0 = b * m1^-1 (mod m2)
 * 
 *      Now, x = A + B = m2 * a0 + m1 * b0
 *             = m2 * a * m2^-1 + m1 * b * m1^-1
 * 
 * Reference
 *    - https://blog.joonas.io/23
 *    - egcd : https://p4per.dev/posts/Extended-Euclidean/
 *             https://yuanie.tistory.com/18
 */

#include <vector>
#include <numeric>
#include <tuple>

using namespace std;

#ifndef i64
#define i64 long long
#endif

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

i64 __crt(int a1, int m1, int a2, int m2) {
    auto [r, a, _] = egcd(m1, m2);

    if ((a2 - a1) % r) return -1;

    i64
        p = (a2 - a1) / r * a,
        x = a1 + m1 * p,
        m = lcm(m1, m2);

    return ((x % m) + m) % m;
}

i64 crt(const vector<pair<i64, i64>>& ps) {
    if (ps.size() == 1) return -1;

    auto [prev_p, prev_mod] = ps[0];

    for (int i = 1; i < ps.size(); i++) {
        auto [p, mod] = ps[i];
        prev_p = __crt(prev_p, prev_mod, p, mod);
        prev_mod = lcm(prev_mod, mod);

        if (prev_p == -1) return -1;
    }

    return prev_p;
}
