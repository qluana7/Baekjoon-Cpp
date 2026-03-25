#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
constexpr u64 max_value = 10e18;

vector<u64> sizes;
vector<array<u64, 26>> Xcnt, Ycnt, totcnt;

void setup_cnt(vector<array<u64, 26>>& vt, const string& S) {
    vt.resize(S.size() + 1);
    
    array<u64, 26> cnts = { 0, };
    for (int i = 0; i < S.size(); i++) {
        ++cnts[S[i] - 'a'];
        
        vt[i + 1] = cnts;
    }
}

void init(const string& X, const string& Y) {
    sizes = { 0, X.size(), Y.size() };
    
    while (sizes.back() <= max_value)
        sizes.push_back(sizes.end()[-1] + sizes.end()[-2]);
}

void mem(const string& X, const string& Y) {
    setup_cnt(Xcnt, X);
    setup_cnt(Ycnt, Y);
    
    totcnt = { { 0, }, Xcnt.back(), Ycnt.back() };
    totcnt.resize(sizes.size());
    
    for (int i = 3; i < sizes.size(); i++) {
        totcnt[i] = totcnt[i - 2];
        
        for (int j = 0; j < 26; j++)
            totcnt[i][j] += totcnt[i - 1][j];
    }
}

u64 rec(u64 k, u64 n, u64 i) {
    if (k == 1)
        return Xcnt[n][i];
    else if (k == 2)
        return Ycnt[n][i];
    else {
        if (n <= sizes[k - 1])
            return rec(k - 1, n, i);
        else
            return totcnt[k - 1][i] + rec(k - 2, n - sizes[k - 1], i);
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    string x, y; cin >> x >> y;
    
    init(x, y);
    mem(x, y);
    u64 K = sizes.size() - 1;
    
    u64 n; cin >> n;
    
    while (n --> 0) {
        u64 a, b; char c; cin >> a >> b >> c;
        
        u64 idx = c - 'a';
        
        cout << rec(K, b, idx) - rec(K, a - 1, idx) << "\n";
    }
}