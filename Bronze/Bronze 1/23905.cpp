#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> init(vector<int> str) {
    vector<int> res(str.size(), 0);
    
    for (int i = 1, j = 0; i < res.size(); i++) {
        while (j > 0 && str[i] != str[j]) j = res[j - 1];
        
        if (str[i] == str[j]) res[i] = ++j;
    }
    
    return res;
}

vector<int> kmp(vector<int> src, vector<int> pat) {
    vector<int> out;
    
    vector<int> bd = init(pat);
    
    for (int i = 0, j = 0; i < src.size(); i++) {
        while (j > 0 && src[i] != pat[j]) j = bd[j - 1];
        
        if (src[i] == pat[j]) {
            if (j == pat.size() - 1) {
                out.push_back(i - pat.size() + 1);
                j = bd[j];
            } else j++;
        }
    }
    
    return out;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int rp; cin >> rp;
    
    for (int i = 1; i <= rp; i++) {
        int n, m; cin >> n >> m;
        vector<int> vs(n), vp;
        for (int i = m; i > 0; i--) vp.push_back(i);
        for (int& x : vs) cin >> x;
        
        cout << "Case #" << i << ": " << kmp(vs, vp).size() << "\n";
    }
    
    return 0;
}