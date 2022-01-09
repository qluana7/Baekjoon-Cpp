#include <iostream>

using namespace std;

int main() {
    int word[26] = { 0, };
    string str;
    
    cin >> str;
    
    for (char& c : str) {
        word[c >= 97 ? c - 97 : c - 65]++;
    }
    
    int max = 0, er = 0;
    
    for (int i = 1; i < 26; i++) {
        if (word[i] == 0) continue;
        
        if (word[i] == word[max]) er = 1;
        
        if (word[max] < word[i]) { max = i; er = 0; }
    }
    
    cout << (!er ? (char)(max + 65) : '?');
    
    return 0;
}