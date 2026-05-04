#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

struct pos_t {
    pos_t() : pos_t(0, 0) { }
    pos_t(int a, int b)
        : x(a), y(b), p(1), q(0) { }
    ll x, y, p, q;
};

inline ll ccw(pos_t s, pos_t a, pos_t b) {
    return 1LL * (a.x - s.x) * (b.y - s.y) - 1LL * (b.x - s.x) * (a.y - s.y);
}

template<typename ForwardIterator>
vector<pos_t> cvh_mc(ForwardIterator _s, ForwardIterator _e) {
    vector<pos_t> arr(_s, _e);

    sort(arr.begin(), arr.end(), [](const pos_t& p1, const pos_t& p2) {
        if (p1.x != p2.x) return p1.x < p2.x;
        else return p1.y < p2.y;
    });

    vector<pos_t> top, bottom;
    
    for (auto b = arr.begin(), e = arr.end(); b != e; b++) {
        while (top.size() >= 2 && ccw(top[top.size() - 2], top[top.size() - 1], *b) >= 0) top.pop_back();

        top.push_back(*b);
    }

    for (auto b = arr.rbegin(), e = arr.rend(); b != e; b++) {
        while (bottom.size() >= 2 && ccw(bottom[bottom.size() - 2], bottom[bottom.size() - 1], *b) >= 0) bottom.pop_back();

        bottom.push_back(*b);
    }

    top.pop_back();
    top.insert(top.end(), bottom.begin(), bottom.end() - 1);

    return top;
}

double distance(pos_t a, pos_t b, pos_t k) {
    if (a.x == b.x) { return abs(a.x - k.x); }
    if (a.y == b.y) { return abs(a.y - k.y); }

    double t1 = (double)(b.y - a.y) / (b.x - a.x), t2 = -1, t3 = -t1 * a.x + a.y;
    return abs(t1 * k.x + t2 * k.y + t3) / sqrt(t1*t1 + t2*t2);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.precision(2);
    
    int n;
    for (int t = 1; cin >> n, n; t++) {

        if (n == 0) return 0;

        vector<pos_t> v(n);
        for (auto& x : v) cin >> x.x >> x.y;

        vector<pos_t> cv = cvh_mc(v.begin(), v.end());

        double mn = numeric_limits<double>::max();
        for (int i = 0; i < cv.size(); i++) {
            double mx = 0;
            pos_t a = cv[i], b = cv[(i + 1) % cv.size()];

            for (int j = 0; j < cv.size() - 2; j++) {
                pos_t k = cv[(j + i + 2) % cv.size()];

                mx = max(mx, distance(a, b, k));
            }

            mn = min(mn, mx);
        }

        cout << "Case " << t << ": " << fixed << ceil(mn * 100) / 100 << "\n";
    }
}