#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
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
    
    string s; cin >> s;
    
    cout << (s.size() % 5 ? "No" : "Yes");
}