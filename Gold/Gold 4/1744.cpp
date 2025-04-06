#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    bool z = false;
    vector<int> pv, nv;
    int s = 0;

    while (n --> 0) {
        int k; cin >> k;

        if (k == 1) s++;
        else if (k > 0) pv.push_back(k);
        else if (k < 0) nv.push_back(k);
        else z = true;
    }

    sort(pv.begin(), pv.end());
    sort(nv.begin(), nv.end(), greater<int>{});


    while (pv.size() >= 2) {
        s += pv[pv.size() - 1] * pv[pv.size() - 2];
        pv.pop_back(); pv.pop_back();
    } if (pv.size() == 1) s += pv.back();

    while (nv.size() >= 2) {
        s += nv[nv.size() - 1] * nv[nv.size() - 2];
        nv.pop_back(); nv.pop_back();
    } if (nv.size() == 1 && !z) s += nv.back();

    cout << s;
}