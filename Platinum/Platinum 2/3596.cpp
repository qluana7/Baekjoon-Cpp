#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    vector<int> gv(2001, 0);
    gv[1] = gv[2] = gv[3] = 1; gv[4] = 2;

    vector<bool> chk(2001, false);
    for (int i = 5; i < 2001; i++) {
        chk.assign(2001, false);

        for (int j = i - 5; j < i - 2; j++) chk[gv[j]] = true;

        int k = i - 5;
        for (int j = 0; j <= k / 2; j++) {
            chk[gv[j] ^ gv[k - j]] = true;
        }

        int j = 0;
        for (; j < chk.size(); j++) if (!chk[j]) break;

        gv[i] = j;
    }

    int n; cin >> n;

    cout << (!gv[n] + 1);
}