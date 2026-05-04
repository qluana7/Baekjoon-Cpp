#include <iostream>

#define ll long long

using namespace std;

struct pos_t {
    pos_t() : pos_t(0, 0) { }
    pos_t(ll a, ll b)
        : x(a), y(b) { }
    ll x, y;
    
    bool cmp(pos_t pt) {
        if (this->x == pt.x) return this->y <= pt.y;
        else return this->x <= pt.x;
    }
};

inline int ccw(pos_t s, pos_t a, pos_t b) {
    ll res = (a.x - s.x) * (b.y - s.y) - (b.x - s.x) * (a.y - s.y);
    
    return res > 0 ? 1 : res < 0 ? -1 : 0;
}

/*

x1    x2
  \  /
   \/
   /\
  /  \
y2    y1

x1 -- y1  x2 -- y2

*/

int main() {
    pos_t x1, y1, x2, y2;
    cin >> x1.x >> x1.y
        >> y1.x >> y1.y
        >> x2.x >> x2.y
        >> y2.x >> y2.y;
    
    int a = ccw(y2, x2, x1) * ccw(y2, x2, y1), b = ccw(x1, y1, y2) * ccw(x1, y1, x2);
    
    if (a == 0 && b == 0) {
        if (!x1.cmp(y1)) swap(x1, y1);
        if (!x2.cmp(y2)) swap(x2, y2);
        
        #ifndef ONLINE_JUDGE
        cout << x1.x << " " << x1.y << "\n"
             << y1.x << " " << y1.y << "\n"
             << x2.x << " " << x2.y << "\n"
             << y2.x << " " << y2.y << "\n";
        #endif
        
        cout << (x1.cmp(y2) && x2.cmp(y1));
    } else {
        cout << (a <= 0 && b <= 0);
    }
    
    return 0;
}