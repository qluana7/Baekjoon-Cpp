#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, t = 0; cin >> n;
    while (n --> 0) {
        int x; cin >> x;

        if (x == 0 || x == 2) continue;

        t ^= (x / 2) + (x % 2 == 0 ? -1 : 1);
    }

    cout << (t ? "koosaga" : "cubelover");
}