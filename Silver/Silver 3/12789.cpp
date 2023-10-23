#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    
    for (auto& vx : v) cin >> vx;
    
    stack<int> s;
    int cur = 1;
    
    for (auto x : v) {
        while (!s.empty() && s.top() == cur) {
            s.pop(); cur++;
        }
        
        if (x == cur) cur++;
        else s.push(x);
    }
    
    while (!s.empty()) {
        int x = s.top(); s.pop();
        
        if (x != cur) {
            cout << "Sad";
            return 0;
        }
        
        cur++;
    }
    
    cout << "Nice";
    
    return 0;
}