#include <iostream>

using namespace std;

void DFS(int table[][1001], int* nodes, int size, int start);

int main() {
    int size, count; cin >> size >> count;
    auto table = new int [size + 1][1001];
    auto nodes = new int [size + 1];
    
    for (; count--;) {
        int a, b; cin >> a >> b;
        table[a][b] = 1;
        table[b][a] = 1;
    }
    
    int result = 0;
    
    for (int i = 1; i <= size; i++)
    {
        if (nodes[i] == 1) continue;
        
        DFS(table, nodes, size, i);
        result++;
    }
    
    cout << result;
    
    return 0;
}

void DFS(int table[][1001], int* nodes, int size, int start) {
    nodes[start] = 1;
    
    for (int i = 1; i <= size; i++) {
        if (table[start][i] == 1 && nodes[i] == 0) {
            DFS(table, nodes, size, i);
        }
    }
}