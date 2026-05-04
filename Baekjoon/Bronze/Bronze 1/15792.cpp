#include <iostream>

using namespace std;

int main() {
    int a, b; cin >> a >> b;
    cout << a / b << ".";
    
    for (int i = 2000; i--;) {
        a = a % b * 10;
        
        if (a == 0) break;
        
        cout << a / b;
    }
}