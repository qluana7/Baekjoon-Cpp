#include <iostream>
#include <string>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(int n) {

    unordered_map<string, int> v;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        v[str] = i;
    }

    ordered_set os;

    long long t = 0; string str; cin >> str;
    os.insert(v[str]);
    while (n --> 1) {
        cin >> str; int x = v[str];
        os.insert(x);
        t += os.size() - os.order_of_key(x + 1);
    }

    cout << t << "\n";
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n, n) solve(n);
}