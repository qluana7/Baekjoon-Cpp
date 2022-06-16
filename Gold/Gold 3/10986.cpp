#include <iostream>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int arr[m] { 0 }; int tot = 0;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x; tot += x;
        arr[tot %= m]++;
    }
    
    long long cnt = 0;
    
    for (int i = 0; i < m; i++) {
        if (arr[i] == 0) continue;
        
        long long x = arr[i];
        
        cnt += x * (x - 1) / 2;
    } cnt += arr[0];
    
    cout << cnt;
    
    return 0;
}