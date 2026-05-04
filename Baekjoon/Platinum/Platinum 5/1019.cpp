#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void add(vector<ll>& v, ll n, ll t) {
    while (n) {
        v[n % 10] += t; n /= 10;
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    ll a = 1, b, t = 1; cin >> b;
    vector<ll> v(10);

    for (;; a /= 10, b /= 10, t *= 10) {
        while (a % 10 != 0 && a <= b) { add(v, a, t); a++; }
        if (a > b) break;
        while (b % 10 != 9 && a <= b) { add(v, b, t); b--; }

        for (int i = 0; i < 10; i++) v[i] += (b / 10 - a / 10 + 1) * t;
    }

    for (auto x : v) cout << x << " ";
}