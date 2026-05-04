#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0); cin.sync_with_stdio(false);
    
    int t1[1'000'001] {};
    int t2[1'000'001] {};
    stack<int> s;
    
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) cin >> t1[i];
    
    for (int i = n - 1; i >= 0; i--) {
        int x = t1[i];
        while (!s.empty() && s.top() <= x) s.pop();
        
        t2[i] = s.empty() ? -1 : s.top();
        
        s.push(x);
    }
    
    for (int i = 0; i < n; i++) cout << t2[i] << " ";
    
    return 0;
}