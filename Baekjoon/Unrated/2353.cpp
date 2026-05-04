#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string str; cin >> str;
    int idx = 0;
    int flag = 0;
    
    unordered_set<char> _initial {
        'r', 'R', 's', 'e', 'E', 'f', 'a', 'q', 'Q', 't', 
        'T', 'd', 'w', 'W', 'c', 'z', 'x', 'v', 'g'
    },
    _neutral {
        'k', 'o', 'i', 'O', 'j', 'p', 'u', 'P', 'h',
        'y', 'n', 'b', 'm', 'l'
    },
    _final {
        'r', 'R', 's', 'e', 'f',
        'a', 'q', 't', 'T', 'd', 'w',
        'c', 'z', 'x', 'v', 'g'
    };
    
    for (; idx < str.size(); idx++) {
        char c = str[idx];
        
        switch (flag) {
        case 0: if (!_initial.count(c)) flag = -1; else flag = 1; break;
        case 1:
            if (!_neutral.count(c)) flag = -1;
            else {
                char nx = str[idx + 1];
                if (
                    (c == 'h' && (nx == 'k' || nx == 'o' || nx == 'l')) ||
                    (c == 'n' && (nx == 'j' || nx == 'p' || nx == 'l')) ||
                    (c == 'm' && nx == 'l')
                    ) idx++;
                
                flag = 3;
            } break;
        case 3: 
            if (!_final.count(c)) {
                if (_initial.count(c)) flag = 1;
                else flag = -1;
            }
            else {
                char nx = str[idx + 1];
                
                if (_neutral.count(nx)) { flag = 1; continue; }
                else if (
                    (c == 'r' && nx == 't') ||
                    (c == 's' && (nx == 'w' || nx == 'g')) ||
                    (c == 'f' && (nx == 'r' || nx == 'a' || nx == 'q' ||
                                  nx == 't' || nx == 'x' || nx == 'v' || nx == 'g')) ||
                    (c == 'q' && nx == 't')
                    ) idx++;
                
                flag = 7;
            } break;
        case 7: flag = 0; idx--; continue;
        default: cout << idx; return 0;
        }
    }
    
    if (idx == str.size()) cout << 0;
    
    return 0;
}