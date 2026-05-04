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

inline int nor(ll n) { return n < 0 ? -1 : 1; }

bool cmp(const pos_t& p1, const pos_t& p2) {
    if(1LL * p1.p * p2.q != 1LL * p2.p * p1.q)
        return 1LL * p1.p * p2.q > 1LL * p2.p * p1.q;
    if (p1.y != p2.y) return p1.y < p2.y;
    return p1.x < p2.x;
}

stack<int> cvh(vector<pos_t>& pt) {
    sort(pt.begin(), pt.end(), cmp);
	
	for (int i = 1; i < pt.size(); i++) {
	    pt[i].p = pt[i].x - pt[0].x;
	    pt[i].q = pt[i].y - pt[0].y;
	}
	
	sort(pt.begin() + 1, pt.end(), cmp);
	
	stack<int> s;
	
	s.push(0);
	s.push(1);
	
	for(int i = 2; i < pt.size(); i++) {
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
    
    return s;
}

int main()
{
	int n; cin >> n;
	vector<pos_t> pt(n);
    
    pos_t sdp; cin >> sdp.x >> sdp.y;
	
	for(auto& p : pt) cin >> p.x >> p.y;
    
    int t = 0; bool done = false;
    
    for (; !done; t++) {
        if (pt.size() < 3) break;
        
        auto s = cvh(pt);
        int a = s.top(); s.pop();
        while (!s.empty()) {
            int b = s.top(); s.pop();
            
            if (ccw(sdp, pt[a], pt[b]) > 0) { done = true; break; }
            pt.erase(pt.begin() + a);
            
            a = b;
        }
        
        if (done) break;
        
        pt.erase(pt.begin() + a);
    }
    
    cout << t;

	return 0;
}