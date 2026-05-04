#include <iostream>

using namespace std;

int main() {
    int arr[100][100] { 0, };
    
    int n; cin >> n;
    
    int tot = 0;
    while (n --> 0) {
        int x, y; cin >> x >> y;
        
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (!arr[i + x][j + y]) tot += arr[i + x][j + y] = 1;
    }
    
    cout << tot;
    
    return 0;
}