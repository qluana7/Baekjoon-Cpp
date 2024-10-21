#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>

#define type_t double

using namespace std;

struct pos_t {
    pos_t() : pos_t(0, 0) { }
    pos_t(type_t a, type_t b)
        : x(a), y(b) { }
    type_t x, y;

    bool operator<(const pos_t p) const {
        if (this->x != p.x) return this->x < p.x;
        else return this->y < p.y;
    }
};

inline type_t ccw(pos_t s, pos_t a, pos_t b) {
    return (a.x - s.x) * (b.y - s.y) - (b.x - s.x) * (a.y - s.y);
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

double area(const vector<pos_t>& v) {
    double t = 0;

    for (int i = 0; i < v.size(); i++) {
        pos_t a = v[i], b = v[(i + 1) % v.size()];
        t += (a.x * b.y - a.y * b.x);
    }

    return abs(t) / 2;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.precision(4);

    string s; int n;

    while (cin >> s >> n, s != "ZZ") {
        set<pos_t> st;
        for (int i = 0; i < n; i++) {
            double a, b; cin >> a >> b;
            st.emplace(a, b);
        }

        vector<pos_t> v1 = cvh(st.begin(), st.end()), v2;

        for (auto x : v1) st.erase(x);

        v2 = cvh(st.begin(), st.end());

        cout << "ProblemID " << s << ": " << fixed << area(v1) - area(v2) << "\n";
    }
}