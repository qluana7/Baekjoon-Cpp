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

constexpr u64 limit = 1e9;

inline int get_digit(u64 value) {
    return (int)__builtin_log10(value) + 1;
}

constinit array<u64, 10> tens = [] () consteval {
    array<u64, 10> arr;
    
    arr[0] = 1;
    for (unsigned int i = 1; i < 10; i++)
        arr[i] = arr[i - 1] * 10;
        
    return arr;
}();

u64 concat(u64 a, u64 b) {
    return a * tens[get_digit(b)] + b;
}

void get_pair(const vector<u64>& t1, const vector<u64>& t2, vector<u64>& result) {
    for (int i = 0; i < t1.size(); i++) {
        for (int j = i; j < t2.size(); j++) {
            auto v1 = t1[i], v2 = t2[j];
            result.push_back(concat(v1, v2));
            result.push_back(concat(v2, v1));
        }
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    vector<vector<u64>> table(9);
    
    table[0] = { 1, 2, 4, 8 };
    
    u64 r = 16;
    
    for (int i = 2; i < 10; i++) {
        for (int j = 1; j < (i + 1) / 2; j++) {
            get_pair(table[j - 1], table[i - j - 1], table[i - 1]);
            get_pair(table[i - j - 1], table[j - 1], table[i - 1]);
        }
        
        if (i % 2 == 0) get_pair(table[i / 2 - 1], table[i / 2 - 1], table[i - 1]);
        
        while (r < tens[i]) {
            table[i - 1].push_back(r);
            r *= 2;
        }
        
        sort(table[i - 1].begin(), table[i - 1].end());
        table[i - 1].erase(unique(table[i - 1].begin(), table[i - 1].end()), table[i - 1].end());
    }
    
    u64 n; cin >> n; n--;
    
    int idx = 0;
    while (table[idx].size() <= n) {
        n -= table[idx].size();
        idx++;
    }
    
    cout << table[idx][n];
}