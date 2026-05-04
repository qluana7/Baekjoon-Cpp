#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

struct pos_t {
    pos_t() : pos_t(0, 0, -1) { }
    pos_t(int a, int b, int i)
        : x(a), y(b), ind(i) { }
    ll x, y; int ind;
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
        while (top.size() >= 2 && ccw(top[top.size() - 2], top[top.size() - 1], *b) > 0) top.pop_back();

        top.push_back(*b);
    }

    for (auto b = arr.rbegin(), e = arr.rend(); b != e; b++) {
        while (bottom.size() >= 2 && ccw(bottom[bottom.size() - 2], bottom[bottom.size() - 1], *b) > 0) bottom.pop_back();

        bottom.push_back(*b);
    }

    top.pop_back();
    top.insert(top.end(), bottom.begin(), bottom.end() - 1);

    return top;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<pos_t> v(n);
    int i = 1; for (auto& x : v) { cin >> x.x >> x.y; x.ind = i++; }

    v = cvh(v.begin(), v.end());
    sort(v.begin(), v.end(), [](const pos_t& a, const pos_t& b) { return a.ind < b.ind; });
    v.erase(unique(v.begin(), v.end(), [](const pos_t& a, const pos_t& b){ return a.ind == b.ind; }), v.end());

    for (auto [_1, _2, x] : v) cout << x << " ";
}