// TEST

#include <iostream>

#include "../KMP"

int main() {
    /* INPUT
     *
     * Hello, World! Hello, C++! Hello Everyone!
     * Hello
     */
    
    string str, pat;
    getline(cin, str); getline(cin, pat);
    
    auto v = kmp(str, pat);
    
    for (int x : v) cout << x << " ";
    
    return 0;
}