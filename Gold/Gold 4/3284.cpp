#include <iostream>
#include <string>

using namespace std;

string::iterator iter;

int get() {
    int tot = 0, prev = 0;
    for (;*iter != ')'; iter++) {
        switch (*iter) {
            case 'H': tot += prev; prev = 1;  break;
            case 'C': tot += prev; prev = 12; break;
            case 'O': tot += prev; prev = 16; break;
            case '(': tot += prev; iter++; prev = get(); break;
            default: tot += prev * (*iter - '0'); prev = 0; break;
        }
    }
    return tot + prev;
}

int main() {
    string str; cin >> str;
    int tot = 0, prev = 0;
    
    iter = str.begin();
    
    for (;iter != str.end(); iter++) {
        switch (*iter) {
            case 'H': tot += prev; prev = 1;  break;
            case 'C': tot += prev; prev = 12; break;
            case 'O': tot += prev; prev = 16; break;
            case '(': tot += prev; iter++; prev = get(); break;
            default: tot += prev * (*iter - '0'); prev = 0; break;
        }
    }
    
    cout << tot + prev;
    
    return 0;
}