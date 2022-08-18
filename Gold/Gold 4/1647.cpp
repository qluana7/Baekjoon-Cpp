#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int start, end;
    
    int cost;
};

int head(vector<int>& v, int idx) {
    if (v[idx] == idx) return idx;
    
    return v[idx] = head(v, v[idx]);
}

int main() {
    int n, m; cin >> n >> m;
    vector<edge> v(m);
    
    for (auto& x : v) cin >> x.start >> x.end >> x.cost;
    
    int t = 0, c = 0;
    vector<int> vertex(n + 1);
    for (int i = 0; i < n + 1; i++) vertex[i] = i;
    
    sort(v.begin(), v.end(), [](const edge& v1, const edge& v2){ return v1.cost < v2.cost; });
    
    for (auto& e : v) {
        if (head(vertex, e.start) == head(vertex, e.end)) continue;
        
        vertex[head(vertex, e.end)] = head(vertex, e.start);
        t += e.cost; c++;
        
        if (c == n - 2) break;
    }
    
    cout << t;
    
    return 0;
}