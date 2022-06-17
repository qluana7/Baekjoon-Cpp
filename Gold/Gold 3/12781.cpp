#include <iostream>

#define ll long long

using namespace std;

struct pos_t {
    pos_t() : pos_t(0, 0) { }
    pos_t(int a, int b)
        : x(a), y(b), p(1), q(0) { }
    ll x, y, p, q;
};

inline int ccw(pos_t s, pos_t a, pos_t b) {
    ll res = 1LL * (a.x - s.x) * (b.y - s.y) - 1LL * (b.x - s.x) * (a.y - s.y);
    
    return res > 0 ? 1 : res < 0 ? -1 : 0;
}

int main() {
    pos_t x1, y1, x2, y2;
    cin >> x1.x >> x1.y
        >> y1.x >> y1.y
        >> x2.x >> x2.y
        >> y2.x >> y2.y;
    
    cout << (ccw(y2, x1, x2) * ccw(y2, y1, x2) < 0 && ccw(x1, x2, y1) * ccw(x1, y2, y1) < 0);
    
    return 0;
}