// TEST

#include <iostream>

#include "../Dijkstra"

int main() {
    /* input
     * 
     * 4 5
     * 1 2 3
     * 1 3 6
     * 1 4 7
     * 2 3 1
     * 3 4 1
     */
    
    int n, m; cin >> n >> m; max_node = n;
    
    line_info = vector<vector<pii>>(n, vector<pii>());
    
    for (int i = 0; i < m; i++) {
        int a, b, x; cin >> a >> b >> x;
        line_info[a - 1].emplace_back(b, x);
        line_info[b - 1].emplace_back(a, x);
    }
    
    cin >> n >> m;
    
    cout << n << " -> " << m << " = " << dijkstra(n, m);
    
    return 0;
}