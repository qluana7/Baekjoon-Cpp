#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct P {
    int sum, cnt;
};

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    int k; cin >> k;
    
    vector<int> dp(v.back() * k, 0);
    
    queue<P> q;
    for (auto x : v) q.push({ x, 1 });
    
    while (!q.empty()) {
        P p = q.front(); q.pop();
        
        if (dp[p.sum] != 0) continue;
        dp[p.sum] = 1;
        if (p.cnt == k) continue;
        
        for (auto x : v) q.push({ p.sum + x, p.cnt + 1 });
    }
    
    int i = 0;
    while (dp[++i] != 0);
    cout << (i % 2 == 0 ? "holsoon" : "jjaksoon") << " win at " << i;
}