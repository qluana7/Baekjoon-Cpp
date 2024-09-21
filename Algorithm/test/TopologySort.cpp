// TEST

#include <iostream>

#include "../TopologySort"

int _main() {
    /* INPUT
     *
     * 7 7
     * 1 2
     * 1 5
     * 2 3
     * 3 4
     * 4 6
     * 5 6
     * 6 7
     * 
     */
    
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v(m);
    
    for (int i = 0; i < m; i++) cin >> v[i].first >> v[i].second;
    
    auto vx = topology_sort(n, v);
    
    for (const auto& x : vx) cout << x << " ";
    cout << "\n";
    
    return 0;
}