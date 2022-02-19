#include <iostream>

using namespace std;

long table[68] { 1, 1, 2, 4 };

int main() {
    int k; cin >> k;
    
    for (; k--;) {
        int n; cin >> n;
        
        for (int i = 4; i <= n; i++)
            table[i] = table[i - 4] + table[i - 3] + table[i - 2] + table[i - 1];
        
        cout << table[n] << "\n";
    }
    
    return 0;
}