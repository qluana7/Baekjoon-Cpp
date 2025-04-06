#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")

#include <iostream>
#include <vector>

#define i64 long long

using namespace std;

i64 divmod(i64& a, i64 b) {
    i64 k = a % b;

    if (b > 0) return a /= b, k;

    a /= b;

    if (k < 0) a += 1, k += abs(b);
    
    return k;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    i64 n, m; cin >> n >> m;
    vector<int> v;

    if (!n) return !(cout << 0);
    if (n < 0 && m > 0) cout << "-";

    while (n)
        v.push_back(divmod(n, m));
    
    for (int i = v.size() - 1; i >= 0; i--)
        cout << abs(v[i]);
}