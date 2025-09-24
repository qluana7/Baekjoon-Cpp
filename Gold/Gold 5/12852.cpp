#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[1000001];

int main() {
    int n; cin >> n;
    
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
        if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
    }
    
    cout << arr[n] << "\n";
    
    while (n != 1) {
        cout << n << " ";
        
        if (arr[n] == arr[n - 1] + 1) n -= 1;
        else if (n % 2 == 0 && arr[n] == arr[n / 2] + 1) n /= 2;
        else if (n % 3 == 0 && arr[n] == arr[n / 3] + 1) n /= 3;
    }
    
    cout << 1;
    
    return 0;
}