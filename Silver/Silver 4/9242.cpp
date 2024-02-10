#include <iostream>
#include <vector>

using namespace std;

vector<string> ans {
    "**** ** ** ****",
    "  *  *  *  *  *",
    "***  *****  ***",
    "***  ****  ****",
    "* ** ****  *  *",
    "****  ***  ****",
    "****  **** ****",
    "***  *  *  *  *",
    "**** ***** ****",
    "**** ****  ****"
};

int main() {
    cin.tie(nullptr);
    vector<string> v;
    
    string str(3, '\0');
    while (~scanf("%c", &str[0])) {
        str[1] = getchar();
        if (str[1] == '\n') { str[1] = ' '; str[2] = ' '; v.push_back(str); continue; }
        str[2] = getchar();
        if (str[2] == '\n') { str[2] = ' '; }
        v.push_back(str);
        getchar();
    }
    
    int x = v.size() / 5, sum = 0;
    
    for (int i = 0; i < x; i++) {
        std::string tmp;
        
        for (int j = 0; j < 5; j++)
            tmp += v[i + j * x];
        
        bool flag = false;
        for (int j = 0; j < 10; j++) {
            flag |= ans[j] == tmp;
            
            if (ans[j] == tmp) sum = sum * 10 + j;
        }
        
        if (!flag) { cout << "BOOM!!"; return 0; }
    }
    
    cout << (sum % 6 == 0 ? "BEER!!" : "BOOM!!");
}