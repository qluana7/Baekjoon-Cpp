#include <iostream>
#include <string>
#include <streambuf>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n; cin >> n >> n;
    string str; cin >> str;
    rope<char> r(str.c_str());

    while (n --> 0) {
        int x, a, b; char c; cin >> x;

        if (x == 1) {
            cin >> c >> a;
            r.insert(a - 1, c);
        } else {
            cin >> a >> b;
            copy(r.begin() + a - 1, r.begin() + b, ostreambuf_iterator<char>(cout));
            cout << "\n";
            r.erase(a - 1, b - a + 1);
        }
    }
}