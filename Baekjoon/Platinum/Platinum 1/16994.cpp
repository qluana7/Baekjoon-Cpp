#include <iostream>
#include <string>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    string str; cin >> str;
    rope<char> r(str.c_str());

    int n; cin >> n;
    while (n --> 0) {
        int x, a, b; cin >> x;
        if (x == 1 || x == 2) cin >> a >> b;
        else cin >> a;

        switch (x) {
            case 1:
                x = b - a + 1;
                r.insert(0, r.begin() + a, r.begin() + b + 1);
                r.erase(a + x, b - a + 1);
                break;
            case 2:
                r.append(r.begin() + a, r.begin() + b + 1);
                r.erase(a, b - a + 1);
                break;
            case 3:
                cout << r[a] << "\n";
                break;
        }
    }
}