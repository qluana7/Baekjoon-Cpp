#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

struct pos_t {
    pos_t() : pos_t(0, 0) { }
    pos_t(int a, int b)
        : x(a), y(b), p(1), q(0) { }
    int x, y, p, q;
};

inline int ccw(pos_t s, pos_t a, pos_t b) {
    return 1LL * (a.x - s.x) * (b.y - s.y) - 1LL * (b.x - s.x) * (a.y - s.y);
}

bool cmp(const pos_t& p1, const pos_t& p2) {
    if(1LL * p1.p * p2.q != 1LL * p2.p * p1.q)
        return 1LL * p1.p * p2.q > 1LL * p2.p * p1.q;
    if (p1.y != p2.y) return p1.y < p2.y;
    return p1.x < p2.x;
}

inline double dt(pos_t a, pos_t b) {
    int
        dx = a.x - b.x,
        dy = a.y - b.y;
    
    return sqrt(dx * dx + dy * dy);
}

inline double len_sq(pos_t a) {
    return a.x * a.x + a.y * a.y;
}

inline double dot(pos_t a, pos_t b) {
    return a.x * b.x + a.y * b.y;
}

inline double angle(pos_t s, pos_t a, pos_t b) {
    a.x -= s.x; a.y -= s.y;
    b.x -= s.x; b.y -= s.y;
    
    double dt = sqrt(len_sq(a) * len_sq(b));
    
    return acos(dot(a, b) / dt);
}

int main()
{
	int n, l; cin >> n >> l;
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
    
    double w = 0;
    
    int a = s.top(); s.pop();
    int st = a;
    int nt = s.top();
    
    while (!s.empty()) {
        int b = s.top(); s.pop();
        
        w += dt(pt[a], pt[b]);
        int nx = s.empty() ? st : s.top();
        w += (M_PI - angle(pt[b], pt[a], pt[nx])) * l;
        a = b;
    }
    w += dt(pt[a], pt[st]);
    w += (M_PI - angle(pt[st], pt[a], pt[nt])) * l;
    
    cout.precision(16);
    cout << w;

	return 0;
}