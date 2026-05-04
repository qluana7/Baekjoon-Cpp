#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

void DFS(int table[][1001], int* nodes, int size, int start);
void BFS(int table[][1001], int* nodes, int size, int start);

int main() {
    int size, count, start; cin >> size >> count >> start;
    auto table = new int [size + 1][1001] {};
    auto nodes = new int [size + 1];
    
    for (int i = 0; i < count; i++) {
        int a, b; cin >> a >> b;
        
        table[a][b] = 1;
        table[b][a] = 1;
    }
    
    DFS(table, nodes, size, start);
    
    cout << endl;
    memset(nodes, 0, sizeof(int) * (size + 1));
    
    BFS(table, nodes, size, start);
    
    delete[] table;
    delete[] nodes;
    
    return 0;
}

void DFS(int table[][1001], int* nodes, int size, int start) {
    cout << start << " ";
    nodes[start] = 1;
    
    for (int i = 1; i <= size; i++) {
        int n = table[start][i];
        
        if (n == 1 && nodes[i] == 0) {
            DFS(table, nodes, size, i);
        }
    }
}

void BFS(int table[][1001], int* nodes, int size, int start) {
    queue<int> q = queue<int>();
    
    cout << start << " ";
    nodes[start] = 1;
    
    q.push(start);
    
    while (!q.empty()) {
        int n = q.front(); q.pop();
        
        for (int i = 1; i <= size; i++) {
            int x = table[n][i];
            
            if (x == 1 && nodes[i] == 0) {
                q.push(i);
                cout << i << " ";
                nodes[i] = 1;
            }
        }
    }
}