#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    
    int v1[1'000'001] {}, v2[1'000'001] {};
    int a, b; cin >> a >> b;
    
    for (int i = 0; i < a; i++) cin >> v1[i];
    for (int i = 0; i < b; i++) cin >> v2[i];
    
    int loc1 = 0, loc2 = 0;
    
    while (loc1 < a && loc2 < b) {
        if (v1[loc1] < v2[loc2]) { cout << v1[loc1] << " "; loc1++; }
        else { cout << v2[loc2] << " "; loc2++; }
    }
    
    if (loc1 == a) while (loc2 < b) { cout << v2[loc2] << " "; loc2++; }
    if (loc2 == b) while (loc1 < a) { cout << v1[loc1] << " "; loc1++; }
    
    return 0;
}