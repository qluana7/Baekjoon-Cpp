#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> manacher(const string& src) {
    string s = "#";

    for (auto c : src) s += c + (string)"#";

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

    string s; cin >> s;
    vector<int> v = manacher(s);

    cout << *max_element(v.begin(), v.end());
}