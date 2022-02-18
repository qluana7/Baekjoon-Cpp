#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<string> exts;

struct str {
    string name, ext;
};

bool cmp(str& s1, str& s2) {
    if (s1.name != s2.name) return s1.name < s2.name;
    
    bool
        b1 = exts.find(s1.ext) != exts.end(),
        b2 = exts.find(s2.ext) != exts.end();
    
    if (b1 ^ b2) return b1 ? true : false;
    else return s1.ext < s2.ext;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    vector<str> inp;
    
    int n, m; cin >> n >> m;
    
    for (; n--; ) {
        string name, ext, tmp;
        cin >> tmp;
        
        bool b = false;
        int len = tmp.length();
        for (int i = 0; i < len; i++) {
            if (tmp[i] == '.') { b = true; continue; }
            
            if (b) ext += tmp[i];
            else name += tmp[i];
        }
        
        inp.push_back({name, ext});
    }
    
    for (; m--; ) {
        string st; cin >> st;
        exts.insert(st);
    }
    
    sort(inp.begin(), inp.end(), cmp);
    
    for (const str& s : inp)
        cout << s.name << "." << s.ext << "\n";
    
    return 0;
}