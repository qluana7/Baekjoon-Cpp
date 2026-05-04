#include <iostream>
#include <string>
#include <streambuf>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n; cin >> n;

    while (n --> 0) {
        string str; int a, b; cin >> str;
        rope<char> r(str.c_str());

        for (string cmd; cin >> cmd, cmd[0] != 'E';) {
            if (cmd[0] == 'I') {
                cin >> str >> a;

                r.insert(a, str.c_str());
            } else {
                cin >> a >> b;

                copy(r.begin() + a, r.begin() + b + 1, ostreambuf_iterator<char>(cout));
                cout << "\n";
            }
        }
    }
}