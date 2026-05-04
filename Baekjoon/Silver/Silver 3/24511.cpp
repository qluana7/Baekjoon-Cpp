#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> v(n, 0);
    deque<int> q;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[i] = x;
    }
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!v[i]) q.push_back(x);
    }
    
    cin >> n;
    while (n --> 0) {
        int x; cin >> x;
        q.push_front(x);
        cout << q.back() << " ";
        q.pop_back();
    }
    
    return 0;
}