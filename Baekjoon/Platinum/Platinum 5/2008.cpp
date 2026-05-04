#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;

// Minimal cost memorization
vector<vector<u64>> ctable;
vector<u64> lines;
int n, m, a, b, x, y;

void fill(int pos, int depth, bool first = false) {
    int line = lines[depth];
    
    for (int i = 0; i < n; i++) {
        u64 cost = first ? 0 : ctable[depth][pos];
        
        // When go down, need to remove line
        if (pos == i && (line == i || line == i + 1))
            cost += x;
        else if (pos != i) {
            cost += abs(pos - i) * y;
            
            if (i < pos) {
                if (i < line && line <= pos) cost -= y;
            } else {
                if (pos < line && line <= i) cost -= y;
            }
        }
        
        if (m == 0) {
            u64& tb = ctable[depth][i];
            tb = min(tb, cost);
        } else {
            u64& tb = ctable[depth + 1][i];
            tb = min(tb, cost);
        }
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    ctable = vector<vector<u64>>(m + 1, vector<u64>(n, 2147384647));
    lines = vector<u64>(m);
    
    cin >> a >> b >> x >> y;
    for (auto& x : lines) cin >> x;
    // Exception for last line.
    lines.push_back(-1);
    
    fill(a - 1, 0, true);
    
    for (int i = 1; i < m; i++)
        for (int j = 0; j < n; j++)
            fill(j, i);
            
    cout << ctable.back()[b - 1];
}