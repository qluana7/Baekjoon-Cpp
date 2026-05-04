#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> dep;
vector<vector<int>> p;

void dfs(int cpos, int dpos, int ppos) {
    dep[cpos] = dpos;

    for (auto npos : adj[cpos]) {
        if (npos != ppos) {
            p[npos][0] = cpos;
            dfs(npos, dpos + 1, cpos);
        }
    }
}

void fill(int n) {
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++)
            p[j][i] = p[p[j][i - 1]][i - 1];
}

int lca(int n, int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);

    for (int i = 20; i >= 0; i--)
        if (dep[a] - dep[b] >= (1 << i)) a = p[a][i];
    
    if (a == b) return a;

    for (int i = 20; i >= 0; i--) {
        if (p[a][i] != p[b][i]) { a = p[a][i]; b = p[b][i]; }
    }

    return p[a][0];
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    adj = vector<vector<int>>(10001);
    dep = vector<int>(10001);
    p = vector<vector<int>>(10001, vector<int>(21));

    int t; cin >> t;
    while (t --> 0) {
        int n; cin >> n;
        adj.assign(n + 1, vector<int>());
        dep.assign(n + 1, 0);
        p.assign(n + 1, vector<int>(21));

        int root = 0;
        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;

            if (root == 0 || root == b) root = a;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(root, 1, 0);
        fill(n);

        int x, y; cin >> x >> y;
        cout << lca(n, x, y) << "\n";
    }
}