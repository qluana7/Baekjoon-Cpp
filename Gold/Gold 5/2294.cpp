#include <iostream>
#include <vector>

using namespace std;

int min_f(int a, int b) {
    if (a == -1) return b;
    else if (b == -1) return a;
    else return min(a, b);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<int> v(n), table(m + 1, -1);
    for (auto& x : v) cin >> x, table[x] = 1;

    for (int i = 1; i < m; i++) {
        for (auto x : v) {
            if (i + x > m || table[i] == -1) continue;
            table[i + x] = min_f(table[i + x], table[i] + 1);
        }
    }

    cout << table[m];
}