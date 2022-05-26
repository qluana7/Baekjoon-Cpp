#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> dict;

int get(string::iterator& iter) {
    int tot = 0, prev = 0; string c;
    
    for (; *iter != ')'; iter++) {
        c = "";
        char p = *iter;
        
        if ('0' <= p && p <= '9') {
            int n = p - '0';
            if ('0' <= *(iter + 1) && *(iter + 1) <= '9') { n *= 10; n += *++iter - '0'; }
            tot += prev * n; prev = 0;
        }
        else if (p == '(') {
                tot += prev; iter++;
                int tmp = get(iter);
                
                if (tmp == -1) return -1;
                prev = tmp;
            }
        else {
            c += *iter;
            char np = *(iter + 1);
            
            if ('a' <= np && np <= 'z') c += *++iter;
            
            tot += prev;
            
            if (dict.count(c) == 0) return -1;
            prev = dict[c];
        }
    }
    
    return tot + prev;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    for (
        string str; cin >> str,
        str != "END_OF_FIRST_PART";
        cin >> dict[str]
    );
    
    for (string str; cin >> str, str != "0";) {
        auto iter = str.begin();
        int tot = 0, prev = 0;
        string c; bool uk = false;
        
        for (; iter != str.end(); iter++) {
            c = "";
            char p = *iter;
            
            if ('0' <= p && p <= '9') {
                int n = p - '0';
                if ('0' <= *(iter + 1) && *(iter + 1) <= '9') { n *= 10; n += *++iter - '0'; }
                tot += prev * n; prev = 0;
            }
            else if (p == '(') {
                tot += prev; iter++;
                int tmp = get(iter);
                
                if (tmp == -1) { uk = true; break; }
                prev = tmp;
            }
            else {
                c += *iter;
                char np = *(iter + 1);
                
                if ('a' <= np && np <= 'z') c += *++iter;
                
                tot += prev;
                
                if (dict.count(c) == 0) { uk = true; break; }
                prev = dict[c];
            }
        }
        
        if (uk) cout << "UNKNOWN\n";
        else cout << tot + prev << "\n";
    }
    
    return 0;
}