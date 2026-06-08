#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

int solve(int l, int r) {
    int cnt = 0, k = l;
    while (k) {
        while ((k % 10 == l % 10 || k % 10 == r % 10) && k < r)
            k++;
        
        cnt += (k % 10 == l % 10) + (k % 10 == r % 10);
        k /= 10; l /= 10; r /= 10;
    }
    
    return cnt;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    while (n --> 0) {
        int a, b; cin >> a >> b;
        
        cout << solve(a, b) << "\n";
    }
}