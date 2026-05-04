#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    int g = 0;

    while (n --> 0) { int x; cin >> x; g ^= x; }

    cout << (g == 0 ? "cubelover" : "koosaga");
}