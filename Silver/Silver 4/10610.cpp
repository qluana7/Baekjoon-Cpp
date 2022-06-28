#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str; cin >> str;
    int sum = 0; bool b = false;
    
    for (const char& ch : str) { sum += (ch - 48); b |= ch == 48; }
    if (sum % 3 || !b) { cout << -1; return 0; }
    
    sort(str.begin(), str.end(), greater<int>());
    
    cout << str;
    
    return 0;
}