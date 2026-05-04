#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int count = 0;
    
    getline(cin, str);
    
    if (str.empty() || str == " ") { cout << 0; return 0; }
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') continue;
        
        if (i == 0 || i == str.length() - 1) continue;
        
        count++;
    }
    
    cout << count + 1;
    
    return 0;
}