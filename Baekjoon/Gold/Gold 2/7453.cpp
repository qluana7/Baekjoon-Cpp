#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> a(n), b(n), c(n), d(n);

    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<int> v(n * n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            v[i * n + j] = c[i] + d[j];
    
    sort(v.begin(), v.end());

    long long ct = 0;
    for (int i = 0; i < n; i++) {
        int k = a[i];
        for (int j = 0; j < n; j++) {
            int p = -(k + b[j]);
            ct +=
                upper_bound(v.begin(), v.end(), p) -
                lower_bound(v.begin(), v.end(), p);
        }
    }

    cout << ct;
}