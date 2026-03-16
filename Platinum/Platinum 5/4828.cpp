#include <iostream>
#include <regex>
#include <stack>
#include <string>

using namespace std;

inline void clear(stack<string>& s) { while (!s.empty()) s.pop(); }

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    string str;
    stack<string> tags;
    bool valid = true;
    
    for (;getline(cin, str); clear(tags), valid = true) {
        
        for (auto iter = str.begin(), ed = str.end(); iter != ed; iter++) {
            switch (*iter) {
                case '<': {
                    bool pop = *++iter == '/';
                    if (pop) { if (tags.empty()) { valid = false; break; } iter++; }
                    bool np = false;
                    string tag;
                    
                    for (;*iter != '>' && iter != str.end(); iter++) {
                        char c = *iter;
                        if (c == '<' || c == '&') { valid = false; break; }
                        if (c == '/') {
                            if (*++iter == '>') np = true;
                            else valid = false;
                            break;
                        }
                        if (!(('0' <= c && c <= '9') || ('a' <= c && c <= 'z'))) { valid = false; break; }
                        tag += c;
                    }
                    
                    if (!valid || np) break;
                    if (tag == "" || iter == str.end()) { valid = false; break; }
                    
                    if (pop) {
                        if (tags.top() != tag) { valid = false; break; }
                        tags.pop();
                    } else tags.push(tag);
                    break;
                }
                case '>': valid = false; break;
                case '&': {
                    switch (*++iter) {
                        case 'l': case 'g':
                            if (*++iter != 't') valid = false;
                            break;
                        case 'a':
                            if (*++iter != 'm') { valid = false; break; }
                            if (*++iter != 'p') { valid = false; break; }
                            break;
                        case 'x':
                            int c = 0;
                            for(iter++; *iter != ';' && iter != str.end(); c++, iter++) {
                                char x = *iter;
                                if (!(('0' <= x && x <= '9') || ('A' <= x && x <= 'F') || ('a' <= x && x <= 'f'))) { valid = false; break; }
                            }
                            
                            if (!valid) break;
                            if (c == 0 || c % 2 == 1) { valid = false; break; }
                            iter--;
                    }
                    
                    if (!valid) break;
                    if (*++iter != ';') { valid = false; break; }
                    
                    if (iter == str.end()) { valid = false; break; }
                }
            }
            
            if (!valid) break;
        }
        
        cout << (valid && tags.empty() ? "valid\n" : "invalid\n");
    }
    
    return 0;
}