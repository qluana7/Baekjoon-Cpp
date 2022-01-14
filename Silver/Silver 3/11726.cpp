#include <iostream>

using namespace std;

int main() {
    int table[1001] { 1, 1 };
    
    int n; cin >> n;
    
    for (int i = 2; i <= n; i++) {
        table[i] = table[i - 1] + table[i - 2];
        table[i] %= 10007;
    }
    
    cout << table[n];
    
    return 0;
}