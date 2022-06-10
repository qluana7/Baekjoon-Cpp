#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL); cin.sync_with_stdio(false);
    
    int x; cin >> x;
    
    for (; x--;) {
        int a, b; cin >> a >> b;
        cout << a + b << "\n";
    }
    
    return 0;
}