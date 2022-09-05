#include <iostream>
#include <queue>
#include <iterator>
#include <string>
#include <cmath>

using namespace std;

inline int D(int n) { return n*2%10000; }
inline int S(int n) { return n ? n - 1 : 9999; }
inline int L(int n) { return n*10%10000 + n/1000; }
inline int R(int n) { return n/10 + n%10*1000; }

int dp[10000];

const int pos = (1 << 14) - 1;

inline int save(int p, int n, char c) { dp[p] = n | (c << 14); return p; }

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int rp; cin >> rp;
    
    for (;rp--;) {
        fill(dp, dp + 10000, (1 << 14) - 1);
        int v, r; cin >> v >> r;
        
        queue<int> q;
        q.push(v); dp[v] = 0;
        
        while (!q.empty()) {
            int x = q.front(); q.pop();
            
            if (x == r) break;
            
            if ((dp[D(x)] & pos) == pos) { int t = save(D(x), x, 'D'); q.push(t); }
            if ((dp[L(x)] & pos) == pos) { int t = save(L(x), x, 'L'); q.push(t); }
            if ((dp[R(x)] & pos) == pos) { int t = save(R(x), x, 'R'); q.push(t); }
            if ((dp[S(x)] & pos) == pos) { int t = save(S(x), x, 'S'); q.push(t); }
        }
        
        string s;
        while (r != v) {
            s.push_back(dp[r] >> 14);
            r = dp[r] & pos;
        }
        
        copy(s.rbegin(), s.rend(), ostream_iterator<char>(cout));
        cout << "\n";
    }
    
    return 0;
}