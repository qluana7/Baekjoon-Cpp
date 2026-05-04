#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, t = 0; cin >> n;

    while (n --> 0) {
        int x; cin >> x;
        
        t ^= x - 2;
    }

    string name[2] = { "Black", "White" };
    string str; cin >> str;
    cout << (name[str != "Blackking" ^ t == 0]) << "king";
}