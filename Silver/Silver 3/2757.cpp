#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int main() {
    char tmp; int a, b;
    
    while (true) {
        cin >> tmp >> a >> tmp >> b;
        
        if (!a) return 0;
        
        string str;
        
        int x = 1;
        int t;
        
        do {
            t = (t = b % 26) ? t : 26;
            str.push_back('@' + t);
        } while ((b = b / 26 - !(b % 26)) > 0);
        
        copy(str.rbegin(), str.rend(), ostream_iterator<char>(cout));
        cout << a << "\n";
    }
    
    return 0;
}