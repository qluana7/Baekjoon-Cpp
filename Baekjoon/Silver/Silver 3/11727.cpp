#include <iostream>

using namespace std;

int table[1001] { 0, 1, 3 };

int main() {
    int n; cin >> n;
    for (int i = 3; i <= n; i++) {
        table[i] = (table[i - 2] * 2 + table[i - 1]) % 10007;
    }
    
    cout << table[n];
}