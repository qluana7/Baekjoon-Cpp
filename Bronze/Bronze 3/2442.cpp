#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    string str = "*";
    
    for (;n--;) {
        cout << string(n, ' ') << str << "\n";
        str += "**";
    }
    
    return 0;
}