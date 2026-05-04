#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr, arr + n);
    
    for (int i = 0; i < n - 1; i++) cout << arr[i] << " ";
    cout << arr[n - 1];
    
    return 0;
}