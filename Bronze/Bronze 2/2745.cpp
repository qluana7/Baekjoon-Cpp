#include <iostream>

using namespace std;

#define num(x) ((x) - ((x) >= 65 ? 55 : 48))

int main() {
    string str; int base; cin >> str >> base;
    
    int n = 0, b = 1;
    for (auto i = str.rbegin(); i != str.rend(); i++) {
        n += num(*i) * b; b *= base;
    }
    
    cout << n;
    
    return 0;
}