#include <iostream>
#include <string>
#include <cmath>

#define isNum(c) ('0' <= (c) && (c) <= '9')

using namespace std;

void solve() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n = 0, i = 0; string s; cin >> s;
    long long x = 0, y = 0;

    for (; i < s.size(); i++) {
        while (isNum(s[i]) || s[i] == 'x') i++;
        string str = string(s.begin() + n, s.begin() + i);
        bool flag = str.back() == 'x'; if (flag) str.pop_back();
        if (str == "-" || str == "+" || str == "") str.push_back('1');
        long long k = stoll(str);

        if (flag) x += k; else y += k;

        n = i;

        if (s[i] == '=') break;
    }

    for (n++, i++; i < s.size(); i++) {
        while (isNum(s[i]) || s[i] == 'x') i++;
        string str = string(s.begin() + n, s.begin() + i);
        bool flag = str.back() == 'x'; if (flag) str.pop_back();
        if (str == "-" || str == "+" || str == "") str.push_back('1');
        long long k = stoll(str);

        if (flag) x -= k; else y -= k;

        n = i;
    } x = -x;
    
    if (x == 0) cout << (y ? "IMPOSSIBLE\n" : "IDENTITY\n");
    else cout << floor(y * 1.0 / x) << "\n";
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n; cin >> n;

    while (n --> 0) solve();
}