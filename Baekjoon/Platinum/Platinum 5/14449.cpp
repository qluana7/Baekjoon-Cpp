#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n, t = 0; cin >> n;
    vector<int> v(n), a(n), b(n);
    for (auto& x : v) cin >> x;
    ordered_set s1, s2;

    for (int i = 0, j = n - 1; i < n; i++, j--) {
        s1.insert(v[i]); s2.insert(v[j]);

        a[i] = s1.order_of_key(v[i]);
        b[j] = s2.order_of_key(v[j]);
    }

    for (int i = 0; i < n; i++)
        t += min(a[i], b[i]) * 2 < max(a[i], b[i]);

    cout << t;
}