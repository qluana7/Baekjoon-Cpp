#include <iostream>

using namespace std;

int main() {
    long long n, m, d = 0; cin >> n >> m;

    while (n --> 0) {
        long long t = 0;
        for (int i = 0; i < m; i++) {
            long long x; cin >> x;

            t += x;
        }

        d ^= t;
    }

    cout << (d ? "august14" : "ainta");
}