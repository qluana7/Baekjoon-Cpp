#include <iostream>
#include <vector>

using namespace std;

int zeroInd(string s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == '1') return i;
    }
    return len - 1;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    for (; n--; ) {
        string s1, s2;
        cin >> s1 >> s2;
        
        s1 = s1.substr(zeroInd(s1));
        s2 = s2.substr(zeroInd(s2));
        
        int n1 = s1.length(), n2 = s2.length();
        int m = max(n1, n2);
        
        vector<int> v1(m, 0), v2(m, 0);
        
        for (int i = 0; i < n1; i++) v1[m - i - 1] = s1[n1 - i - 1] - 48;
        for (int i = 0; i < n2; i++) v2[m - i - 1] = s2[n2 - i - 1] - 48;
        
        for (int i = m - 1; i > 0; i--) {
            v1[i] += v2[i];
            v1[i - 1] += v1[i] / 2;
            v1[i] %= 2;
        }
        
        v1[0] += v2[0];
        v1[0] = v1[0] / 2 * 10 + v1[0] % 2;
        
        for (const int& i : v1) cout << i;
        cout << "\n";
    }
    
    return 0;
}