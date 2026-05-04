#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos3 {
    int x, y, z;
};

struct edge {
    int start, end;
    
    int cost;
};

inline int cost(const pos3& p1, const pos3& p2) {
    return min(abs(p1.x - p2.x), min(abs(p1.y - p2.y), abs(p1.z - p2.z)));
}

int head(vector<int>& v, int idx) {
    if (v[idx] == idx) return idx;
    
    return v[idx] = head(v, v[idx]);
}

int main() {
    int n; cin >> n;
    vector<pos3> ptss(n);
    vector<pair<int, pos3>> pts(n);
    vector<edge> v;
    
    for (int i = 0; i < n; i++){
        auto& x = pts[i];
        cin >> x.second.x >> x.second.y >> x.second.z;
        ptss[i] = x.second;
        
        x.first = i;
    }
    
    sort(pts.begin(), pts.end(), [](const auto& a, const auto& b){ return a.second.x < b.second.x; });
    
    for (int i = 0; i < n - 1; i++)
        for (int j = 1; j < 3; j++) {
            if (i + j >= n) break;
            v.push_back({pts[i].first, pts[i + j].first, cost(ptss[pts[i].first], ptss[pts[i + j].first])});
        }
    
    sort(pts.begin(), pts.end(), [](const auto& a, const auto& b){ return a.second.y < b.second.y; });
    
    for (int i = 0; i < n - 1; i++)
        for (int j = 1; j < 3; j++) {
            if (i + j >= n) break;
            v.push_back({pts[i].first, pts[i + j].first, cost(ptss[pts[i].first], ptss[pts[i + j].first])});
        }
    
    sort(pts.begin(), pts.end(), [](const auto& a, const auto& b){ return a.second.z < b.second.z; });
    
    for (int i = 0; i < n - 1; i++)
        for (int j = 1; j < 3; j++) {
            if (i + j >= n) break;
            v.push_back({pts[i].first, pts[i + j].first, cost(ptss[pts[i].first], ptss[pts[i + j].first])});
        }
    
    int t = 0, c = 0;
    vector<int> vertex(n + 1);
    for (int i = 0; i < n + 1; i++) vertex[i] = i;
    
    sort(v.begin(), v.end(), [](const edge& v1, const edge& v2){ return v1.cost < v2.cost; });
    
    for (auto& e : v) {
        if (head(vertex, e.start) == head(vertex, e.end)) continue;
        
        vertex[head(vertex, e.end)] = head(vertex, e.start);
        t += e.cost; c++;
        
        if (c == n - 1) break;
    }
    
    cout << t;
    
    return 0;
}