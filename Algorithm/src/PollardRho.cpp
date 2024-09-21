/*
 * Algorithm Name : Pollard's Rho
 *
 * Description
 *    - O(N ^ 1/4)의 성능으로 빠르게 소인수 분해를 하는 알고리즘.
 * 
 *    - 배경지식 1. Floyd's Cycle Finding Algorithm
 *    - 배경지식 ext. Birthday Paradox
 * 
 *    - 초기값 a와 함수 g(x)를 정의한다. (N = pq)
 *    - ex) a = 3, g(x) = (x^2 + 1) mod N
 *    - 이때 g(x)에 대한 수열과 (x^2 + 1) mod p에 대해 이 둘은 언젠가는 반복되게 된다.
 *    - 이러한 반복은 Floyd's Cycle Finding Algorithm을 통해서 찾는다.
 *    - 사이클에 의해 a1 = a2 mod p가 되는 지점이 존재하게 된다. 따라서
 *    - a1 - a2 = 0 mod p가 성립(참고 1) 하고 a1, a2가 N으로 나누어 떨어지므로
 *    - gcd(|a1 - a2|, N) 으로 값을 얻어낼 수 있다.
 * 
 *    - 참고 1
 *    - a1 - a2 = 0 mod p는 실패할 수 있으나, Birthday Paradox에 의해
 *    - 그 가능성은 무한히 작다. 따라서 성립힌다고 가정한다.
 * 
 * Reference
 *    - https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm (Implementation)
 *    - https://blog.naver.com/jinhan814/222141831551
 */

#include <iostream>
#include <numeric>

using namespace std;

// Can use random at 

inline int g(int x, int n) { return (((x % n) * (x % n)) % n + 1 /* here */) % n; }

int pollard_rho(int n) {
    int x = 3 /* and here. */, y = x, d = 1;
    
    while (d == 1) {
        x = g(x, n);
        y = g(g(y, n), n);
        d = gcd(abs(x - y), n);
        
        if (d == n) return pollard_rho(n);
    }
    
    return pollard_rho(n);
}