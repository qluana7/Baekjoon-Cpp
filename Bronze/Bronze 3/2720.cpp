#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    
    while (n --> 0) {
        int x; cin >> x;
        cout << x / 25 << " "; x %= 25;
        cout << x / 10 << " "; x %= 10;
        cout << x / 5  << " "; x %= 5;
        cout << x;
        
        cout << "\n";
    }
    
    return 0;
}
