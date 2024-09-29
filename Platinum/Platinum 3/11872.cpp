#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, t = 0; cin >> n;

    while (n --> 0) {
        int x; cin >> x;
        
        if (x % 4 == 0) t ^= x - 1;
        else if (x % 4 == 3) t ^= x + 1;
        else t ^= x;
    }

    cout << (t == 0 ? "cubelover" : "koosaga");
}