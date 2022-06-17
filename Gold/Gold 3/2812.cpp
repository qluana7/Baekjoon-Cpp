#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, z; cin >> n >> m; z = n - m;
    
    vector<int> s;
    string str; cin >> str;
    s.push_back(str[0] - 48);
    
    for (int i = 1; i < str.length(); i++) {
        int p = str[i] - 48;
        while (!s.empty() && s.back() < p && m != 0) { s.pop_back(); m--; }
        s.push_back(p);
    }
    
    for(int i = 0; i < z; i++) cout << s[i];
    
    return 0;
}