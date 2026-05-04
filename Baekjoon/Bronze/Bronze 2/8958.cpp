#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    
    for (; n--;) {
        int x = 0, sum = 0;
        string str; cin >> str;
        for (char& c : str) {
            if (c == 'O') sum += ++x;
            else x = 0;
        }
        
        cout << sum << endl;
    }
    
    return 0;
}