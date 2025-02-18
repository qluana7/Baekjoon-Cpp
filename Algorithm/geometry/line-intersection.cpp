/*

*/

#include <utility>

#define i64 long long

using namespace std;

struct pos_t {
    constexpr pos_t() : pos_t(0, 0) { }
    constexpr pos_t(i64 a, i64 b)
        : x(a), y(b) { }
    i64 x, y;
    
    constexpr bool cmp(pos_t pt) {
        if (this->x == pt.x) return this->y <= pt.y;
        else return this->x <= pt.x;
    }
};

constexpr i64 ccw(pos_t s, pos_t a, pos_t b) {
    return 1LL * (a.x - s.x) * (b.y - s.y) - 1LL * (b.x - s.x) * (a.y - s.y);
}

constexpr int zip(i64 res) { return res < 0 ? -1 : !!res; }

constexpr bool is_intersection(pos_t a, pos_t b, pos_t x, pos_t y) {
    int p = zip(ccw(y, x, a)) * zip(ccw(y, x, b)),
        q = zip(ccw(a, b, y)) * zip(ccw(a, b, x));
    
    if (!p & !q) {
        if (!a.cmp(b)) swap(a, b);
        if (!x.cmp(y)) swap(x, y);

        return a.cmp(y) && x.cmp(b);
    }

    return p <= 0 && q <= 0;
}