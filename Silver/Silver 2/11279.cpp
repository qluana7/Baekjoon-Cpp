#include <queue>
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    priority_queue<int, vector<int>, less<int>> q;
    int n; cin >> n;
    
    for (;n--;) {
        int x; cin >> x;
        if (x == 0) {
            if (q.empty()) cout << "0\n";
            else {
                cout << q.top() << "\n";
                q.pop();
            }
        } else q.push(x);
    }
    
    return 0;
}