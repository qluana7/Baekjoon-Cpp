#include <string>
#include <iostream>
#include <cstdio>
#include <regex>

using namespace std;

int main() {
    regex r1("\\-?(\\d+)?x[\\-\\+]\\d+", regex_constants::optimize), r2("\\-?\\d+x");
    string str; cin >> str;
    
    int a = 0, b = 0;
    if (regex_match(str, r1)) {
        sscanf(str.c_str(), "%dx%d", &a, &b);
    } else if (regex_match(str, r2)) {
        sscanf(str.c_str(), "%d", &a);
    } else {
        sscanf(str.c_str(), "%d", &b);
    }
    
    a /= 2;
    
    if (a != 0) {
        if (a == -1) cout << '-';
        if (a != 1 && a != -1) cout << a;
        cout << "xx";
    }
    
    if (b != 0) {
        if (b < 0) cout << '-';
        else if (a != 0) cout << '+';
        if (b != 1 && b != -1) cout << abs(b);
        cout << "x";
    }
    
    if (a != 0 || b != 0) cout << "+";
    cout << "W";
    
    return 0;
}