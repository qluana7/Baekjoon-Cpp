#include <iostream>
#include <string>
#include <algorithm>

#define u64 unsigned long long

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    string a, b; cin >> a >> b;

    int l = 0, r = b.size() - 1;
    bool flag = false;

    for (int i = a.size(); i < b.size(); i++) {
        if (flag)
            flag ^= b[l] == 'B', ++l;
        else
            flag ^= b[r] == 'B', --r;
    }

    string s(b.begin() + l, b.begin() + r + 1);
    if (flag) reverse(s.begin(), s.end());

    cout << (a == s);
}