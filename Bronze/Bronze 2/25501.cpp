#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int i; cin >> i;

    while (i --> 0) {
        string s; cin >> s;

        int i = 0; bool flag = true;
        for (int len = s.size(); i < len / 2; i++) {
            if (s[i] != s[len - i - 1]) { flag = false; break; }
        }

        cout << (flag ? 1 : 0) << " " << i + 1 << "\n";
    }
}