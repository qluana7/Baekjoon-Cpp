#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    unordered_set<string> set;
    
    int n, m, t = 0; cin >> n >> m;
    
    for (;n--;) {
        string str; cin >> str;
        set.insert(str);
    }
    
    for (;m--;) {
        string str; cin >> str;
        t += set.count(str);
    }
    
    cout << t;
    
    return 0;
}