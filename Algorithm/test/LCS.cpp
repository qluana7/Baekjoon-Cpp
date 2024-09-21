// TEST

#include <iostream>

#include "../LCS"

int main() {
    string s1, s2; cin >> s1 >> s2;
    cout << LCS_LEN(" " + s1, " " + s2);
    cout << LCS_REV(" " + s1, " " + s2);
    
    return 0;
}