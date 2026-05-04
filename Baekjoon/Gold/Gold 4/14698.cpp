#include <iostream>
#include <vector>
#include <queue>

#define u64 unsigned long long
#define u128 __uint128_t

#define MOD 1000000007

using namespace std;

inline u64 mulmod(u64 a, u64 b, u64 m)
{ return a * b % m; }

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    
    while (n --> 0) {
        priority_queue<u128, vector<u128>, greater<u128>> pq;

        int m; cin >> m;
        while (m --> 0) {
            u64 x; cin >> x;
            pq.push(x);
        }

        u64 s = 1;
        while (pq.size() != 1) {
            u128 a = pq.top(); pq.pop();
            u128 b = pq.top(); pq.pop();

            s = mulmod(s, a * b % MOD, MOD);
            pq.push(a * b);
        }

        cout << s << "\n";
    }
}