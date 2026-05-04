#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    char x = a[0];
    a[0] = a[2];
    a[2] = x;
    
    char y = b[0];
    b[0] = b[2];
    b[2] = y;
        
    cout << max(stoi(a), stoi(b));
    
    return 0;
}