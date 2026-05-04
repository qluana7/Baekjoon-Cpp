#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n;
    while (cin >> n, n) {
        int g = 0;
        vector<int> v(n);
        for (auto& x : v) { cin >> x; g^= x; }

        int t = 0;
        for (auto x : v) { if ((g ^ x) < x) t++; }

        cout << t << "\n";
    }
}