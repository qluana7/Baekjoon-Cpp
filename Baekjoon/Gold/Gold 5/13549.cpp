#include <iostream>
#include <vector>
#include <queue>

#define pint pair<int, int>

using namespace std;

int BFS(int, int);

int table[100'001];

int main() {
    int n, m; cin >> n >> m;
    
    cout << BFS(n, m);
}

int BFS(int start, int target) {
    priority_queue<pint, vector<pint>, greater<pint>> q;
    int dep = 0;
    
    table[start] = 0;
    q.push(make_pair(0, start));
    
    while (!q.empty()) {
        pint it = q.top();
        int n = it.second; q.pop();
        
        if (n == target) return it.first;
        
        if (n * 2 <= 100'000 && !table[n * 2]) { q.push(make_pair(it.first, n * 2)); table[n * 2] = 1; }
        if (n - 1 >= 0 && !table[n - 1]) { q.push(make_pair(it.first + 1, n - 1)); table[n - 1] = 1; }
        if (n + 1 <= 100'000 && !table[n + 1]) { q.push(make_pair(it.first + 1, n + 1)); table[n + 1] = 1; }
    }
}