#include <iostream>
#include <queue>

using namespace std;

int BFS(int, int);

int table[100'001];

int main() {
    int n, m; cin >> n >> m;
    
    cout << BFS(n, m);
}

int BFS(int start, int target) {
    queue<int> q;
    int dep = 0;
    
    table[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int n = q.front(); q.pop();
        
        if (n == target) return table[n];
        
        if (n - 1 >= 0 && !table[n - 1]) { q.push(n - 1); table[n - 1] = table[n] + 1; }
        if (n + 1 <= 100'000 && !table[n + 1]) { q.push(n + 1); table[n + 1] = table[n] + 1; }
        if (n * 2 <= 100'000 && !table[n * 2]) { q.push(n * 2); table[n * 2] = table[n] + 1; }
    }
}