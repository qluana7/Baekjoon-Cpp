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

int solve(const string& s) {
    vector<array<int, 26>> a1, a2;
    a1.resize(s.size()); a2.resize(s.size());
    
    a1[0] = a2[0] = { 0, };
    
    a1[0][s.front() - 'a']++;
    
    for (int i = 1; i < s.size(); i++) {
        a1[i] = a1[i - 1]; a2[i] = a2[i - 1];
        
        (i & 1 ? a2 : a1)[i][s[i] - 'a']++;
    }
    
    if (!(s.size() & 1)) {
        int a1m = *ranges::max_element(a1.back()), a2m = *ranges::max_element(a2.back());
        
        return s.size() - (a1m + a2m);
    }
    
    int mn = s.size();
    // eliminate character
    for (int i = 0; i < s.size(); i++) {
        auto t1 = a1[i], t2 = a2[i];
        
        (i & 1 ? t2 : t1)[s[i] - 'a']--;
        
        int a1m = 0, a2m = 0;
        
        for (int j = 0; j < 26; j++) {
            a1m = max(a1m, a1.back()[j] - a1[i][j] + t2[j]);
            a2m = max(a2m, a2.back()[j] - a2[i][j] + t1[j]);
        }
        
            
        mn = min<int>(mn, s.size() - 1 - (a1m + a2m));
    }
    
    return mn + 1;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    while (t --> 0) {
        int n; cin >> n;
        string s; cin >> s;
        
        cout << solve(s) << "\n";
    }
}