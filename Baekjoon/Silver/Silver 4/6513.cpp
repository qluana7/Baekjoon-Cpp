#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    unordered_map<string, string> um;
    int n, m; cin >> n >> m;
    
    for (;n--;) {
        string s1, s2; cin >> s1 >> s2;
        um[s1] = s2;
    }
    
    for (;m--;) {
        string tmp; cin >> tmp;
        
        if (um.count(tmp)) cout << um[tmp] << "\n";
        else if (tmp.back() == 'y') {
            char c = tmp[tmp.size() - 2];
            switch (c) {
                case 'a': case 'e': case 'i':
                case 'o': case 'u':
                    cout << tmp << "s\n";
                    break;
                default:
                    cout << tmp.substr(0, tmp.size() - 1) << "ies\n";
                    break;
            }
        }
        else {
            switch (tmp.back()) {
            case 'o': case 's': case 'x':
                cout << tmp << "es\n"; continue;
            case 'h': {
                char c = tmp[tmp.size() - 2];
                if (c == 'c' || c == 's')
                    cout << tmp << "es\n"; continue;
            }
            default: break;
            }
            
            cout << tmp << "s\n";
        }
    }
    
    return 0;
}