/*
 * Algorithm Name : Miller Rabin
 *
 * Description
 *    - O(N log^3 N) (FFT 사용시 O(N log^2 N))의 속도로 소수를 판별할 수 있는 알고리즘
 *    - 확률적 판단이나, int, long long 범위에서는 증명되었음.
 * 
 *    - 배경지식 1. 페르마의 소정리
 *    - 배경지식 2. 소수 P에 대해 x^2 ≡ 1 (mod p) => x ≡ 1 (mod p) or x ≡ -1 (mod p)
 * 
 *    - N - 1을 d * 2^r 라고 할때, N이 소수이므로 페르마의 소정리에 의해
 *    - a^(N - 1) mod N => a^(d * 2^r) mod N => (a^(d * 2^(r - 1)))^2 mod N
 *    - 보조 정리 2에 의해서 a^(d * 2^(r - 1)) ≡ 1 mod p or a^(d * 2^(r - 1)) ≡ -1
 *    - 이를 반복하면 최종적으로 다음과 같은 형태가 된다.
 *    - a^d ≡ 1 mod p or a^d ≡ -1 mod p
 * 
 *    - 따라서 다음 조건에 만족한다면 소수(N != 2) 로써 판별할 수 있다
 *    - a^d ≡ 1 mod N | 어떤 r(0 <= r < s)에 대해서 a^d * (2 ^ r) ≡ -1 mod p
 * 
 * Reference
 *    - https://goodbyefin.tistory.com/47
 */

int i32a[] = { 2, 7, 61 };
unsigned long long i64a[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

int modpow(int n, int p, int m) {
    int r = 1;
    
    while (p) {
        if (p & 1) r = ((n % m) * (r % m)) % m;
        
        n = ((n % m) * (n % m)) % m;
        
        p >>= 1;
    }
    
    return r;
}

bool miller_rabin(int n, int a) {
    if (a == n) return true;
    
    int d = n - 1;
    
    while (true) {
        int t = modpow(a, d, n);
        if (t == n - 1) return true;
        if (d % 2 == 1) return t == 1 || t == n - 1;
        d >>= 1;
    }
}