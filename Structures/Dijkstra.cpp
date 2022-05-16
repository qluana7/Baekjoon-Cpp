/*
 * Algorithm Name : Dijkstra
 *
 * Description
 *    - 그래프 간선의 가중치가 주어졌을 때,
 *      최단 거리를 찾는 알고리즘
 * 
 *    - 인접 행렬과 힙(우선순위 큐)를 이용해
 *      O(n log n) 소모
 */

/*     GRAPH
 *
 *    /-[7] - 4
 *   /        |
 *  1 -\     [1]
 *  |   \     |
 * [3]  [6] - 3
 *  |        /
 *  2 - [1]-/
 * 
 * ARRAY :
 * [ 0  , 3  , 6  , 7   ]
 * [ 3  , 0  , 1  , INF ]
 * [ 6  , 1  , 0  , 1   ]
 * [ 7  , INF, 1  , 0   ]
 * 
 * RESULT :
 * ┌───────┬──────────────────┐
 * │ Start │      Array       │
 * ├───────┼──────────────────┤
 * │   1   │  [ 0, 3, 4, 5 ]  │
 * │   2   │  [ 3, 0, 1, 2 ]  │
 * │   3   │  [ 4, 1, 0, 1 ]  │
 * │   4   │  [ 5, 2, 1, 0 ]  │
 * └───────┴──────────────────┘
 */

#include <vector>
#include <queue>

#define pii pair<int, int>
#define INF 2147483647

using namespace std;

vector<vector<pii>> line_info;
int max_node;

struct cmp {
    bool operator() (const pii& a, const pii& b) {
        return a.second > b.second;
    }
};

int dijkstra(int start, int end) {
    vector<int> v(max_node, INF);
    
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.emplace(start, 0);
    v[start - 1] = 0;
    
    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        
        if (v[x.first - 1] < x.second) continue;
        
        for (const pii& p : line_info[x.first - 1]) {
            int d = x.second + p.second;
            if (d < v[p.first - 1]) {
                v[p.first - 1] = d;
                pq.emplace(p.first, d);
            }
        }
    }
    
    
    return v[end - 1];
}

// TESTING

#include <iostream>

int main() {
    /* input
     * 
     * 4 5
     * 1 2 3
     * 1 3 6
     * 1 4 7
     * 2 3 1
     * 3 4 1
     */
    
    int n, m; cin >> n >> m; max_node = n;
    
    line_info = vector<vector<pii>>(n, vector<pii>());
    
    for (int i = 0; i < m; i++) {
        int a, b, x; cin >> a >> b >> x;
        line_info[a - 1].emplace_back(b, x);
        line_info[b - 1].emplace_back(a, x);
    }
    
    cin >> n >> m;
    
    cout << n << " -> " << m << " = " << dijkstra(n, m);
    
    return 0;
}