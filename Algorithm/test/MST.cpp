// TEST

#include <iostream>

#include "../MST"

int main() {
    /* input
     *
     * 3 3
     * 1 2 1
     * 2 3 2
     * 1 3 3
     */
    
    int n, m; cin >> n >> m;
    vector<edge> v(m);
    
    for (auto& x : v) cin >> x.start >> x.end >> x.cost;
    
    vector<edge> vst = mst(v, n);
    
    int t = 0; cout << "\n";
    for (auto& x : vst) {
        cout << x.start << " " << x.end << " " << x.cost << "\n";
        t += x.cost;
    }
    
    cout << t;
    
    return 0;
}