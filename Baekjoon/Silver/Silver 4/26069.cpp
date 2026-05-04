#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, bool> m;
    m["ChongChong"] = 1;
    
    int n; cin >> n;
    
    while (n --> 0) {
        string str1, str2;
        cin >> str1 >> str2;
        
        bool b = m[str1] | m[str2];
        m[str1] = b; m[str2] = b;
    }
    
    int cnt = 0;
    for (const auto& [_, b] : m) cnt += b;
    
    cout << cnt;
    
    return 0;
}