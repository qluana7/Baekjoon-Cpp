#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2) {
    int a = s1.size(), b = s2.size();
    
    if (a != b) return a < b;
    
    return s1 < s2;
}

int main() {
    vector<string> v;
    
    int n; cin >> n;
    
    for (; n--; ) {
        string x; cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    string prev = "";
    
    for (string& s : v) {
        if (prev == s) continue;
        cout << s << "\n";
        prev = s;
    }
    
    return 0;
}