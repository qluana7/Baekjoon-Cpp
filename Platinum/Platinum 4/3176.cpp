#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dep;
vector<vector<int>> p;
vector<vector<pair<int, int>>> dist_v;

void f(pair<int, int>& src, const pair<int, int>& a, const pair<int, int>& b) {
    src = { min(a.first, b.first), max(a.second, b.second) };
}

void dfs(int cpos, int dpos, int ppos, int c) {
    dep[cpos] = dpos;

    for (auto [npos, _] : adj[cpos]) {
        if (npos != ppos) {
            p[npos][0] = cpos;
            dist_v[npos][0] = {_, _};
            dfs(npos, dpos + 1, cpos, _);
        }
    }
}

void fill(int n) {
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            p[j][i] = p[p[j][i - 1]][i - 1];
            auto a = dist_v[j][i - 1], b = dist_v[p[j][i - 1]][i - 1];

            f(dist_v[j][i], a, b);
        }
    }
}

pair<int, int> lca(int n, int a, int b) {
    pair<int, int> ret = { 2147483647, -2147483648 };

    if (dep[a] < dep[b]) swap(a, b);

    for (int i = 20; i >= 0; i--)
        if (dep[a] - dep[b] >= (1 << i)) { f(ret, ret, dist_v[a][i]); a = p[a][i]; }
    
    if (a == b) return ret;

    for (int i = 20; i >= 0; i--) {
        if (p[a][i] != p[b][i]) { f(ret, ret, dist_v[a][i]); f(ret, ret, dist_v[b][i]); a = p[a][i]; b = p[b][i]; }
    }

    f(ret, ret, dist_v[a][0]); f(ret, ret, dist_v[b][0]);

    return ret;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    adj = vector<vector<pair<int, int>>>(n + 1);
    dep = vector<int>(n + 1);
    p = vector<vector<int>>(n + 1, vector<int>(21));
    dist_v = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>(21));

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
        auto [mn, mx] = lca(n, a, b);
        cout << mn << " " << mx << "\n";
    }
}