#include <iostream>
#include <vector>

using namespace std;

int update(vector<int>& dp, const vector<vector<int>>& e, int k) {
    if (dp[k] != -1) return 0;

    dp[k] += 2;

    for (int x : e[k]) {
        dp[k] += update(dp, e, x);
    }

    return dp[k];
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m, k; cin >> n >> m >> k;
    vector<int> dp(n + 1, -1);
    vector<vector<int>> e(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;

        e[a].push_back(b);
        e[b].push_back(a);
    }

    dp[m] = update(dp, e, m);
    
    while (k --> 0) {
        int x; cin >> x;
        cout << dp[x] << "\n";
    }
}