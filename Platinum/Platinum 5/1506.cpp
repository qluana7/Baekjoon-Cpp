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
	int n; cin >> n;
	src.resize(n); inv.resize(n);
	node.resize(n);
	
	vector<int> cost(n);
	for (auto& x : cost) cin >> x;
	
	for (int i = 0; i < n; i++) {
	    getchar();
	    for (int j = 0; j < n; j++) {
	        if (getchar() == 48) continue;
	        
	        src[i].push_back(j);
	        inv[j].push_back(i);
	    }
	}
	
	for (int i = 0; i < n; i++)
	    if (!node[i]) dfs(i, true);
	
	fill(node.begin(), node.end(), 0);
	while (!comp.empty()) {
	    int x = comp.top(); comp.pop();
	    
	    if (node[x]) continue;
	    node[x] = true;
	    
	    scc.resize(r + 1);
	    dfs(x, false);
	    
	    sort(scc[r].begin(), scc[r].end(), [&](const auto& a, const auto& b) { return cost[a] < cost[b]; }); r++;
	}
	
	sort(scc.begin(), scc.end(), [&](const auto& a, const auto& b) { return cost[a[0]] < cost[b[0]]; });
	
	int tot = 0;
	for (auto& vx : scc) tot += cost[vx[0]];
	
	cout << tot;
	
	return 0;
}