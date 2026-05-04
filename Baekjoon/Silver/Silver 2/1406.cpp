#include <iostream>
#include <list>
#include <string>
#include <iterator>

using namespace std;

int main() {
    string str; int n; cin >> str >> n;
    list<char> buf(str.begin(), str.end());
    
    auto cur = buf.end();
    
    for (;n--;) {
        char c; cin >> c;
        
        switch (c) {
            case 'L': if (cur != buf.begin()) cur--; break;
            case 'D': if (cur != buf.end())   cur++; break;
            case 'B':
                if (cur != buf.begin()) {
                    auto tmp = --cur; --cur;
                    buf.erase(tmp);
                    cur++;
                } break;
            case 'P':
                char p; cin >> p;
                buf.insert(cur, p);
                break;
        }
    }
    
    copy(buf.begin(), buf.end(), ostream_iterator<char>(cout));
    
    return 0;
}