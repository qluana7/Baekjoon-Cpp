#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string sa, sb; cin >> sa >> sb;
    int la = sa.length(), lb = sb.length();
    int m = max(la, lb);
    vector<int> a(m, 0), b(m, 0);
    
    for (int i = 0; i < la; i++) a[m - i - 1] = sa[la - i - 1] - 48;
    for (int i = 0; i < lb; i++) b[m - i - 1] = sb[lb - i - 1] - 48;
    
    for (int i = 0; i < m; i++) a[i] += b[i];
    
    for (int i = m; i > 1; i--) { a[i - 2] += a[i - 1] / 10; a[i - 1] %= 10; }
    
    for (int& n : a) cout << n;
    
    return 0;
}