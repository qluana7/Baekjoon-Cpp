#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    int m; cin >> m;

    while (m --> 0) {
        int k, a, b, c; cin >> k;

        if (k == 2) {
            cin >> a >> b >> c; k = 0;

            for (; a <= b; a++)
                k += v[a] > c;
            
            cout << k << "\n";
        } else {
            cin >> a >> b;
            v[a] = b;
        }
    }
}