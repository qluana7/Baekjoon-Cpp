#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    for(int n = 1;;n++) {
        cin >> s1 >> s2;
        if (s1 == "END") return 0;
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        cout << "Case " << n << ": " << (s1 == s2 ? "same" : "different") << "\n";
    }
}