#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> init(string str) {
    vector<int> res(str.size(), 0);
    
    for (int i = 1, j = 0; i < res.size(); i++) {
        while (j > 0 && str[i] != str[j]) j = res[j - 1];
        
        if (str[i] == str[j]) res[i] = ++j;
    }
    
    return res;
}

int main() {
    string str; getline(cin, str);
    
    int mx = 0;
    
    for (int i = 0; i < str.size(); i++) {
        auto v = init(str.substr(i));
        for (int x : v) mx = max(mx, x);
    }
    
    cout << mx;
    
    return 0;
}