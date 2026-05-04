#include <iostream>

using namespace std;

int result = 0;

void DFS(int table[][101], int* nodes, int size, int start);

int main() {
    int size, count; cin >> size >> count;
    auto table = new int [size + 1][101];
    auto nodes = new int [size + 1];
    
    for (; count--;) {
        int a, b; cin >> a >> b;
        table[a][b] = 1;
        table[b][a] = 1;
    }
    
    DFS(table, nodes, size, 1);
    
    cout << result - 1;
    
    return 0;
}

void DFS(int table[][101], int* nodes, int size, int start) {
    result++;
    nodes[start] = 1;
    
    for (int i = 1; i <= size; i++) {
        if (table[start][i] == 1 && nodes[i] == 0) {
            DFS(table, nodes, size, i);
        }
    }
}