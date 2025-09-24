#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

stack<int> comp;
vector<vector<int>> src, inv, scc;
vector<int> node;
int r = 0;

void dfs(int st, bool stk) {
    node[st] = true;
    
    if (!stk) scc[r].push_back(st);
    
    for (auto x : (stk ? src : inv)[st])
        if (!node[x]) dfs(x, stk);
    
    if (stk) comp.push(st);
}

int main()
{
	int n, m; cin >> n >> m;
	src.resize(n + 1); inv.resize(n + 1);
	node.resize(n + 1);
	
	for (;m--;) {
	    int x, y; cin >> x >> y;
	    src[x].push_back(y);
	    inv[y].push_back(x);
	}
	
	for (int i = 1; i <= n; i++)
	    if (!node[i]) dfs(i, true);
	
	fill(node.begin(), node.end(), 0);
    int tmp = 0;
	while (!comp.empty()) {
	    int x = comp.top(); comp.pop();
	    
	    if (node[x]) continue;
	    node[x] = true;
	    
	    scc.resize(r + 1);
	    dfs(x, false);
	    
	    tmp = max<int>(tmp, scc[r].size()); r++;
	}
	
    cout << tmp;
	return 0;
}