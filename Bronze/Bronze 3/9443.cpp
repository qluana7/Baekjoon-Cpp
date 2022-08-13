#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<char> ch(n);
    
    for (char& c : ch) {
        string str; cin >> str; c = str[0];
    }
    
    sort(ch.begin(), ch.end());
    
    int p = 1;
    if (ch[0] != 'A') { cout << 0; return 0; }
    for (char c : ch) {
        if (c == 'A' + p - 1) continue;
        else if (c == 'A' + p) p++;
        else break;
    }
    
    cout << p;
    
    return 0;
}