#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    for (int i = 1; i < n; i++)
        cout << string(n - i, ' ') << string(i * 2 - 1, '*') << "\n";
    cout << string(n * 2 - 1, '*') << "\n";
    for (int i = 1; i < n; i++)
        cout << string(i, ' ') << string((n - i) * 2 - 1, '*') << "\n";
    
    return 0;
}