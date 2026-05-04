#include <iostream>

using namespace std;

int main() {
    int a, b, m = 64; cin >> a >> b;
    
    int arr[a][b]; getchar();
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            arr[i][j] = (getchar() == 'W' ? 1 : 0);
        }
        getchar();
    }
    
    for (int i = 0; i <= a - 8; i++) {
        for (int j = 0; j <= b - 8; j++) {
            int tmp = arr[i][j], c = 0;
            
            for (int p = i; p < i + 8; p++) {
                for (int q = j; q < j + 8; q++) {
                    if (arr[p][q] != tmp) c++;
                    
                    tmp = !tmp;
                }
                
                tmp = !tmp;
            }
            
            c = min(c, 64 - c);
            m = min(m, c);
        }
    }
    
    cout << m;
    
    return 0;
}