/*
 * Algorithm Name : Modular Multiplicative Inverse with Fermat's Little Theorem
 *
 * Description
 *    - 페르마의 소정리를 이용한 모듈러 역원 구하기
 * 
 *    - a^(m-1) ≡ 1 (mod m) (m is prime number)
 *      -> a^(m-2) ≡ a^-1 (mod m)
 * 
 *       a^-1 ≡ a^(m-2) (mod m)
 * 
 * Note
 *    - Meaning of the 128 suffix on the function name:
 *      When calculating u64 * u64 % u64, it can overflow.
 *      The 128 suffix function prevents overflow using a hack.
 *      This is faster than using uint128_t,
 *      but cannot be used if 80-bit floating point is not supported.
 *      * A notable exception is MSVC, which implements long double
 *        in the same format as double. (https://en.cppreference.com/w/cpp/language/types)
 * 
 * Reference
 *    - mulmod : jhnah917's message from solved.ac Discord
 *    - https://en.wikipedia.org/wiki/Fermat%27s_little_theorem
 */

#ifndef i64
#define i64 long long
#endif
#ifndef u64
#define u64 unsigned long long
#endif

// Modular hack : u64 * u64 % u64 without overflow.
u64 mulmod(u64 a, u64 b, u64 m) {
    i64 r = a * b - m * (u64)(1.L / m * a * b);
    return r + m * (r < 0) - m * (r >= (i64)m);
}

u64 powmod128(u64 a, u64 b, u64 m) {
    u64 r = 1;

    while (b) {
        if (b & 1) r = mulmod(r, a, m);
        a = mulmod(a, a, m);
        b >>= 1;
    }

    return r;
}

u64 invmod128(u64 a, u64 m) {
    return powmod128(a, m - 2, m);
}

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