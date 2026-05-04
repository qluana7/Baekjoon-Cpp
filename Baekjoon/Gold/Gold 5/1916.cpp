#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define INF 2147483647

using namespace std;

vector<vector<pii>> line_info;
int max_node;

struct cmp {
    bool operator() (const pii& a, const pii& b) {
        return a.second > b.second;
    }
};

int dijkstra(int start, int end) {
    vector<int> v(max_node, INF);
    
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.emplace(start, 0);
    v[start - 1] = 0;
    
    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        
        if (v[x.first - 1] < x.second) continue;
        
        for (const pii& p : line_info[x.first - 1]) {
            int d = x.second + p.second;
            if (d < v[p.first - 1]) {
                v[p.first - 1] = d;
                pq.emplace(p.first, d);
            }
        }
    }
    
    
    return v[end - 1];
}

int main() {
    int n, m; cin >> n >> m; max_node = n;
    
    line_info = vector<vector<pii>>(n, vector<pii>());
    
    for (int i = 0; i < m; i++) {
        int a, b, x; cin >> a >> b >> x;
        line_info[a - 1].emplace_back(b, x);
        // line_info[b - 1].emplace_back(a, x);
    }
    
    cin >> n >> m;
    cout << dijkstra(n, m);
    
    return 0;
}