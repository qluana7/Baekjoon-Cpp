#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <atcoder/all>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

string transform(const string& s) {
    string output; output.reserve(s.size());
    int stack = 0;
    
    bool flag = false;
    
    for (int i = 0; i < s.size(); i++) {
        if (flag) {
            while (i < s.size() && stack > 0 && s[i] == ')')
                --stack, ++i;
            
            i--;
            
            output += string(stack, '(') + "xx";
            stack = 0;
            
            flag = false;
        } else {
            if (s[i] != '(') {
                output += s[i];
                stack = 0;
            }
            else {
                while (i < s.size() && s[i] == '(')
                    ++stack, ++i;
                
                if (i == s.size()) {
                    output += string(stack, '(');
                    break;
                }
                    
                if (i + 1 < s.size() && (s[i] == 'x' && s[i + 1] == 'x'))
                    flag = true, ++i;
                else {
                    output += string(stack, '(') + s[i];
                    stack = 0;
                }
            }
        }
    }
    
    if (flag)
        output += string(stack, '(') + "xx";
    
    return output;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    
    while (n --> 0) {
        string a, b; cin >> a >> b;
        
        cout << (transform(a) == transform(b) ? "Yes" : "No") << "\n";
    }
}