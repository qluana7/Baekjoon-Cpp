#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, x; cin >> n;
    stack<int> s;
    
    while (cin >> x) {
        if (x == 1) { int p; cin >> p; s.push(p); continue; }
        else if (x == 2) { if (s.empty()) cout << -1; else { cout << s.top(); s.pop(); } }
        else if (x == 3) { cout << s.size(); }
        else if (x == 4) { cout << (s.empty() ? 1 : 0); }
        else { cout << (s.empty() ? -1 : s.top()); }
        
        cout << "\n";
    }
}