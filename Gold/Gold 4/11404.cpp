#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1U << 29;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1)), res = adj;

    while (m --> 0) {
        int a, b, c; cin >> a >> b >> c;
        adj[a][b] = adj[a][b] ? min(adj[a][b], c) : c;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            if (adj[i][j]) res[i][j] = adj[i][j];
            else res[i][j] = INF;
        }
    }
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << (res[i][j] == INF ? 0 : res[i][j]) << " ";
        cout << "\n";
    }
}