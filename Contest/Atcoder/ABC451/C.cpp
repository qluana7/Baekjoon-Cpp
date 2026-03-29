#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <atcoder/all>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    multiset<u64> s;
    
    int n; cin >> n;
    
    while (n --> 0) {
        u64 a, b; cin >> a >> b;
        
        if (a == 1) s.insert(b);
        else {
            auto it = s.upper_bound(b);
            s.erase(s.begin(), it);
        }
        
        cout << s.size() << "\n";
    }
    
}