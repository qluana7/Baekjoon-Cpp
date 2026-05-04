#include <iostream>

using namespace std;

int main() {
    int mx1, my1; cin >> mx1 >> my1;
    int mt1[101][101] {};
    
    for (int i = 0; i < mx1; i++)
        for (int j = 0; j < my1; j++)
            cin >> mt1[i][j];
    
    int mx2, my2; cin >> mx2 >> my2;
    int mt2[101][101] {};
    
    for (int i = 0; i < mx2; i++)
        for (int j = 0; j < my2; j++)
            cin >> mt2[i][j];
    
    int size = my1;
    int mtr[101][101] {};
    
    for (int i = 0; i < mx1; i++) {
        for (int j = 0; j < my2; j++) {
            for (int k = 0; k < size; k++) {
                mtr[i][j] += mt1[i][k] * mt2[k][j];
            }
        }
    }
    
    for (int i = 0; i < mx1; i++) {
        for (int j = 0; j < my2; j++) {
            cout << mtr[i][j] << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}