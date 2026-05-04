#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int& a, int& b) {
        int n = abs(a), m = abs(b);
        if (n == m) return a > b;
        else return n > m;
    }
};

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    priority_queue<int, vector<int>, cmp> pq;
    int n; cin >> n;
    
    for (; n--; ) {
        int tmp; cin >> tmp;
        
        if (tmp == 0) {
            if (pq.empty()) cout << "0";
            else { cout << pq.top(); pq.pop(); }
            cout << "\n";
        } else pq.push(tmp);
    }
    
    return 0;
}