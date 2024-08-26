#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

#define l2(x) ((long long)log2((long double)(x)))

using namespace std;

long long getnum(const vector<long long>& v, long long n) {
    if (n < 2) return n;
    if (!((n & (n + 1)) - 1)) return v[l2(n)];

    long long t = n - (1LL << l2(n));
    return getnum(v, t) + v[l2(n)] + (t + 1);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    long long a, b; cin >> a >> b;
    vector<long long> v(l2(b) + 2);

    v[0] = 0;
    for (int i = 1; i < v.size(); i++)
        v[i] = (1LL << (i - 1)) + 2 * v[i - 1];
    
    cout << getnum(v, b) - getnum(v, a - 1) << "\n";
}

/*

0.    0     = 0
1.    1     = 1

2.    10    = 1 = 1 + 0
3.    11    = 2 = 1 + 1

4.    100   = 1 = 1 + 0
5.    101   = 2 = 1 + 1
6.    110   = 2 = 1 + 1
7.    111   = 3 = 1 + 2

8.    1000  = 1 = 1 + 0
9.    1001  = 2 = 1 + 1
10.   1010  = 2 = 1 + 1
11.   1011  = 3 = 1 + 2
12.   1100  = 2 = 1 + 1
13.   1101  = 3 = 1 + 2
14.   1110  = 3 = 1 + 2
15.   1111  = 4 = 1 + 3

*/
