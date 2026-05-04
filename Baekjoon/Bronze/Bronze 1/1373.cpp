#include <iostream>
#include <vector>
#include <string>

#define long unsigned long

using namespace std;

int main() {
    string str; cin >> str;
    
    long base = 1;
    bool rp = true;
    vector<int> v;
    
    if (str.size() == 1 && str[0] == '0') {
        cout << 0; return 0;
    }
    
    for (auto fst = str.rbegin(), lst = str.rend(); rp; fst += 3) {
        int b = 1;
        int n = 0;
        for (int i = 0; i < 3; i++, b *= 2) {
            if ((fst + i) == lst) { rp = false; break; }
            n += (*(fst + i) == '1') * b;
        }
        
        if (!rp && n == 0) continue;
        v.push_back(n);
    }
    
    for (auto fst = v.rbegin(), lst = v.rend(); fst != lst; fst++) cout << *fst;
    
    return 0;
}