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

#define i64 long long

using namespace std;

extern tuple<i64, i64, i64> egcd(i64, i64);

i64 crt(i64 a1, i64 m1, i64 a2, i64 m2) {
    auto [r, a, _] = egcd(m1, m2);

    if ((a2 - a1) % r) return -1;

    i64
        p = (a2 - a1) / r * a,
        x = a1 + m1 * p,
        m = lcm(m1, m2);

    return ((x % m) + m) % m;
}

i64 crtx(const vector<pair<i64, i64>>& ps) {
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
