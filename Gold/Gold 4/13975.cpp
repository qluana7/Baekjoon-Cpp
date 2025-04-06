#include <iostream>
#include <vector>
#include <queue>

#define u64 unsigned long long

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    while (t --> 0) {
        priority_queue<u64, vector<u64>, greater<u64>> pq;

        int n; cin >> n;

        while (n --> 0) {
            int x; cin >> x;
            pq.push(x);
        }

        u64 cost = 0;
        while (pq.size() != 1) {
            u64 a = pq.top(); pq.pop();
            u64 b = pq.top(); pq.pop();

            cost += a + b;
            pq.push(a + b);
        }

        cout << cost << "\n";
    }
}