#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
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
    
    int n, m; cin >> n >> m;
    
    cout << (
        (n == 1 && m == 7) ||
        (n == 3 && m == 3) ||
        (n == 5 && m == 5) ||
        (n == 7 && m == 7) ||
        (n == 9 && m == 9)
     ? "Yes" : "No");
}