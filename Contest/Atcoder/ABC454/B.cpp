#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
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
    
    bool arr[m] = { false, };
    bool f1 = false;
    
    while (n --> 0) {
        int x; cin >> x;
        
        if (arr[x - 1]) f1 = true;
        arr[x - 1] = true;
    }
    
    bool f2 = false;
    for (auto b : arr)
        f2 |= !b;
    
    cout << (f1 ? "No" : "Yes") << "\n" << (f2 ? "No" : "Yes");
}