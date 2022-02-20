#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int c; cin >> c;
    vector<string> v;
    
    for (int i = 0; i < c; i++) {
        string str; cin >> str;
        v.push_back(str);
    }
    
    int len = v[0].length();
    
    for (int i = 0; i < len; i++) {
        bool b = false; char ch = v[0][i];
        for (int k = 1; k < c; k++) {
            b |= v[k][i] != ch;
            
            if (b) break;
        }
        
        cout << (b ? '?' : ch);
    }
    
    return 0;
}