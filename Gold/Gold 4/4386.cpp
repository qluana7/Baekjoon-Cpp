#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define pdd pair<double, double>

using namespace std;

struct edge {
    int start, end;
    
    double cost;
};

int head(vector<int>& v, int idx) {
    if (v[idx] == idx) return idx;
    
    return v[idx] = head(v, v[idx]);
}

double cost(pdd a, pdd b) {
    double dx = a.first - b.first, dy = a.second - b.second;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    int n; cin >> n;
    vector<pdd> vtx(n);
    vector<edge> v;
    
    for (auto& x : vtx) cin >> x.first >> x.second;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            v.push_back({i, j, cost(vtx[i], vtx[j])});
        }
    }
    
    double t = 0; int c = 0;
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