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
};

inline ll ccw(pos_t s, pos_t a, pos_t b) {
    return 1LL * (a.x - s.x) * (b.y - s.y) - 1LL * (b.x - s.x) * (a.y - s.y);
}

bool cmp(const pos_t& p1, const pos_t& p2) {
    if(1LL * p1.p * p2.q != 1LL * p2.p * p1.q)
        return 1LL * p1.p * p2.q > 1LL * p2.p * p1.q;
    if (p1.y != p2.y) return p1.y < p2.y;
    return p1.x < p2.x;
}

int main()
{
	int n; cin >> n;
	vector<pos_t> pt(n);
	
	for(auto& p : pt) cin >> p.x >> p.y;
	
	sort(pt.begin(), pt.end(), cmp);
	
	for (int i = 1; i < pt.size(); i++) {
	    pt[i].p = pt[i].x - pt[0].x;
	    pt[i].q = pt[i].y - pt[0].y;
	}
	
	sort(pt.begin() + 1, pt.end(), cmp);
	
	stack<int> s;
	
	s.push(0);
	s.push(1);
	
	for(int i = 2; i < n; i++) {
	    while (s.size() >= 2) {
	        int p2 = s.top(); s.pop();
	        int p1 = s.top();
	        
	        if (ccw(pt[p1], pt[p2], pt[i]) > 0) {
	            s.push(p2);
	            break;
	        }
	    }
	    
	    s.push(i);
	}
	
    ll w = 0;
	
	pos_t p = pt[s.top()]; s.pop();
	pos_t prev = pt[s.top()]; s.pop();
	prev.x -= p.x; prev.y -= p.y;
	
	while (!s.empty()) {
	    pos_t m = pt[s.top()]; s.pop();
	    m.x -= p.x; m.y -= p.y;
	    
	    w += prev.x * m.y - prev.y * m.x;
	    
	    prev = m;
	}
	
	cout << llabs(w) / 100;
	
	return 0;
}