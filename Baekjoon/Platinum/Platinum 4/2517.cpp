#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n; cin >> n;
    ordered_set s;
    while (n --> 0) {
        int k; cin >> k;
        s.insert(k);

        cout << s.order_of_key(k) + 1 << "\n";
    }
}