#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

struct pos_t {
    pos_t() : pos_t(0, 0) { }
    pos_t(int a, int b)
        : x(a), y(b), p(1), q(0) { }
    ll x, y, p, q;
    
    pos_t operator- (pos_t p) { return pos_t(this->x - p.x, this->y - p.y); }
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

inline double dt(pos_t a, pos_t b) {
    ll
        dx = a.x - b.x,
        dy = a.y - b.y;
    
    return sqrt(dx * dx + dy * dy);
}

inline ll dot(pos_t a, pos_t b) {
    return a.x * b.x + a.y * b.y;
}

inline ll cross(pos_t a, pos_t b) {
    return a.x * b.y - b.x * a.y;
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
	
	vector<int> s;
	
	s.push_back(0);
	s.push_back(1);
	
	for(int i = 2; i < n; i++) {
	    while (s.size() >= 2) {
	        int p2 = s.back(); s.pop_back();
	        int p1 = s.back();
	        
	        if (ccw(pt[p1], pt[p2], pt[i]) > 0) {
	            s.push_back(p2);
	            break;
	        }
	    }
	    
	    s.push_back(i);
	}
    
    int mxx = 0, mnx = 0;
    
    for (int i = 0; i <s.size(); i++) {
        if (pt[s[mnx]].x > pt[s[i]].x) mnx = i;
        if (pt[s[mxx]].x < pt[s[i]].x) mxx = i;
    }
    
    double r = dt(pt[s[mnx]], pt[s[mxx]]);
    
    for (int i = 0; i < s.size(); i++) {
        if (cross(pt[s[(mnx + 1) % s.size()]] - pt[s[mnx]], pt[s[mxx]] - pt[s[(mxx + 1) % s.size()]]) > 0)
            mnx = (mnx + 1) % s.size();
        else mxx = (mxx + 1) % s.size();
        
        r = fmax(r, dt(pt[s[mnx]], pt[s[mxx]]));
    }
    
    cout.precision(15);
    cout << r;

	return 0;
}