#include <iostream>
#include <string>
#include <streambuf>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int m; cin >> m;
    string str; cin >> str;
    rope<char> r(str.c_str());

    int n; cin >> n;
    while (n --> 0) {
        int a, b, c; cin >> a >> b >> c;
        r.insert(c, r.begin() + a, r.begin() + b);
        if (r.size() > m) r.erase(r.mutable_begin() + m, r.mutable_end());
    }

    copy(r.begin(), r.end(), ostreambuf_iterator<char>(cout));
}