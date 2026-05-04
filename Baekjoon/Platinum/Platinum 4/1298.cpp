#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
bool dfs(const vector<vector<T>>& edge, vector<int>& minfo, vector<int>& visit, int vs, int x) {
    for (auto i : edge[x]) {
        if (visit[i] == vs) continue;

        visit[i] = vs;

        if (minfo[i] == -1 || dfs(edge, minfo, visit, vs, minfo[i])) {
            minfo[i] = x; return true;
        }
    }

    return false;
}

template <typename T>
int match(const vector<vector<T>>& edge, int x, int y) {
    int ret = 0, vs = 1, mx = max(x, y);

    vector<int> minfo(y, -1), visit(y);

    for (int i = 0; i < edge.size(); i++) {
        vs++; ret += dfs(edge, minfo, visit, vs, i);
    }
    
    return ret;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<vector<int>> edge(n, vector<int>());

    while (m --> 0) {
        int a, b; cin >> a >> b;
        edge[a - 1].push_back(b - 1);
    }

    cout << match(edge, n, n);
}