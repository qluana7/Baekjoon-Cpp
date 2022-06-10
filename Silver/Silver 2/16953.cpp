#include <iostream>
#include <queue>

using namespace std;

int bfs(int x, int target) {
    queue<pair<long long, int>> q;
    q.push({x, 1});
    
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        
        if (p.first == target) return p.second;
        
        if (p.first << 1 <= target) q.push({p.first << 1, p.second + 1});
        if (p.first * 10 + 1 <= target) q.push({p.first * 10 + 1, p.second + 1});
    }
    
    return -1;
}

int main() {
    int n, m; cin >> n >> m;
    
    cout << bfs(n, m);
    
    return 0;
}