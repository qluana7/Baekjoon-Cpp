#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    
    for (; n--; ) {
        int x; cin >> x;
        for (int i = 0; x; i++, x >>= 1) if (x & 1) cout << i << " ";
    }
    
    return 0;
}