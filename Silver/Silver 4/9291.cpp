#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int arr[9][9];
    int n; cin >> n;
    bool fail = true;
    
    for (int cs = 0; cs < n; cs++, cout << "Case " << cs << ": " << (fail ? "INCORRECT" : "CORRECT") << "\n", fail = true) {
        int f1 = 0, f2 = 0;
        memset(arr, 0,sizeof(arr));
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> arr[i][j];
            }
        }
        
        for (int i = 0; i < 9; i++) {
            f1 = 0; f2 = 0;
            for (int j = 0; j < 9; j++) {
                int t1 = 1 << arr[i][j] - 1;
                int t2 = 1 << arr[j][i] - 1;
                
                if (f1 & t1) goto end; f1 |= t1;
                if (f2 & t2) goto end; f2 |= t2;
            }
        }
        
        for (int i = 0; i / 3 < 3; i += 3) {
            for (int j = 0; j / 3 < 3; j += 3) {
                int f1 = 0;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        int t = 1 << arr[i + k][j + l] - 1;
                        
                        if (f1 & t) goto end; f1 |= t;
                    }
                }
            }
        }
        
        fail = false;
        end: ;
    }
    
    return 0;
}