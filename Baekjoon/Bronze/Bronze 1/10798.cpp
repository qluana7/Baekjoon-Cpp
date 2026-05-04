#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int m = 0;
    vector<string> vs(5);
    for (string& s : vs) { cin >> s; m = max<int>(m, s.size()); }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 5; j++) {
            if (i >= vs[j].size()) continue;
            
            cout << vs[j][i];
        }
    }
    
    return 0;
}