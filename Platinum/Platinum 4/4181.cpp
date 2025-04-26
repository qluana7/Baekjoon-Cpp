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
    if (p1.x != p2.x) return p1.x < p2.x;
    return p1.y < p2.y;
}

int main()
{
	int n; cin >> n;
	vector<pos_t> pt;
	
	for(int x = n; x--;) {
        pos_t p; char c;
        cin >> p.x >> p.y >> c;
        
        if (c == 'Y') pt.push_back(p);
    } n = pt.size();
	
	sort(pt.begin(), pt.end(), cmp);
	
	for (int i = 1; i < pt.size(); i++) {
	    pt[i].p = pt[i].x - pt[0].x;
	    pt[i].q = pt[i].y - pt[0].y;
	}
	
	sort(pt.begin() + 1, pt.end(), cmp);
    
    cout << pt.size() << "\n";
    
    vector<int> tmp;
    
    for (int i = 0; i < n; i++) {
        tmp.push_back(i);
        
        if (ccw(pt[i], pt[(i + 1) % n], pt[(i + 2) % n]) != 0) {
            if (i == n - 1) break;
            for (auto z : tmp) cout << pt[z].x << " " << pt[z].y << "\n";
            tmp.clear();
        }
    } for (auto st = tmp.rbegin(); st != tmp.rend(); st++) cout << pt[*st].x << " " << pt[*st].y << "\n";
    
    cout << "\n";

	return 0;
}