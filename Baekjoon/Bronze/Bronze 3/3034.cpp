#include <iostream>

using namespace std;

int main() {
    int n, w, h; cin >> n >> w >> h;
    int m = w * w + h * h;
    
    for (;n--;) {
        int x; cin >> x;
        cout << (x * x > m ? "NE" : "DA") << "\n";
    }
    
    return 0;
}