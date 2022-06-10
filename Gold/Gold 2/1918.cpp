#include <iostream>
#include <stack>

using namespace std;

int getPriority(char toke, bool stack = false);

int main() {
    string exp; cin >> exp;
    stack<char> s;
    
    for (char& c : exp) {
        if (c >= 65) { cout << c; continue; }
        
        if (c == ')') {
            while (s.top() != '(') { cout << s.top(); s.pop(); }
            s.pop();
            continue;
        }
        
        while (!s.empty() && getPriority(c) <= getPriority(s.top(), true)) { cout << s.top(); s.pop(); }
        
        s.push(c);
    }
    
    while (!s.empty()) { cout << s.top(); s.pop(); }
    
    return 0;
}

int getPriority(char token, bool stack) {
    switch (token) {
        case '(':
            return stack ? 0 : 3;
        case '*': case '/':
            return 2;
        case '+': case '-':
            return 1;
        default:
            return -1;
    }
}