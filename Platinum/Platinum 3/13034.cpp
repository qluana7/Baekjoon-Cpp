#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    vector<int> gv(1001, 0);
    gv[2] = gv[3] = 1;

    vector<bool> chk(1001, false);
    for (int i = 4; i < 1001; i++) {
        chk.assign(1001, false);

        int k = i - 2;
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