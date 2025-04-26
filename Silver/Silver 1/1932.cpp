#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int table[501] {}, tmp[501] {};
    int n;
    cin >> n >> table[0];
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int x; cin >> x;
            
            tmp[j] = x +
                max(j - 1 < 0 ? 0 : table[j - 1], j == i ? 0 : table[j]);
        }
        
        mempcpy(table, tmp, sizeof(int) * i);
    }
    
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max > table[i]) continue;
        
        max = table[i];
    }
    
    cout << max;
}