#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> manacher(const vector<int>& src) {
    vector<int> s { -1 };

    for (auto c : src) { s.push_back(c); s.push_back(-1); }

    int r = 0, t = 0, n = s.size();
    vector<int> ret(n);

    for (int i = 0; i < n; i++) {
        if (i <= r) ret[i] = min(ret[(t << 1) - i], r - i);
        else        ret[i] = 0;

        while (
            i - ret[i] - 1 >= 0 && i + ret[i] + 1 < n &&
            s[i - ret[i] - 1] == s[i + ret[i] + 1]
            ) ret[i]++;

        if (i + ret[i] > r) { r = i + ret[i]; t = i; }
    }

    return ret;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n; cin >> n;

    vector<int> s(n);
    for (auto& x : s) cin >> x;

    vector<int> v = manacher(s);

    cin >> n;
    while (n --> 0) {
        int a, b; cin >> a >> b;
        cout << (v[a + b - 1] >= b - a + 1) << "\n";
    }
}