#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> topology_sort(int vertex_count, const vector<pair<int, int>>& edges) {
    vector<int> out;
    
    vector<int> vertex(vertex_count + 1);
    vector<vector<int>> edge(vertex_count + 1);
    
    for (auto& x : edges) {
        vertex[x.second]++;
        edge[x.first].push_back(x.second);
    }
    
    queue<int> q;
    
    for (int i = 1; i <= vertex_count; i++) {
        auto x = vertex[i];
        if (x == 0) q.push(i);
    }
    
    for(int i = 0; i < vertex_count; i++) {
        if (q.empty()) __throw_invalid_argument("Cycle accrued");
        
        auto v = q.front(); q.pop();
        out.push_back(v);
        
        for (auto x : edge[v]) if (--vertex[x] == 0) q.push(x);
    }
    
    return out;
}

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v(m);
    
    for (int i = 0; i < m; i++) cin >> v[i].first >> v[i].second;
    
    auto vx = topology_sort(n, v);
    
    for (const auto& x : vx) cout << x << " ";
    cout << "\n";
    
    return 0;
}