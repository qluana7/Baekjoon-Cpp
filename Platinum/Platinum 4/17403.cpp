#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define ll long long

using namespace std;

struct pos_t {
    pos_t() : pos_t(0, 0) { }
    pos_t(int a, int b)
        : x(a), y(b), p(1), q(0) { }
    ll x, y, p, q;
    int ind;
};

inline ll ccw(pos_t s, pos_t a, pos_t b) {
    return 1LL * (a.x - s.x) * (b.y - s.y) - 1LL * (b.x - s.x) * (a.y - s.y);
}

bool cmp(const pair<pos_t, int>& pp1, const pair<pos_t, int>& pp2) {
    auto p1 = pp1.first, p2 = pp2.first;
    if(1LL * p1.p * p2.q != 1LL * p2.p * p1.q)
        return 1LL * p1.p * p2.q > 1LL * p2.p * p1.q;
    if (p1.y != p2.y) return p1.y < p2.y;
    return p1.x < p2.x;
}

int n;

int get(vector<pair<pos_t, int>>& pts, int dep)
{
    vector<pair<pos_t, int>> pt;
    
    for (const auto& x : pts) if (x.second == 0) pt.push_back(x);
    
    if (pt.size() < 3) return 0;
    
	sort(pt.begin(), pt.end(), cmp);
	
	for (int i = 1; i < pt.size(); i++) {
	    pt[i].first.p = pt[i].first.x - pt[0].first.x;
	    pt[i].first.q = pt[i].first.y - pt[0].first.y;
	}
	
	sort(pt.begin() + 1, pt.end(), cmp);
	
	stack<int> s;
	
	s.push(0);
	s.push(1);
	
	for(int i = 2; i < pt.size(); i++) {
	    while (s.size() >= 2) {
	        int p2 = s.top(); s.pop();
	        int p1 = s.top();
	        
	        if (ccw(pt[p1].first, pt[p2].first, pt[i].first) > 0) {
	            s.push(p2);
	            break;
	        }
	    }
	    
	    s.push(i);
	}
    
    if (s.size() == 2) return 0;
	
    int sz = s.size();
    while (!s.empty()) { pts[pt[s.top()].first.ind].second = dep; s.pop(); }
    return sz;
}

int main() {
    int dep = 1; cin >> n;
    vector<pair<pos_t, int>> pt;
    
    for(int i = 0; i < n; i++) {
        pos_t p;
        cin >> p.x >> p.y; p.ind = i;
        pt.push_back({p, 0});
    }
    
    while (get(pt, dep)) dep++;
    
    for (const auto& p : pt) cout << p.second << " ";
    
    return 0;
}