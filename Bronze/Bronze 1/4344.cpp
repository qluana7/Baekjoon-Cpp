#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n; cin >> n;
    
    for (; n--;) {
        int x; cin >> x;
        int arr[x];
        float s = 0;
        
        for (int i = 0; i < x; i++) {
            cin >> arr[i];
            s += arr[i];
        }
        
        s /= x;
        
        float c = 0;
        
        for (int i = 0; i < x; i++) if (arr[i] > s) c++;
        
        cout << round(c / x * 1000) / 1000 << "%d" << endl;
    }
    
    return 0;
}