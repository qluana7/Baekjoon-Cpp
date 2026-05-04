#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n; string str; cin >> n >> str;
    vector<int> v(n); stack<double> s;
    
    for (int& x : v) cin >> x;
    
    for (char c : str) {
        switch (c) {
            case '+': {
                double b = s.top(); s.pop();
                double a = s.top(); s.pop();
                s.push(a + b);
                break;
            }
            case '-': {
                double b = s.top(); s.pop();
                double a = s.top(); s.pop();
                s.push(a - b);
                break;
            }
            case '*': {
                double b = s.top(); s.pop();
                double a = s.top(); s.pop();
                s.push(a * b);
                break;
            }
            case '/': {
                double b = s.top(); s.pop();
                double a = s.top(); s.pop();
                s.push(a / b);
                break;
            }
            default:
                s.push(v[c - 'A']);
                break;
        }
    }
    
    cout.precision(2);
    cout << fixed << s.top();
    
    return 0;
}