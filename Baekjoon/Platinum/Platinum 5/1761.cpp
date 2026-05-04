#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dep;
vector<vector<int>> p;
vector<vector<int>> dist_v;

void dfs(int cpos, int dpos, int ppos, int c) {
    dep[cpos] = dpos;

    for (auto [npos, _] : adj[cpos]) {
        if (npos != ppos) {
            p[npos][0] = cpos;
            dist_v[npos][0] = _;
            dfs(npos, dpos + 1, cpos, _);
        }
    }
}

void fill(int n) {
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            p[j][i] = p[p[j][i - 1]][i - 1];
            dist_v[j][i] = dist_v[j][i - 1] + dist_v[p[j][i - 1]][i - 1];
        }
    }
}

int lca(int n, int a, int b) {
    int sum = 0;

    if (dep[a] < dep[b]) swap(a, b);

    for (int i = 20; i >= 0; i--)
        if (dep[a] - dep[b] >= (1 << i)) { sum += dist_v[a][i]; a = p[a][i]; }
    
    if (a == b) return sum;

    for (int i = 20; i >= 0; i--) {
        if (p[a][i] != p[b][i]) { sum += dist_v[a][i] + dist_v[b][i]; a = p[a][i]; b = p[b][i]; }
    }

    sum += dist_v[a][0] + dist_v[b][0];

    return sum;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    adj = vector<vector<pair<int, int>>>(n + 1);
    dep = vector<int>(n + 1);
    p = vector<vector<int>>(n + 1, vector<int>(21));
    dist_v = vector<vector<int>>(n + 1, vector<int>(21));

    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    dfs(1, 1, 0, 0);
    fill(n);

    int m; cin >> m;

    while (m --> 0) {
        int a, b; cin >> a >> b;
        cout << lca(n, a, b) << "\n";
    }
}