#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    priority_queue<int, vector<int>, greater<int>> pq;

    int n; cin >> n;

    while (n --> 0) {
        int x; cin >> x;
        pq.push(x);
    }

    int cost = 0;
    while (pq.size() != 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        cost += a + b;
        pq.push(a + b);
    }

    cout << cost;
}