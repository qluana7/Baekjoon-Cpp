#include <iostream>
#include <cmath>

using namespace std;

int table[1000] { 1 }, input[1000];
int n;

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> input[i];
    
    for (int ind = 0; ind < n; ind++) {
        table[ind] = 1;
        for (int i = 0; i < ind; i++) {
            if (input[ind] <= input[i]) continue;
            
            table[ind] = max(table[ind], table[i] + 1);
        }
    }
    
    int m = 0;
    for (int i = 0; i < n; i++) if (m < table[i]) m = table[i];
    
    cout << m;
    
    return 0;
}