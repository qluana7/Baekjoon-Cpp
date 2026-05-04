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
        : x(a), y(b) { }
    ll x, y;
};

inline ll ccw(pos_t s, pos_t a, pos_t b) {
    return 1LL * (a.x - s.x) * (b.y - s.y) - 1LL * (b.x - s.x) * (a.y - s.y);
}

template<typename ForwardIterator>
vector<pos_t> cvh(ForwardIterator _s, ForwardIterator _e) {
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

inline double distance(pos_t a, pos_t b) {
    ll x = a.x - b.x, y = a.y - b.y;
    return sqrt(x*x + y*y);
}

void solve() {
    int n; cin >> n;
    vector<pos_t> v(n);
    for (auto& x : v) cin >> x.x >> x.y;

    v = cvh(v.begin(), v.end());

    double r = 0;

    for (int i = 0; i < v.size(); i++)
        r += distance(v[i], v[(i + 1) % v.size()]);
    
    cout << fixed << r << "\n";
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.precision(2);
    
    int n; cin >> n;

    while (n --> 0) solve();
}