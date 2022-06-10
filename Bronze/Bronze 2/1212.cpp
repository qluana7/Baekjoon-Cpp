#include <iostream>
#include <string>

using namespace std;

int main() {
    string str; cin >> str;
    
    if (str == "0") { cout << 0; return 0; }
    
    int len = str.length();
    for (int i = 0; i < len; i++) {
        int c = str[i] - 48;
        string tmp = "000";
        
        for (int j = 0; j < 3; j++) {
            tmp[2 - j] = (c % 2) + 48;
            c /= 2;
        }
        
        if (i == 0) {
            bool b = false;
            
            for (const char& cp : tmp) {
                if (cp == '1') b = true;
                
                if (!b && cp == '0') continue;
                
                cout << cp;
            }
        } else cout << tmp;
    }
    
    return 0;
}