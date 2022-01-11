#include <iostream>

using namespace std;

int main() {
    string s1, s2; cin >> s1 >> s2;
    s1 = " " + s1; s2 = " " + s2;
    
    auto table = new string [s1.length()][41];
    
    for (int i = 1; i < s1.length(); i++) {
        for (int j = 1; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                table[i][j] = table[i - 1][j - 1] + s1[i];
            }
            else {
                string a = table[i - 1][j], b = table[i][j - 1];
                table[i][j] = a.length() > b.length() ? a : b;
            }
        }
    }
    
    cout << table[s1.length() - 1][s2.length() - 1];
    
    return 0;
}