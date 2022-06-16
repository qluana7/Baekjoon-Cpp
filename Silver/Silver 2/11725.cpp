#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> table;
vector<int> ps;
int* nodes;
    
void dfs(int node, int pr) {
    ps[node] = pr;
    nodes[node] = 1;
    
    for (int nd : table[node]) {
        if (nodes[nd] == 1) continue;
        dfs(nd, node);
    }
}

int main() {
    int n; cin >> n;
    table = vector<vector<int>>(n + 1, vector<int>());
    ps = vector<int>(n + 1, 0);
    nodes = new int[n + 1]; memset(nodes, 0, n + 1);
    
    for (;--n;) {
        int x, y; cin >> x >> y;
        table[x].push_back(y);
        table[y].push_back(x);
    }
    
    dfs(1, 0);
    
    delete[] nodes;
    
    int len = ps.size();
    for (int i = 2; i < len; i++) cout << ps[i] << "\n";
    
    return 0;
}