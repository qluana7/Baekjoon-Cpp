#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    vector<int> fb(32);
    fb[0] = 1; fb[1] = 2;
    for (int i = 2; i < 32; i++)
        fb[i] = fb[i - 1] + fb[i - 2];

    vector<int> gv(3000001);
    vector<bool> chk(32, false);
    for (int i = 1; i <= 3000001; i++) {
        chk.assign(32, false);

        for (auto x : fb) {
            if (x > i) break;

            chk[gv[i - x]] = true;
        }

        int j = 0;
        for (; j < chk.size(); j++) if (!chk[j]) break;

        gv[i] = j;
    }

    int n; cin >> n;
    int t = 0;
    while (n --> 0) { int x; cin >> x; t ^= gv[x]; }
    cout << (t ? "koosaga" : "cubelover");
}