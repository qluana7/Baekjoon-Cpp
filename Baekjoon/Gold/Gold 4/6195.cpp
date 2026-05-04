#include <iostream>
#include <vector>
#include <queue>

#define u64 unsigned long long

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    priority_queue<u64, vector<u64>, greater<u64>> pq;

    int n; cin >> n;

    while (n --> 0) {
        int x; cin >> x;
        pq.push(x);
    }

    u64 cost = 0;
    while (pq.size() != 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        
        cost += a + b;
        pq.push(a + b);
    }

    cout << cost;
}