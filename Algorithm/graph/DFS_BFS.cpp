/*
 * Algorithm Name : DFS & BFS
 *
 * Description
 *    - 인접 행렬을 이용한 그래프 탐색 알고리즘
 *    - 재귀를 이용한 DFS와 큐를 이용한 BFS
 */

#include <iostream>
#include <queue>

using namespace std;

void DFS(int table[][1001], int* nodes, int size, int start);
void BFS(int table[][1001], int* nodes, int size, int start);

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