#include <iostream>
#include <string>
#include <vector>

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
    string s; cin >> s;

    vector<int> v = manacher(s);

    int c = 0, t = 1;
    auto b = v.begin() + 1;
    
    for (int i = 0; i < v.size() / 2; b++, t++, i++) {
        if (*b == t) c = t;
    }

    cout << s.size() * 2 - c;
}