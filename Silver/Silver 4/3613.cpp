#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, tmp; cin >> str;
    
    // c++ = 1 | java = 2
    int type = 0;
    bool b = false;
    
    if(str[0] < 96) { cout << "Error!"; return 0; }
    
    for (const char& ch : str) {
        if (ch < 95) {
            if (type == 1) { cout << "Error!"; return 0; }
            type = 2;
            tmp += (string)"_" + (char)(ch + 32);
        } else if (ch > 95) {
            if (b) { b = false; tmp += (char)(ch - 32); }
            else tmp += ch;
        }
        else {
            if (b) { cout << "Error!"; return 0; }
            if (type == 2) { cout << "Error!"; return 0; }
            type = 1; b = true;
        }
    }
    
    if (b) { cout << "Error!"; return 0; }
    
    cout << tmp;
    
    return 0;
}