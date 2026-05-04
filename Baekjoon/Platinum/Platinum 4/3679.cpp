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

bool cmp(const pair<pos_t, int>& pp1, const pair<pos_t, int>& pp2) {
    auto p1 = pp1.first, p2 = pp2.first;
    if(1LL * p1.p * p2.q != 1LL * p2.p * p1.q)
        return 1LL * p1.p * p2.q > 1LL * p2.p * p1.q;
    if (p1.y != p2.y) return p1.y < p2.y;
    return p1.x < p2.x;
}

void get()
{
	int n; cin >> n;
	vector<pair<pos_t, int>> pt(n);
	
    int x = 0;
	for(auto& p : pt) { cin >> p.first.x >> p.first.y; p.second = x; x++; }
	
	sort(pt.begin(), pt.end(), cmp);
	
	for (int i = 1; i < pt.size(); i++) {
	    pt[i].first.p = pt[i].first.x - pt[0].first.x;
	    pt[i].first.q = pt[i].first.y - pt[0].first.y;
	}
	
	sort(pt.begin() + 1, pt.end(), cmp);
    
    vector<int> tmp;
    
    for (int i = 0; i < n; i++) {
        tmp.push_back(i);
        
        if (ccw(pt[i].first, pt[(i + 1) % n].first, pt[(i + 2) % n].first) != 0) {
            if (i == n - 1) break;
            for (auto z : tmp) cout << pt[z].second << " ";
            tmp.clear();
        }
    } for (auto st = tmp.rbegin(); st != tmp.rend(); st++) cout << pt[*st].second << " ";
    
    cout << "\n";
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    for (;n--;) get();
    
    return 0;
}