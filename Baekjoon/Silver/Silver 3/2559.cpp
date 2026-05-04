#include <iostream>
#include <queue>

using namespace std;

int main() {
    int c, n; cin >> c >> n;
    int mx, tot = 0;
    queue<int> q;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        q.push(x);
        tot += x;
    } mx = tot;
    
    for (int i = 0; i < (c - n); i++) {
        int x; cin >> x;
        tot = tot - q.front() + x;
        
        q.pop(); q.push(x);
        
        if (tot > mx) mx = tot;
    }
    
    cout << mx;
    
    return 0;
}