#include <iostream>

#define ll long long

using namespace std;

struct pos_t {
    ll x, y;
};

inline ll ccw(pos_t s, pos_t a, pos_t b) {
    return 1LL * (a.x - s.x) * (b.y - s.y) - 1LL * (b.x - s.x) * (a.y - s.y);
}

int main() {
    pos_t s, a, b;
    
    cin >> a.x >> a.y
        >> s.x >> s.y
        >> b.x >> b.y;
    
    ll v = ccw(s, a, b);
    
    cout << (v < 0) - (v > 0);
    
    return 0;
}