#include <iostream>
#include <vector>
#include <cmath>

#define vint vector<int>

using namespace std;

void add(vint a, vint b, int m, bool positive);
void sub(vint a, vint b, int m, bool positive);
int strcmp(string s1, string s2);

int main() {
    string sa, sb; cin >> sa >> sb;
    bool ap = sa[0] != '-', bp = sb[0] != '-';
    
    if (!ap) sa = sa.substr(1);
    if (!bp) sb = sb.substr(1);
    
    int la = sa.length(), lb = sb.length();
    int m = max(la, lb);
    vint a(m, 0), b(m, 0);
    
    for (int i = 0; i < la; i++) a[m - i - 1] = sa[la - i - 1] - 48;
    for (int i = 0; i < lb; i++) b[m - i - 1] = sb[lb - i - 1] - 48;
    
    void (*fp)(vint, vint, int, bool) = ap == bp ? add : sub;
    int cmp = strcmp(sa, sb);
    
    if (cmp == 0 && ap != bp) { cout << 0; return 0; }
    
    bool pos = !ap && !bp ? false :
               bp && ap ? true :
               cmp == 1 && bp ? false :
               cmp == -1 && ap ? false : true;
    
    if (cmp == 1) fp(a, b, m, pos);
    else fp(b, a, m, pos);
    
    return 0;
}

// 1 = left is big, 0 = same, -1 = right is big
int strcmp(string s1, string s2) {
    if (s1.length() != s2.length()) return s1.length() > s2.length() ? 1 : -1;
    
    int len = s1.length();
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) return s1[i] > s2[i] ? 1 : -1;
    }
    
    return 0;
}

void add(vint a, vint b, int m, bool positive) {
    for (int i = 0; i < m; i++) a[i] += b[i];
    
    for (int i = m; i > 1; i--) { a[i - 2] += a[i - 1] / 10; a[i - 1] %= 10; }
    
    if (!positive) cout << "-";
    
    for (int& n : a) cout << n;
}

void sub(vint a, vint b, int m, bool positive) {
    for (int i = 0; i < m; i++) a[i] -= b[i];
    
    for (int i = m; i > 1; i--) {
        a[i - 2] -= a[i - 1] < -10 ? 2 : a[i - 1] < 0 ? 1 : 0;
        while (a[i - 1] < 0) a[i - 1] += 10;
    }
    
    if (!positive) cout << "-";
    bool zero = true;
    
    for (int& n : a) {
        if (n == 0 && zero) continue;
        zero = false;
        
        cout << n;
    }
}