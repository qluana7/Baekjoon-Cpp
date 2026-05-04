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

vector<int> kmp(string src, string pat) {
    vector<int> out;
    
    vector<int> bd = init(pat);
    
    for (int i = 0, j = 0; i < src.size(); i++) {
        while (j > 0 && src[i] != pat[j]) j = bd[j - 1];
        
        if (src[i] == pat[j]) {
            if (j == pat.size() - 1) {
                out.push_back(i - pat.size() + 1);
                j = bd[j];
            } else j++;
        }
    }
    
    return out;
}

int main() {
    
    string str, pat;
    getline(cin, str); getline(cin, pat);
    
    auto v = kmp(str, pat);
    
    cout << v.size() << "\n";
    for (int x : v) cout << x + 1 << " ";
    
    return 0;
}