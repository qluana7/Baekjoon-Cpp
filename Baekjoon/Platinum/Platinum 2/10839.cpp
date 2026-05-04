#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

struct pos_t {
    constexpr pos_t() : pos_t(0, 0, -1) { }
    constexpr pos_t(int a, int b, int i)
        : x(a), y(b), ind(i) { }
    ll x, y;
    int ind;
};

constexpr ll ccw(pos_t s, pos_t a, pos_t b) {
    return 1LL * (a.x - s.x) * (b.y - s.y) - 1LL * (b.x - s.x) * (a.y - s.y);
}

template <typename Iterator>
vector<pos_t> get(Iterator _s, Iterator _e) {
    if (_s == _e) return {};
    if (_s + 1 == _e) return { *_s, *_e };

    vector<pos_t> ret { *_s };

    _s++;
    while (_s != _e) {
        while (ret.size() >= 2 && ccw(ret[ret.size() - 2], ret.back(), *_s) >= 0)
            ret.pop_back();
        ret.push_back(*_s);
        _s++;
    }

    return ret;
}

int main() {
    int n; cin >> n;
    vector<pos_t> _v(n);
    int k = 0; for (auto& x : _v) { cin >> x.x >> x.y; x.ind = k++; }

    int a, b; cin >> a >> b;

    if (a == 0) { _v.push_back(_v.front()); a = _v.size() - 1; }
    if (b == 0) { _v.push_back(_v.front()); b = _v.size() - 1; }

    bool flag = a > b;
    if (flag) swap(a, b);
    
    _v = get(_v.begin() + a, _v.begin() + b + 1);

    vector<int> res(_v.size());
    transform(_v.begin(), _v.end(), res.begin(), [](const pos_t& p) { return p.ind; });

    if (flag) reverse(res.begin(), res.end());

    cout << res.size() << "\n";
    for (auto x : res) cout << x << " ";

    return 0;
}