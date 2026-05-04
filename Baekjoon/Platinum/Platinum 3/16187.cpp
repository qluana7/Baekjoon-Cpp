#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    vector<int> gv(5001, 0);
    gv[2] = gv[3] = 1;
    vector<bool> chk(5001, false);

    for (int i = 4; i < 5001; i++) {
        chk.assign(5001, false);

        int k = i - 2;
        for (int j = 0; j <= k / 2; j++) {
            chk[gv[j] ^ gv[k - j]] = true;
        }

        int j = 0;
        for (; j < chk.size(); j++) if (!chk[j]) break;

        gv[i] = j;
    }

    int t; cin >> t;
    while (t --> 0) {
        int n; cin >> n;

        cout << vector<char*> { "First", "Second" }[!gv[n]] << "\n";
    }
}