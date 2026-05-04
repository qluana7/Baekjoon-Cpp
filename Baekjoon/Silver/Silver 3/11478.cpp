#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    string s; cin >> s;
    unordered_set<string> c;
    
    for (int i = 0; i < s.size(); i++) {
        string t; t += s[i]; c.insert(t);
        for (int j = i + 1; j < s.size(); j++) {
            t += s[j]; c.insert(t);
        }
    }
    
    cout << c.size();
    
    return 0;
}