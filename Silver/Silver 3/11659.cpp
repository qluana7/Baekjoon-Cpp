#include <iostream>

using namespace std;

int table[100'000];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> table[i]; table[i] += table[i - 1];
    }
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        
        cout << table[b] - table[a - 1] << "\n";
    }
    
    return 0;
}