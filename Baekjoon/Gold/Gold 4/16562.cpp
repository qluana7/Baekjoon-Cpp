#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int head(vector<int>& cost, vector<int>& v, int idx) {
    if (v[idx] == idx) return idx;
    
    int ind = head(cost, v, v[idx]);
    cost[ind] = cost[idx] = min(cost[idx], cost[ind]);
    return v[idx] = ind;
}

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> cost(n);
    for (auto& x : cost) cin >> x;
    
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    
    while (m --> 0) {
        int a, b; cin >> a >> b;
        a--; b--;
        int ah = head(cost, v, b), bh = head(cost, v, a);
        v[ah] = bh;
        cost[bh] = cost[ah] = min(cost[ah], cost[bh]);
    }
    
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == i) sum += cost[i];
    }
    
    cout << (sum > k ? "Oh no" : to_string(sum));
}