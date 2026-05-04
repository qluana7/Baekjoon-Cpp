#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, g = 0; cin >> n;
    vector<int> v(n);
    for (auto& x : v) { cin >> x; g^= x; }

    int t = 0;
    for (auto x : v) { if ((g ^ x) < x) t++; }

    cout << t;
}