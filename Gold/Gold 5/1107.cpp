#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int rs, n; cin >> rs >> n;
    int table[10] { 0, };
    
    for (;n--;) { int x; cin >> x; table[x]++; }
    
    if (rs == 100) { cout << 0; return 0; }
    
    if (rs == 0) {
        for (int i = 0; i < 10; i++) {
            if (!table[i]) { cout << i + 1; return 0; }
        }
        
        cout << 100;
        return 0;
    }
    
    int i = 0, v;
    for (; i < 500000; i++) {
        bool b = false;
        if (rs - i >= 0) {
            int tmp = rs - i;
            do {
                if (table[tmp % 10]) { b = true; break; }
                tmp /= 10;
            } while (tmp != 0);
            
            if (!b) { v = rs - i; break; }
        }
        
        int tmp = rs + i;
        do {
            if (table[tmp % 10]) break;
            tmp /= 10;
        } while (tmp != 0);
        
        if (tmp == 0) { v = rs + i; break; }
    }
    
#ifndef ONLINE_JUDGE
    cout << v << "\n";
#endif
    cout << min(abs(rs - 100), i + (int)__builtin_log10(v ?: 1) + 1);
}